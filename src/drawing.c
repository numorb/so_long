/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 00:41:21 by blnunez-          #+#    #+#             */
/*   Updated: 2024/12/12 01:00:20 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_pixel(char *img, t_size size, t_position pos, int color)
{
	if (pos.x < 0 || pos.y < 0 || pos.x >= size.width || pos.y >= size.height)
		return ;
	((int *)img)[pos.y * size.width + pos.x] = color;
}

void	obj2screen(t_game *game, t_object *object, int idx, t_position pos_img)
{
	t_position	pos_obj;
	t_position	pos;
	int			offset;
	int			color;

	pos_obj.y = 0;
	while (pos_obj.y < object->size.height)
	{
		pos_obj.x = 0;
		while (pos_obj.x < object->size.width)
		{
			pos.x = pos_img.x * TILE + pos_obj.x;
			pos.y = pos_img.y * TILE + pos_obj.y;
			offset = pos_obj.y * object->img[idx]->size_line + pos_obj.x * 4;
			if ((object->img[idx]->buffer[offset + 3] & 0xFF))
			{
				color = (object->img[idx]->buffer[offset + 2] & 0xFF) | \
					((object->img[idx]->buffer[offset + 1] & 0xFF) << 8) | \
					((object->img[idx]->buffer[offset + 0] & 0xFF) << 16);
				put_pixel(game->screen.buffer, game->screen_size, pos, color);
			}
			pos_obj.x++;
		}
		pos_obj.y++;
	}
}

void	draw_background(t_game *game)
{
	t_position	pixel_position;

	pixel_position.y = 0;
	while (pixel_position.y < game->screen_size.height)
	{
		pixel_position.x = 0;
		while (pixel_position.x < game->screen_size.width)
		{
			put_pixel(game->screen.buffer, game->screen_size, pixel_position, \
				BACKGROUND);
			++pixel_position.x;
		}
		++pixel_position.y;
	}
}

void	draw_info(t_game *game)
{
	char	*temp;
	char	*info;

	temp = ft_itoa(game->steps);
	info = ft_strjoin("Steps: ", temp);
	free(temp);
	mlx_string_put(game->mlx, game->win, 5, game->screen_size.height - 20, \
		0xFFFFFFFF, info);
	free(info);
	temp = ft_itoa(game->character.collectables.count - game->collected);
	info = ft_strjoin("Peas left: ", temp);
	free(temp);
	mlx_string_put(game->mlx, game->win, 5, game->screen_size.height - 5, \
		0xFFFFFFFF, info);
	free(info);
	if (game->game_over != 0)
	{
		if (game->game_over < 0)
			mlx_string_put(game->mlx, game->win, game->screen_size.width / 2 \
			- 100, 20, 0xFFFFFFFF, "YOU CAN'T WIN THEM ALL!! :((");
		else
			mlx_string_put(game->mlx, game->win, game->screen_size.width / 2 \
			- 100, 20, 0xFFFFFFFF, "UNBELIEVABLE, YOU WON!!!");
	}
}
