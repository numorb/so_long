/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_mapping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 20:22:13 by blnunez-          #+#    #+#             */
/*   Updated: 2024/12/11 04:00:06 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    end_game(t_game *game, int win)
{
    if (win)
        printf("WINNNNN\n");
    else
        printf("YOU LOST! :((");
    close_handler(game);
}

void    player_collect(t_game *game, t_position p)
{
    int i;
    
    game->map.mapping[p.y][p.x] = '0';
    game->collected++;
    i = -1;
    while (++i < game->character.collectables.count)
    {
        if (p.x == game->character.collectables.pos[i].x && \
            p.y == game->character.collectables.pos[i].y)
        {
            game->character.collectables.pos[i].x = -1;
            return ;
        }
    }
}

void    move_player(t_game *game, int x, int y)
{
    t_position  p;

    game->character.player.pos[0].x += x;
    game->character.player.pos[0].y += y;
    p = game->character.player.pos[0];
    ft_printf("Steps: %d\n", game->steps);
    if (game->map.mapping[p.y][p.x] == 'C')
        player_collect(game, p);
    p = game->character.player.pos[0];
    if (game->map.mapping[p.y][p.x] == 'E' && \
        game->collected == game->character.collectables.count)
        end_game(game, 1);
    if (game->map.mapping[p.y][p.x] == 'X' )
        game->game_over = 1;
}

int key_handler(int key, t_game *game)
{
    t_position player_pos;

    player_pos = game->character.player.pos[0];
    if (key == XK_Escape)
        close_handler(game);
    if (game->game_over)
        return (0);
    if ((key == KEY_ARROW_RIGHT || key == KEY_D) && \
        game->map.mapping[player_pos.y][player_pos.x + 1] != '1' \
        && ++game->steps)
        move_player(game, 1, 0);
    else if ((key == KEY_ARROW_LEFT || key == KEY_A) && \
        game->map.mapping[player_pos.y][player_pos.x - 1] != '1' \
        && ++game->steps)
        move_player(game, -1, 0);
    else if ((key == KEY_ARROW_UP || key == KEY_W) && \
        game->map.mapping[player_pos.y - 1][player_pos.x] != '1' \
        && ++game->steps)
        move_player(game, 0, -1);
    else if ((key == KEY_ARROW_DOWN || key == KEY_S) && \
        game->map.mapping[player_pos.y + 1][player_pos.x] != '1' \
        && ++game->steps)
        move_player(game, 0, 1);
    return (0);
}

int close_handler(t_game *game)
{
    int     i;

    i = 0;
    free_object_handlers(game);
    while(game->map.mapping[i])
        free(game->map.mapping[i++]);
    free(game->map.mapping);
    mlx_destroy_image(game->mlx, game->character.collectables.img[0]->img);
    free(game->character.collectables.img[0]);
    mlx_destroy_image(game->mlx, game->character.enemies.img[0]->img);
    free(game->character.enemies.img[0]);
    mlx_destroy_image(game->mlx, game->character.exit.img[0]->img);
    free(game->character.exit.img[0]);
    mlx_destroy_image(game->mlx, game->character.exit.img[1]->img);
    free(game->character.exit.img[1]);
    mlx_destroy_image(game->mlx, game->character.player.img[0]->img);
    free(game->character.player.img[0]);
    mlx_destroy_image(game->mlx, game->character.player.img[1]->img);
    free(game->character.player.img[1]);
    mlx_destroy_image(game->mlx, game->screen.img);
    mlx_destroy_window(game->mlx, game->win);
    mlx_destroy_display(game->mlx);
    free(game->mlx);
    exit (0);
}
