/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:36:12 by blnunez-          #+#    #+#             */
/*   Updated: 2024/12/12 02:30:04 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_counts(t_map *map, t_position pos, int *counts)
{
	if (pos.x >= 0 && pos.x < map->size.width && \
	pos.y >= 0 && pos.y < map->size.height)
	{
		if (map->mapping[pos.y][pos.x] == 'P')
			counts[0]++;
		else if (map->mapping[pos.y][pos.x] == 'E')
			counts[1]++;
		else if (map->mapping[pos.y][pos.x] == 'C')
			counts[2]++;
		else if (map->mapping[pos.y][pos.x] != 'X' \
		&& map->mapping[pos.y][pos.x] != '0')
			return (1);
	}
	return (0);
}

int	flood_filler(t_map *map, char **flood_map, t_position pos, int *counts)
{
	if (pos.x < 0 || pos.x >= map->size.width || \
	pos.y < 0 || pos.y >= map->size.height)
		return (1);
	if (map->mapping[pos.y][pos.x] == '1' || flood_map[pos.y][pos.x] == '1')
		return (0); 
	flood_map[pos.y][pos.x] = '1';
	if (get_counts(map, pos, counts))
		return (1);
	pos.y--;
	if (flood_filler(map, flood_map, pos, counts))
		return (1);
	pos.y += 2;
	if (flood_filler(map, flood_map, pos, counts))
		return (1);
	pos.y--;
	pos.x--;
	if (flood_filler(map, flood_map, pos, counts))
		return (1);
	pos.x += 2;
	if (flood_filler(map, flood_map, pos, counts))
		return (1);
	return (0);
}

void	free_map(char **map, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(map[i++]);
	free(map);
}

int	init_flood_map(t_game *game, char ***flood_map)
{
	int	i;

	*flood_map = malloc(sizeof(char *) * game->map.size.height);
	if (!*flood_map)
		return (-1);
	i = 0;
	while (i < game->map.size.height)
	{
		(*flood_map)[i] = ft_calloc(game->map.size.width, sizeof(char *));
		if (!(*flood_map)[i])
		{
			free_map(*flood_map, i);
			return (-1);
		}
		i++;
	}
	return (i);
}

int	flood(t_game *game, t_position pos)
{
	char	**flood_map;
	int		counts[3];
	int		i;

	counts[0] = 0;
	counts[1] = 0;
	counts[2] = 0;
	flood_map = NULL;
	i = init_flood_map(game, &flood_map);
	if (i < 0 || flood_filler(&game->map, flood_map, pos, counts))
	{
		free_map(flood_map, i);
		ft_printf("Error\nBad map.\n");
		return (1);
	}
	free_map(flood_map, game->map.size.height);
	if (counts[2] != game->character.collectables.count \
		|| counts[1] != 1 || counts[0] != 1)
	{
		ft_printf("Error\nBad map.\n");
		return (1);
	}
	return (0);
}
