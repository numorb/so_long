/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 01:59:35 by blnunez-          #+#    #+#             */
/*   Updated: 2024/12/12 01:59:59 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pos_handler(t_object *obj, int idx, t_position pos)
{
	obj->pos[idx].x = pos.x;
	obj->pos[idx].y = pos.y;
}

void	count_inc(t_object *obj)
{
	obj->count++;
}

void	init_object_handlers(t_game *game)
{
	t_object_handler		*h;
	t_object_type *const	c = &game->character;

	game->num_handlers = 5;
	game->object_handlers = malloc(sizeof(t_object_handler) * \
		game->num_handlers);
	if (!game->object_handlers)
	{
		ft_printf("Error1\n");
		exit(1);
	}
	h = game->object_handlers;
	ft_memset(&game->character, 0, sizeof(t_object_type));
	h[0] = (t_object_handler){'P', &c->player, &pos_handler, &count_inc};
	h[1] = (t_object_handler){'E', &c->exit, &pos_handler, &count_inc};
	h[2] = (t_object_handler){'C', &c->collectables, &pos_handler, &count_inc};
	h[3] = (t_object_handler){'1', &c->wall, &pos_handler, &count_inc};
	h[4] = (t_object_handler){'X', &c->enemies, &pos_handler, &count_inc};
	objects_count(game);
	h[0].object->pos = malloc(sizeof(t_position));
	h[1].object->pos = malloc(sizeof(t_position));
	h[2].object->pos = malloc(sizeof(t_position) * h[2].object->count);
	h[3].object->pos = malloc(sizeof(t_position) * h[3].object->count);
	h[4].object->pos = malloc(sizeof(t_position) * h[4].object->count);
	objects_positions(game);
}

void	free_object_handlers(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->num_handlers)
		free(game->object_handlers[i++].object->pos);
	free(game->object_handlers);
}
