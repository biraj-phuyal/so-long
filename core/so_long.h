/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:44:08 by biphuyal          #+#    #+#             */
/*   Updated: 2025/08/19 12:02:41 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx.h"
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"


typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct s_player
{
	int x;
	int y;
}	t_player;

typedef struct s_map 
{
	void	*mlx;
	void	*win;
	t_img	*img;
	char	*filename;
	char	*line;
	char	*file;
	char	**map;
	char	**copy;
	int		y;
	int		x;
	int		player;
	int		exit;
	int		collectibles;
}	t_map;

void map_array(t_map *map);
void checks(t_map *map);

#endif