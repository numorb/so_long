/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 01:57:45 by blnunez-          #+#    #+#             */
/*   Updated: 2024/12/12 01:58:10 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_over(t_game *game, int frame)
{
	if (game->game_over == 1 || game->game_over == -1)
		frame = 0;
	if (game->game_over < 0)
	{
		game->game_over--;
		obj2screen(game, &game->character.player, 1, \
			game->character.player.pos[0]);
		game->character.player.img[1]->buffer = ((char *) \
			pacman_dead_data[(frame / FRATE) % PACMAN_DEAD_FRAME_COUNT]);
		if (frame / FRATE < PACMAN_DEAD_FRAME_COUNT - 1)
			frame++;
	}
	else
	{
		game->game_over++;
		frame++;
	}
	if (game->game_over < -10 * FRATE || game->game_over > 10 * FRATE)
		close_handler(game);
}

int	game_loop(t_game *game)
{
	static int	frame;

	draw_background(game);
	draw_walls(game);
	draw_exit(game, frame);
	draw_collectibles(game, frame);
	if (game->game_over == 0)
	{
		obj2screen(game, &game->character.player, 0, \
			game->character.player.pos[0]);
		game->character.player.img[0]->buffer = ((char *) \
			pacman_data[(frame++ / FRATE) % PACMAN_FRAME_COUNT]);
	}
	draw_enemies(game, frame, game->game_over);
	if (game->game_over != 0)
		game_over(game, frame);
	mlx_put_image_to_window(game->mlx, game->win, game->screen.img, 0, 0);
	draw_info(game);
	return (0);
}

int	init_game(t_game *game, char **argv)
{
	t_size	max_size;

	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error\nThe game couldn't be initialised.\n");
		return (1);
	}
	mlx_get_screen_size(game->mlx, &max_size.width, &max_size.height);
	if (maps(argv[1], &game->map))
	{
		ft_printf("Error\nWrong map.\n");
		return (1);
	}
	if (game->map.size.width * TILE > max_size.width || \
	game->map.size.height * TILE > max_size.height)
		return (ft_printf("Map is too big. Go smaller or go home!"), 1);
	game->screen_size.width = game->map.size.width * TILE;
	game->screen_size.height = game->map.size.height * TILE;
	game->win = mlx_new_window(game->mlx, game->screen_size.width + 1, \
		game->screen_size.height + 1, "Lets the game comence!");
	if (!game->win)
		return (ft_printf("Error\nFailed creating window.\n"), 1);
	return (0);
}
