/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:36:34 by blnunez-          #+#    #+#             */
/*   Updated: 2024/12/11 03:45:13 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
// # define WIDTH  800
// # define HEIGHT 600
# define TILE 32
# define FRAMERATE 6
# define BACKGROUND 0x000000
# define WALL_COLOR 0x4242AB

# include <mlx.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include "libft.h"
# include "keys.h"

# include "../sprites/pacman.h"
# include "../sprites/ghost.h"
# include "../sprites/exit42.h"
# include "../sprites/forbidden_exit.h"
# include "../sprites/money.h"
# include "../sprites/pacman_dead.h"

typedef struct  s_position
{
    int x;
    int y;
}               t_position;

typedef struct  s_size
{
    int width;
    int height;
}               t_size;

typedef struct  s_map
{
    t_position  pos;
    t_size      size;
    char        **mapping;
}               t_map;

typedef struct s_image
{
    void    *img;
    char    *buffer;
    int     bpp;
    int     size_line;
    int     endian;
}               t_image;

typedef struct  s_object
{
    t_position      *pos;
    t_size          size;
    t_image         *img[5];
    int             count;
}               t_object;

typedef struct s_object_type
{
    t_object    wall;
    t_object    player;
    t_object    collectables;
    t_object    enemies;
    t_object    exit;
}               t_object_type;

typedef struct  s_object_handler
{
    char object_char;
    t_object   *object;
    void (*position_handler)(t_object *obj, int idx, t_position pos);
    void (*count_incrementer)(t_object *obj);
}               t_object_handler;

typedef struct      s_game
{
    void            *mlx;
    void            *win;
    t_image         screen;
    t_size          screen_size;
    t_object_type   character;
    int             steps;
    t_map           map;
    t_object_handler *object_handlers;
    int             num_handlers;
    int             collected;
    int             game_over;
}                   t_game;


int         key_handler(int key, t_game *game);
int         close_handler(t_game *game);
int        load_map(char *file, char *mem_map);
ssize_t     get_map_size(char *file);
int         maps(char *file, t_map *map);
void    objects_positions(t_game *game);
void    objects_count(t_game *game);
void init_object_handlers(t_game *game);
void free_object_handlers(t_game *game);
int    flood(t_game *game, int x, int y);
void    free_map(char **map, int size);

#endif
