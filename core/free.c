/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:11:42 by biphuyal          #+#    #+#             */
/*   Updated: 2025/11/06 14:54:23 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_exit(t_game *game, int keycode)
{
	free_image(game->mlx, game->floor);
	free_image(game->mlx, game->wall);
	free_image(game->mlx, game->collectables);
	free_image(game->mlx, game->exit);
	free_image(game->mlx, game->player);
	free_image(game->mlx, game->player_left);
	strv_free(game->map);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(keycode);
}

void	print_error_and_exit(t_game *game, char *message)
{
	write(2, "Error\n", 6);
	write(2, message, ft_strlen(message));
	write(2, "\n", 1);
	if (game->map)
		strv_free(game->map);
	if (game->mlx)
	{
		free_image(game->mlx, game->floor);
		free_image(game->mlx, game->wall);
		free_image(game->mlx, game->collectables);
		free_image(game->mlx, game->exit);
		free_image(game->mlx, game->player);
		free_image(game->mlx, game->player_left);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	exit(EXIT_FAILURE);
}
