/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 00:00:00 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/31 16:44:19 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	init_game(t_game *game, char **argv)
{
	game->mlx = mlx_init();
	load_assets(game);
	game->player_direction = 0;
	if (!load_map(game, argv[1]))
	{
		write(2, "Error\nCould not load map\n", 26);
		ft_exit(game, EXIT_FAILURE);
	}
}

static void	setup_window(t_game *game)
{
	int	width;
	int	height;

	width = game->map_width * IMG_PXL;
	height = game->map_height * IMG_PXL;
	game->win = mlx_new_window(game->mlx, width, height, WND_NAME);
	mlx_key_hook(game->win, (void *)key_hook, game);
	mlx_loop_hook(game->mlx, (void *)render_map, game);
	mlx_hook(game->win, 17, 0, (void *)exit_game, game);
}

int	main(int args, char **argv)
{
	static t_game	game;

	if (args != 2)
	{
		write(2, "Error\nInvalid number of arguments\n", 34);
		exit(EXIT_FAILURE);
	}
	init_game(&game, argv);
	setup_window(&game);
	mlx_loop(game.mlx);
	return (0);
}
