/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:23:07 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/21 17:32:25 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int args, char **argv)
{
	static t_game game = {0};

	if (args == 2)
	{
		game.filename = argv[1];
		load_map(&game);
		game.mlx = mlx_init();
		if (!game.mlx)
		{
			write(2, "Failed to initialize MLX\n", 25);
			return (1);
		}
		game.win = mlx_new_window(game.mlx, game.x
				* IMG_PXL, game.y * IMG_PXL, WND_NAME);
		if (!game.win)
		{
			write(2, "Failed to create window\n", 24);
			return (1);
		}
		mlx_loop(game.mlx);
	}
	return (0);
}
