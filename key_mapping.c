/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mapping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:22:13 by blnunez-          #+#    #+#             */
/*   Updated: 2024/12/09 20:22:27 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_handler(int key, t_game *game)
{
    if (key == XK_Escape)
        close_handler(game);
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
    mlx_destroy_image(game->mlx, game->character.collectables->img);
    mlx_destroy_image(game->mlx, game->character.enemies->img);
    mlx_destroy_image(game->mlx, game->character.exit.img);
    mlx_destroy_image(game->mlx, game->character.wall.img);
    mlx_destroy_image(game->mlx, game->character.player.img);
    mlx_destroy_image(game->mlx, game->screen.img);
    mlx_destroy_window(game->mlx, game->win);
    mlx_destroy_display(game->mlx);
    free(game->mlx);
    exit (0);
}
