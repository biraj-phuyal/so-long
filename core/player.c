/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 00:00:00 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/30 18:23:16 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_player(t_game *game, int keycode)
{
	int	i;
	int	j;
	int	new_i;
	int	new_j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				new_i = i;
				new_j = j;
				if (keycode == W_KEY)
					new_i--;
				else if (keycode == A_KEY)
					new_j--;
				else if (keycode == S_KEY)
					new_i++;
				else if (keycode == D_KEY)
					new_j++;
				if (game->map[new_i][new_j] != '1' && game->map[new_i][new_j] != 'E')
				{
					game->map[i][j] = '0';
					game->map[new_i][new_j] = 'P';
				}
				return ;
			}
			j++;
		}
		i++;
	}
}

void	key_hook(int keycode, t_game *game)
{
	if (keycode == ESC_KEY)
		ft_exit(game, EXIT_SUCCESS);
	if (keycode == W_KEY || keycode == A_KEY
		|| keycode == S_KEY || keycode == D_KEY)
	{
		move_player(game, keycode);
	}
}
