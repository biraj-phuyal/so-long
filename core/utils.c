/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 12:10:45 by biphuyal          #+#    #+#             */
/*   Updated: 2025/11/13 13:43:06 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P');
}

int	exit_game(t_game *game)
{
	ft_exit(game, EXIT_SUCCESS);
	return (0);
}

char	**duplicate_map(t_game *game)
{
	char	**map_copy;
	int		i;

	map_copy = strv_new(game->map_height + 1);
	i = 0;
	while (game->map[i])
	{
		map_copy[i] = ft_strdup(game->map[i]);
		if (!map_copy[i])
			print_error_and_exit(game, "Memory allocation failed");
		i++;
	}
	return (map_copy);
}

void	flood_fill(char **map_copy, int x, int y, int *collectibles)
{
	if (map_copy[y][x] == '1' || map_copy[y][x] == 'V' || map_copy[y][x] == 'E')
		return ;
	if (map_copy[y][x] == 'C')
		(*collectibles)++;
	map_copy[y][x] = 'V';
	flood_fill(map_copy, x + 1, y, collectibles);
	flood_fill(map_copy, x - 1, y, collectibles);
	flood_fill(map_copy, x, y + 1, collectibles);
	flood_fill(map_copy, x, y - 1, collectibles);
}

bool	check_filename(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 5 || ft_strcmp(filename + len - 4, ".ber") != 0)
		return (false);
	if (filename[len - 5] == '/')
		return (false);
	if (filename[len - 5] == '.')
		return (false);
	return (true);
}
