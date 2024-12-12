/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_mapping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:19:57 by blnunez-          #+#    #+#             */
/*   Updated: 2024/12/12 03:22:33 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_checker(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->size.height)
	{
		j = 0;
		while (j < map->size.width)
		{
			if ((j == 0 || j == map->size.width - 1 || i == 0 || \
			i == map->size.height - 1) && map->mapping[i][j] != '1')
			{
				ft_printf("Error\nEnter a rectangular map closed by walls\n");
				return (1);
			}
			else
				j++;
		}
		i++;
	}
	return (0);
}

int	load_map(char *file, char *mem_map)
{
	int		fd;
	ssize_t	buffer_size;
	ssize_t	total_size;
	char	buffer[4096];

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	total_size = 0;
	buffer_size = read(fd, buffer, 4096);
	while (buffer_size > 0)
	{
		ft_memcpy(mem_map + total_size, buffer, buffer_size);
		total_size += buffer_size;
		buffer_size = read(fd, buffer, 4096);
	}
	close(fd);
	if (total_size <= 0)
		return (-1);
	mem_map[total_size] = '\0';
	return (0);
}

ssize_t	get_map_size(char *file)
{
	int		fd;
	ssize_t	buffer_size;
	ssize_t	total_size;
	char	buffer[4096];

	fd = open(file, O_RDONLY);
	total_size = 0;
	if (fd < 0)
		return (-1);
	buffer_size = read(fd, buffer, 4096);
	while (buffer_size > 0)
	{
		total_size += buffer_size;
		buffer_size = read(fd, buffer, 4096);
	}
	close(fd);
	if (total_size <= 0)
		return (-1);
	return (total_size);
}

int	maps(char *file, t_map *map)
{
	ssize_t	total_size;
	char	*mem_map;
	int		height;

	height = 0;
	total_size = get_map_size(file);
	if (total_size < 0)
		return (ft_printf("Error\nWrong map.\n"), 1);
	mem_map = (char *)malloc((total_size + 1) * sizeof(char));
	if (!mem_map)
		return (-1);
	ft_memset(mem_map, 0, total_size + 1);
	if (load_map(file, mem_map))
		return (free(mem_map), 1);
	map->mapping = ft_split(mem_map, '\n');
	free(mem_map);
	map->size.width = ft_strlen(map->mapping[0]);
	while (map->mapping[height])
		++height;
	map->size.height = height;
	if (map_checker(map))
		return (1);
	return (0);
}
