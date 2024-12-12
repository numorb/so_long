/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 00:50:49 by blnunez-          #+#    #+#             */
/*   Updated: 2024/12/12 00:51:01 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	build_image(t_image *image, void *mlx, t_size size)
{
	image->img = mlx_new_image(mlx, size.width, size.height);
	image->buffer = mlx_get_data_addr(image->img, &image->bpp, \
		&image->size_line, &image->endian);
}

int	create_img(t_game *game, t_object *object, char *data, int idx)
{
	object->img[idx] = malloc(sizeof(t_image));
	if (!object->img[idx])
		return (1);
	object->size.height = TILE;
	object->size.width = TILE;
	build_image(object->img[idx], game->mlx, object->size);
	object->img[idx]->buffer = data;
	return (0);
}

int	sprites(t_game *game)
{
	t_object_type *const	c = &game->character;

	if (create_img(game, &c->player, (char *)pacman_data, 0) || \
		create_img(game, &c->player, (char *)pacman_dead_data, 1) || \
		create_img(game, &c->enemies, (char *)ghost_data, 0) || \
		create_img(game, &c->enemies, (char *)ghost2_data, 1) || \
		create_img(game, &c->enemies, (char *)ghost3_data, 2) || \
		create_img(game, &c->enemies, (char *)ghost4_data, 3) || \
		create_img(game, &c->enemies, (char *)ghost_dead_data, 4) || \
		create_img(game, &c->exit, (char *)forbidden_exit_data, 0) || \
		create_img(game, &c->exit, (char *)exit42_data, 1) || \
		create_img(game, &c->collectables, (char *)money_data, 0))
		return (1);
	return (0);
}
