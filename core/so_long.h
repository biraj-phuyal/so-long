/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:44:08 by biphuyal          #+#    #+#             */
/*   Updated: 2025/09/27 15:43:46 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define IMG_PXL 50
# define WND_NAME "so_long"

# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../mlx.h"
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
	int		p;
	int		c;
	int		e;
	int		exit;
	int		collectibles;
	t_player	player;
}	t_map;

void 	checks(t_map *map);
void 	map_array(t_map *map);
void 	check_wall(t_map *map);
void	error_on_filename(void);
void	error_on_wall(t_map *map);
void	error_on_size(t_map *map);
void	error_on_map_elements(t_map *map);
void	error_on_openfile(void);
int		free_the_array(char **ret, int i);
void	exit_after_free(t_map *map);

#endif