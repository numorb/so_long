/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blnunez- <blnunez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 11:56:58 by blnunez-          #+#    #+#             */
/*   Updated: 2024/12/12 02:31:22 by blnunez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	no_ber(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 5)
		return (1);
	return (ft_strncmp(filename + len - 4, ".ber", 4));
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (argc != 2 || no_ber(argv[1]))
	{
		ft_printf("Error\nAdd just one file as an argument, of type .ber.\n");
		return (1);
	}
	if (init_game(&game, argv))
		close_handler(&game);
	mlx_hook(game.win, 17, 0, close_handler, &game);
	mlx_key_hook(game.win, key_handler, &game);
	build_image(&game.screen, game.mlx, game.screen_size);
	init_object_handlers(&game);
	if (flood(&game, game.character.player.pos[0]))
		close_handler(&game);
	if (sprites(&game))
		close_handler(&game);
	game.collected = 0;
	game.steps = 0;
	game.game_over = 0;
	mlx_loop_hook (game.mlx, game_loop, &game);
	return (mlx_loop(game.mlx));
}
