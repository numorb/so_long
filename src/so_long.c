/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:56:58 by blnunez-          #+#    #+#             */
/*   Updated: 2024/12/11 03:39:52 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void put_pixel(char *img, t_size size, t_position pos, int color)
{
    if (pos.x < 0 || pos.y < 0 || pos.x >= size.width || pos.y >= size.height)
        return ;
    ((int*)img)[pos.y * size.width + pos.x] = color;
}

void    object_to_screen(t_game *game, t_object *object, int img_idx, t_position pos_img)
{
    t_position pos_obj;
    t_position pos;
    int offset;
    int color;

    pos_obj.y = 0;
    while (pos_obj.y < object->size.height)
    {
        pos_obj.x = 0;
        while (pos_obj.x < object->size.width)
        {
            pos.x = pos_img.x * TILE + pos_obj.x;
            pos.y = pos_img.y * TILE + pos_obj.y;
            offset = pos_obj.y * object->img[img_idx]->size_line + pos_obj.x * 4;
            if ((object->img[img_idx]->buffer[offset + 3] & 0xFF))
            {
                color = (object->img[img_idx]->buffer[offset + 2] & 0xFF) | \
                    ((object->img[img_idx]->buffer[offset + 1] & 0xFF) << 8) | \
                    ((object->img[img_idx]->buffer[offset + 0] & 0xFF) << 16);
                put_pixel(game->screen.buffer, game->screen_size, pos, color);
            }
            pos_obj.x++;
        }
        pos_obj.y++;
    }
}

void    draw_walls(t_game *game)
{
    int tiley;
    int tilex;
    t_position screen_p;
    t_position tile_p;
    
    tiley = -1;
    while (++tiley < game->map.size.height)
    {
        tilex = -1;
        while (++tilex < game->map.size.width)
        {
            if (game->map.mapping[tiley][tilex] != '1')
                continue ;
            tile_p.y = -1;
            while (++tile_p.y < TILE)
            {
                tile_p.x = -1;
                while (++tile_p.x < TILE)
                {
                    screen_p.x = tilex * TILE + tile_p.x;
                    screen_p.y = tiley * TILE + tile_p.y;
                    put_pixel(game->screen.buffer, game->screen_size, screen_p, WALL_COLOR);
                }
            }
        }
    }
}

void draw_enemies(t_game *game, int frame)
{
    int i;

    i = 0;
    while (i < game->character.enemies.count)
    {
        object_to_screen(game, &game->character.enemies, 0, \
            game->character.enemies.pos[i]);
        i++;
    }
    game->character.enemies.img[0]->buffer = \
        ((char *)ghost_data[(frame++ / FRAMERATE) % GHOST_FRAME_COUNT]);
}

void    draw_exit(t_game *game, int frame)
{
    int i;

    i = 0;
    if (game->collected == game->character.collectables.count)
        i = 1;
    object_to_screen(game, &game->character.exit, i, \
        game->character.exit.pos[0]);
    game->character.exit.img[0]->buffer = ((char *)forbidden_exit_data[(frame++ / FRAMERATE) % FORBIDDEN_EXIT_FRAME_COUNT]);
    game->character.exit.img[1]->buffer = ((char *)exit42_data[(frame++ / FRAMERATE) % EXIT42_FRAME_COUNT]);
}

void    draw_collectibles(t_game *game, int frame)
{
    int i;

    i = 0;
    while (i < game->character.collectables.count)
    {
        if (game->character.collectables.pos[i].x > 0)
            object_to_screen(game, &game->character.collectables, 0, \
                game->character.collectables.pos[i]);
        i++;
    }
    game->character.collectables.img[0]->buffer = \
        ((char *)money_data[(frame++ / FRAMERATE) % MONEY_FRAME_COUNT]);
}

int game_loop(t_game *game)
{
    static int  frame = 0;
    t_position  pixel_position;
    
    pixel_position.y = 0;
    while (pixel_position.y < game->screen_size.height)
    {
        pixel_position.x = 0;
        while (pixel_position.x < game->screen_size.width)
        {
            
            put_pixel(game->screen.buffer, game->screen_size, pixel_position, BACKGROUND);
            ++pixel_position.x;
        }
        ++pixel_position.y;
    }
    draw_walls(game);
    draw_exit(game, frame);
    draw_collectibles(game, frame);
    if (game->game_over == 0)
    {    
        object_to_screen(game, &game->character.player, 0, game->character.player.pos[0]);
        game->character.player.img[0]->buffer = ((char *)pacman_data[(frame++ / FRAMERATE) % PACMAN_FRAME_COUNT]);
    }
    draw_enemies(game, frame);
    if (game->game_over != 0)
    {
        if (game->game_over == 1)
            frame = 0;
        object_to_screen(game, &game->character.player, 1, game->character.player.pos[0]);
        game->character.player.img[1]->buffer = ((char *)pacman_dead_data[(frame / FRAMERATE) % PACMAN_DEAD_FRAME_COUNT]);
        if (frame / FRAMERATE < PACMAN_DEAD_FRAME_COUNT - 1)
            frame++;
        if (++game->game_over == 82)
            close_handler(game);
    }
    mlx_put_image_to_window(game->mlx, game->win, game->screen.img, 0, 0);
    return (0);
}

void build_image(t_image *image, void *mlx, t_size size)
{
    image->img = mlx_new_image(mlx, size.width, size.height);
    image->buffer = mlx_get_data_addr(image->img, &image->bpp, &image->size_line, &image->endian);
}

int create_img(t_game *game, t_object *object, char *data, int idx)
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

int sprites(t_game *game)
{
    if (create_img(game, &game->character.player, (char *)pacman_data, 0))
        return (1);
    if (create_img(game, &game->character.player, (char *)pacman_dead_data, 1))
        return (1);
    if (create_img(game, &game->character.enemies, (char *)ghost_data, 0))
        return (1);
    if (create_img(game, &game->character.exit, (char *)forbidden_exit_data, 0))
        return (1);
    if (create_img(game, &game->character.exit, (char *)exit42_data, 1))
        return (1);
    if (create_img(game, &game->character.collectables, (char *)money_data, 0))
        return (1);
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
    t_size max_size;
    mlx_get_screen_size(game.mlx, &max_size.width, &max_size.height);
    maps(argv[1], &game.map);
    if (game.map.size.width * TILE > max_size.width || game.map.size.height * TILE > max_size.height)
    {
        ft_printf("Sorry, the map is to big for this screen. Go smaller or go home!");
        return (1);
    }
    game.screen_size.width = game.map.size.width * TILE;
    game.screen_size.height = game.map.size.height * TILE;
    game.win = mlx_new_window(game.mlx, game.screen_size.width + 1, game.screen_size.height + 1,"Lets the game comence!");
    if (!game.win)
    {
        mlx_destroy_display(game.mlx);
        return (1);
    }
    mlx_hook(game.win, 17, 0, close_handler, &game);
    mlx_key_hook(game.win, key_handler, &game);
    build_image(&game.screen, game.mlx, game.screen_size);
    init_object_handlers(&game);
    flood(&game, game.character.player.pos[0].x, game.character.player.pos[0].y);
    if (sprites(&game))
        close_handler(&game);
    game.collected = 0;
    game.steps = 0;
    game.game_over = 0;

    mlx_loop_hook (game.mlx, game_loop, &game);
    return (mlx_loop(game.mlx));
}