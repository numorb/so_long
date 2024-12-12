/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_objects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 00:57:14 by blnunez-          #+#    #+#             */
/*   Updated: 2024/12/12 01:09:07 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_walls(t_game *game)
{
	t_position	tile;
	t_position	tile_p;
	t_position	sp;

	tile.y = -1;
	while (++tile.y < game->map.size.height)
	{
		tile.x = -1;
		while (++tile.x < game->map.size.width)
		{
			if (game->map.mapping[tile.y][tile.x] != '1')
				continue ;
			tile_p.y = -1;
			while (++tile_p.y < TILE)
			{
				tile_p.x = -1;
				while (++tile_p.x < TILE)
				{
					sp.x = tile.x * TILE + tile_p.x;
					sp.y = tile.y * TILE + tile_p.y;
					put_pixel(game->screen.buffer, game->screen_size, sp, WALL);
				}
			}
		}
	}
}

void	draw_enemies(t_game *game, int frame, int dead)
{
	t_object *const	e = &game->character.enemies;
	int				i;
	int				idx;

	i = -1;
	while (++i < e->count)
	{
		if (dead <= 0)
			idx = i % 4;
		else
			idx = 4;
		if (idx == 0)
			e->img[idx]->buffer = (char *)ghost_data[(frame / FRATE) % GFC];
		else if (idx == 1)
			e->img[idx]->buffer = (char *)ghost2_data[(frame / FRATE) % G2FC];
		else if (idx == 2)
			e->img[idx]->buffer = (char *)ghost3_data[(frame / FRATE) % G3FC];
		else if (idx == 3)
			e->img[idx]->buffer = (char *)ghost4_data[(frame / FRATE) % G4FC];
		else if (idx == 4)
			e->img[idx]->buffer = (char *) \
				ghost_dead_data[(frame / FRATE) % GDFC];
		obj2screen(game, &game->character.enemies, idx, e->pos[i]);
	}
}

void	draw_exit(t_game *game, int frame)
{
	int	i;

	i = 0;
	if (game->collected == game->character.collectables.count)
		i = 1;
	obj2screen(game, &game->character.exit, i, \
		game->character.exit.pos[0]);
	game->character.exit.img[0]->buffer = ((char *) \
		forbidden_exit_data[(frame++ / FRATE) % FORBIDDEN_EXIT_FRAME_COUNT]);
	game->character.exit.img[1]->buffer = ((char *) \
		exit42_data[(frame++ / FRATE) % EXIT42_FRAME_COUNT]);
}

void	draw_collectibles(t_game *game, int frame)
{
	int	i;

	i = 0;
	while (i < game->character.collectables.count)
	{
		if (game->character.collectables.pos[i].x > 0)
			obj2screen(game, &game->character.collectables, 0, \
				game->character.collectables.pos[i]);
		i++;
	}
	game->character.collectables.img[0]->buffer = \
		((char *)money_data[(frame++ / FRATE) % MONEY_FRAME_COUNT]);
}
