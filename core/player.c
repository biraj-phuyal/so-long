/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 00:00:00 by biphuyal          #+#    #+#             */
/*   Updated: 2025/11/09 14:59:40 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	get_new_position(int keycode, int *new_i, int *new_j)
{
	if (keycode == W_KEY)
		(*new_i)--;
	else if (keycode == A_KEY)
		(*new_j)--;
	else if (keycode == S_KEY)
		(*new_i)++;
	else if (keycode == D_KEY)
		(*new_j)++;
}

static void	update_player_position(t_game *game, int i, int j, int keycode)
{
	int		new_i;
	int		new_j;
	char	target;

	new_i = i;
	new_j = j;
	get_new_position(keycode, &new_i, &new_j);
	target = game->map[new_i][new_j];
	if (target == '1')
		return ;
	if (target == 'E')
	{
		if (game->collectibles_remaining == 0)
			ft_exit(game, EXIT_SUCCESS);
		return ;
	}
	if (keycode == A_KEY)
		game->player_direction = 1;
	else if (keycode == D_KEY)
		game->player_direction = 0;
	if (target == 'C')
		game->collectibles_remaining--;
	game->map[i][j] = '0';
	game->map[new_i][new_j] = 'P';
}

void	move_player(t_game *game, int keycode)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				update_player_position(game, i, j, keycode);
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
		render_map(game);
	}
}
