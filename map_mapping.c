/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:19:57 by blnunez-          #+#    #+#             */
/*   Updated: 2024/12/09 20:20:36 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    load_map(char *file, char *mem_map)
{
    int     fd;
    ssize_t buffer_size;
    ssize_t total_size;
    char    buffer[4096];
    
    fd = open(file, O_RDONLY);
    total_size = 0;
    if (fd < 0)
        return (-1);
    buffer_size = read(fd, buffer, 4096);
    while (buffer_size > 0)
    {
        ft_memcpy(mem_map + total_size, buffer, buffer_size);
        buffer_size = read(fd, buffer, 4096);
        total_size += buffer_size;
    }
    close(fd);
    if (total_size <= 0)
        return (-1);
    mem_map[total_size] = '\0';
    return (0);
}

ssize_t    get_map_size(char *file)
{
    int     fd;
    ssize_t buffer_size;
    ssize_t total_size;
    char    buffer[4096];
    
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

int     maps(char *file, t_map *map)
{
    ssize_t total_size;
    char    *mem_map;
    int     width;
    int     height;
    
    height = 0;
    total_size = get_map_size(file);
    if (total_size < 0)
        return (1);
    mem_map = (char *)malloc((total_size + 1) * sizeof(char));
    if (!mem_map)
        return (-1);
    ft_memset(mem_map, 0, total_size + 1);
    load_map(file, mem_map);
    map->mapping = ft_split(mem_map, '\n');
    free(mem_map);
    width = ft_strlen(map->mapping[0]);
    while (map->mapping[height])
    {
        printf("%s\n", map->mapping[height]);
        if ((int)ft_strlen(map->mapping[height]) != width)
            return (1);
        height++;
    }
    map->size.width = width;
    map->size.height = height;
    return (0);
}