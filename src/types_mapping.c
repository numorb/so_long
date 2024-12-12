/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_mapping.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 17:03:43 by blnunez-          #+#    #+#             */
/*   Updated: 2024/12/12 02:14:58 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	storing_position(t_game *game, int i, int j, int idxs[5])
{
	int			k;
	t_position	pos;

	k = -1;
	while (++k < game->num_handlers)
	{
		if (game->object_handlers[k].object_char == game->map.mapping[i][j])
		{
			pos.x = j;
			pos.y = i;
			game->object_handlers[k].position_handler(\
				game->object_handlers[k].object, idxs[k]++, pos);
			break ;
		}
	}
}

void	objects_positions(t_game *game)
{
	int			i;
	int			j;
	int			idxs[5];

	ft_memset(idxs, 0, sizeof(int) * 5);
	i = -1;
	while (++i < game->map.size.height)
	{
		j = -1;
		while (++j < game->map.size.width)
		{
			storing_position(game, i, j, idxs);
		}
	}
}

void	objects_count(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i < game->map.size.height)
	{
		j = -1;
		while (++j < game->map.size.width)
		{
			k = -1;
			while (++k < game->num_handlers)
			{
				if (game->object_handlers[k].object_char == \
					game->map.mapping[i][j])
				{
					game->object_handlers[k].count_incrementer(\
						game->object_handlers[k].object);
					break ;
				}
			}
		}
	}
}
