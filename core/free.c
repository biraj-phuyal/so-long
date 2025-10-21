/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 13:11:42 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/21 17:16:30 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	free_the_array(char **ret, int i)
{
	while (i > 0)
		free(ret[--i]);
	free(ret);
	return (0);
}

void	exit_after_free(t_game *game)
{
	if (game->map)
		free_the_array(game->map, game->y);
	if (game->copy)
		free_the_array(game->copy, game->y);
	if (game->file)
		free(game->file);
	if (game->line)
		free(game->line);
	exit(EXIT_FAILURE);
}