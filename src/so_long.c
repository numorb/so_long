/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:56:58 by blnunez-          #+#    #+#             */
/*   Updated: 2024/12/08 23:46:15 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_handler(int key, t_game *game)
{
    if (key == XK_Escape)
    {
        close_handler(game);
    }
    if (key == KEY_ARROW_RIGHT || key == KEY_D)
        game->character.player.pos.x += 1;
    else if (key == KEY_ARROW_LEFT || key == KEY_A)
        game->character.player.pos.x -= 1;
    else if (key == KEY_ARROW_UP || key == KEY_W)
        game->character.player.pos.y -= 1;
    else if (key == KEY_ARROW_DOWN || key == KEY_S)
        game->character.player.pos.y += 1;
    return (0);
}

int close_handler(t_game *game)
{
    int     i;

    i = 0;
    while(game->map.mapping[i])
        free(game->map.mapping[i++]);
    free(game->map.mapping);
    mlx_destroy_image(game->mlx, game->character.player.img);
    mlx_destroy_image(game->mlx, game->screen.img);
    mlx_destroy_window(game->mlx, game->win);
    mlx_destroy_display(game->mlx);
    free(game->mlx);
    exit (0);
}

void put_pixel(char *img, t_size size, t_position pos, int color)
{
    //int offset = (pos.y * size.width + pos.x) * 4;

    if (pos.x < 0 || pos.y < 0 || pos.x >= size.width || pos.y >= size.height)
        return ;
    // *(img + offset++) = (color >> 0) & 0xFF;
    // offset++[img] = (color >> 0) & 0xFF;
    // img[offset++] = (color >> 0) & 0xFF;
    // img[offset++] = (color >> 8) & 0xFF;
    // img[offset++] = (color >> 16) & 0xFF;
    // img[offset++] = (color >> 24) & 0xFF;
    ((int*)img)[pos.y * size.width + pos.x] = color;
}

void    object_to_image(t_object *object, t_image *image, t_position pos_img)
{
    t_size size;
    t_position pos_obj;
    t_position pos;

    size.height = 0;
    size.width = image->size_line;
    pos_obj.y = 0;
    while (pos_obj.y < object->size.height)
    {
        pos_obj.x = 0;
        while (pos_obj.x < object->size.width)
        {
            pos.x = pos_img.x + pos_obj.x;
            pos.y = pos_img.y + pos_obj.y;
            int color = ((int *)object->img->buffer)[pos_obj.y * object->img->size_line + pos_obj.x];
            put_pixel(image->buffer, size, pos, color);
            pos_obj.x++;
        }
        pos_obj.y++;
    }
}

int game_loop(t_game *game)
{
    t_position origin;
    origin.y = 0;
    while (origin.y < game->screen_size.height)
    {
        origin.x = 0;
        while (origin.x < game->screen_size.width)
        {
            
            put_pixel(game->screen.buffer, game->screen_size, origin, 0x4242AB);
            ++origin.x;
        }
        ++origin.y;
    }
    // t_position pos_img;
    // pos_img.x = 0;
    // pos_img.y = 0;
    // object_to_image(&game->character.player, game->screen.img, pos_img);
    mlx_put_image_to_window(game->mlx, game->win, game->screen.img, 0, 0);
    mlx_put_image_to_window(game->mlx, game->win, game->character.player.img, 100, 100);
    return (0);
}

void build_image(t_image *image, void *mlx, t_size size)
{
    image->img = mlx_new_image(mlx, size.width, size.height);
    image->buffer = mlx_get_data_addr(image->img, &image->bpp, &image->size_line, &image->endian);
}

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

int sprites(t_game *game)
{
    t_object    *p;

    p = &game->character.player;
    p->img = mlx_xpm_file_to_image(game->mlx, GHOST3,&p->size.width, &p->size.height);
    return (0);
}

int main(int argc, char **argv)
{
    t_game  game;
    
    if (argc != 2)
        return (0);
    game.mlx = mlx_init();
    if (!game.mlx)
        return (1);
    game.screen_size.width = WIDTH;
    game.screen_size.height = HEIGHT;
    game.win = mlx_new_window(game.mlx, game.screen_size.width + 1, game.screen_size.height + 1,"Lets the game comence!");
    if (!game.win)
    {
        mlx_destroy_display(game.mlx);
        return (1);
    }
    build_image(&game.screen, game.mlx, game.screen_size); //background
    
    mlx_key_hook(game.win, key_handler, &game);
    mlx_hook(game.win, 17, 0, close_handler, &game);

    maps(argv[1], &game.map);
    sprites(&game);
    mlx_loop_hook (game.mlx, game_loop, &game);

    return (mlx_loop(game.mlx));
}