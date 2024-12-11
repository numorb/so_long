/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_mapping.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:03:43 by blnunez-          #+#    #+#             */
/*   Updated: 2024/12/11 03:59:24 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    objects_positions(t_game *game)
{
    t_position  pos;
    int         i;
    int         j;
    int         k;
    int         idxs[5];

    i = 0;
    ft_memset(idxs, 0, sizeof(int) * 5);
    while (i < game->map.size.height)
    {
        j = 0;
        while (j < game->map.size.width)
        {
            k = 0;
            while (k < game->num_handlers)
            {
                if (game->object_handlers[k].object_char ==  game->map.mapping[i][j])
                {
                    pos.x = j;
                    pos.y = i;
                    game->object_handlers[k].position_handler(game->object_handlers[k].object, idxs[k]++, pos);
                    break ;
                }
                k++;
            }
            j++;
        }
        i++;
    }
}

void    objects_count(t_game *game)
{
    int i;
    int j;
    int k;

    i = 0;
    while (i < game->map.size.height)
    {
        j = 0;
        while (j < game->map.size.width)
        {
            k = 0;
            while (k < game->num_handlers)
            {
                if (game->object_handlers[k].object_char == game->map.mapping[i][j])
                {
                    game->object_handlers[k].count_incrementer(game->object_handlers[k].object);
                    break ;
                }
                ++k;
            }
            ++j;
        }
        ++i;
    }
}


void position_handler(t_object *obj, int idx, t_position pos)
{
    obj->pos[idx].x = pos.x;
    obj->pos[idx].y = pos.y;
}

void count_incrementer(t_object *obj)
{
    obj->count++;
}

void init_object_handlers(t_game *game)
{
    game->num_handlers = 5;
    game->object_handlers = malloc(sizeof(t_object_handler) * game->num_handlers);
    if (!game->object_handlers)
    {
        ft_printf("Error\n");
        exit(1);
    }
    ft_memset(&game->character, 0, sizeof(t_object_type));
    game->object_handlers[0] = (t_object_handler){'P',&game->character.player, &position_handler, &count_incrementer};
    game->object_handlers[1] = (t_object_handler){'E',&game->character.exit, &position_handler, &count_incrementer};
    game->object_handlers[2] = (t_object_handler){'C',&game->character.collectables, &position_handler, &count_incrementer};
    game->object_handlers[3] = (t_object_handler){'1',&game->character.wall, &position_handler, &count_incrementer};
    game->object_handlers[4] = (t_object_handler){'X',&game->character.enemies, &position_handler, &count_incrementer};
    objects_count(game);
    game->object_handlers[0].object->pos = malloc(sizeof(t_position));
    game->object_handlers[1].object->pos = malloc(sizeof(t_position));
    game->object_handlers[2].object->pos = malloc(sizeof(t_position) * game->object_handlers[2].object->count);
    game->object_handlers[3].object->pos = malloc(sizeof(t_position) * game->object_handlers[3].object->count);
    game->object_handlers[4].object->pos = malloc(sizeof(t_position) * game->object_handlers[4].object->count);
    objects_positions(game);
}

void free_object_handlers(t_game *game)
{
    int i;

    i = 0;
    while (i < game->num_handlers)
        free(game->object_handlers[i++].object->pos);
    free(game->object_handlers);
}