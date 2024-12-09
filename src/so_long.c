/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:56:58 by blnunez-          #+#    #+#             */
/*   Updated: 2024/12/09 21:31:22 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void put_pixel(char *img, t_size size, t_position pos, int color)
{
    if (pos.x < 0 || pos.y < 0 || pos.x >= size.width || pos.y >= size.height)
        return ;
    ((int*)img)[pos.y * size.width + pos.x] = color;
}

void    object_to_image(t_object *object, t_image *image, t_position pos_img)
{
    t_size size;
    t_position pos_obj;
    t_position pos;
    int color;

    //size.height = 0;
    size.height = object->size.height;
    size.width = object->size.width;
    pos_obj.y = 0;
    while (pos_obj.y < object->size.height)
    {
        pos_obj.x = 0;
        while (pos_obj.x < object->size.width)
        {
            pos.x = pos_img.x + pos_obj.x;
            pos.y = pos_img.y + pos_obj.y;
            color = ((int *)object->img->buffer)[pos_obj.y * object->img->size_line + pos_obj.x];
            put_pixel(image->buffer, size, pos, color);
            pos_obj.x++;
        }
        pos_obj.y++;
    }
}

int game_loop(t_game *game)
{
    t_position  pixel_position;
    int         background_color;
    
    pixel_position.y = 0;
    background_color = 0x4242AB;
    while (pixel_position.y < game->screen_size.height)
    {
        pixel_position.x = 0;
        while (pixel_position.x < game->screen_size.width)
        {
            
            put_pixel(game->screen.buffer, game->screen_size, pixel_position, background_color);
            ++pixel_position.x;
        }
        ++pixel_position.y;
    }
    // t_position pos_img;
    // pos_img.x = 0;
    // pos_img.y = 0;
    // object_to_image(&game->character.player, game->screen.img, pos_img);
    mlx_put_image_to_window(game->mlx, game->win, game->screen.img, 0, 0);
    mlx_put_image_to_window(game->mlx, game->win, game->character.player.img, game->character.player.pos.x, game->character.player.pos.y);
    return (0);
}

void build_image(t_image *image, void *mlx, t_size size)
{
    image->img = mlx_new_image(mlx, size.width, size.height);
    image->buffer = mlx_get_data_addr(image->img, &image->bpp, &image->size_line, &image->endian);
}

int sprites(t_game *game)
{
    t_object    *p;

    p = &game->character.player;
    p->img = mlx_xpm_file_to_image(game->mlx, GHOST3,&p->size.width, &p->size.height);
    return (0);
}

void    objects_positions(t_game *game, char *object_type, char object)
{
    t_position  pos;
    int         i;
    int         j;
    int         k;

    i = 0;
    while (i < game->map.size.width)
    {
        j = 0;
        while (j < game->map.size.height)
        {
            game->map.mapping[i][j];
            k = 0;
            while (k < game->num_handlers)
            if (game->object_handlers[k].object_char ==  game->map.mapping[i][j] == object)
            {
                pos.x = i;
                pos.y = j;
                game->object_handlers[k].position_handler(game, pos);
                break;
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
    while (i < game->map.size.width)
    {
        j = 0;
        while (j < game->map.size.height)
        {
            k = 0;
            while (k < game->num_handlers)
            {
                if (game->object_handlers[k].object_char == game->map.mapping[i][j])
                {
                    game->object_handlers[k].count_incrementer(game);
                    break;
                }
                ++k;
            }
            ++j;
        }
        ++i;
    }
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
    objects_count(&game);
    game->object_handlers[0] = (t_object_handler){'P', handle_player_position, increment_player_count};
    game->object_handlers[1] = (t_object_handler){'E', handle_exit_position, increment_exit_count};
    game->object_handlers[2] = (t_object_handler){'C', handle_collectible_position, increment_collectible_count};
    game->object_handlers[3] = (t_object_handler){'1', handle_wall_position, increment_wall_count};
    game->object_handlers[4] = (t_object_handler){'X', handle_enemy_position, increment_enemy_count};
}

void free_object_handlers(t_game *game)
{
    free(game->object_handlers);
}

void    objects_mapping(t_game *game)
{
    objects_count(&game);
    objects_positions(&game);
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
    init_object_handlers(&game);
    maps(argv[1], &game.map);
    objects_mapping(&game);
    sprites(&game);

    mlx_key_hook(game.win, key_handler, &game);
    mlx_hook(game.win, 17, 0, close_handler, &game);

    mlx_loop_hook (game.mlx, game_loop, &game);
    return (mlx_loop(game.mlx));
}