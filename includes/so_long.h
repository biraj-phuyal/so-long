/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:44:08 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/21 17:11:07 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define IMG_PXL 64
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
	int		*wall;
	int		*player_up;
	int		*player_down;
	int		*player_right;
	int		*player_left;
	int		*floor;
	int		*collectables;
	int		*exit;

}	t_img;

typedef struct s_player
{
	int left;
	int right;
	int up;
	int down;
}	t_player;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
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
}	t_game;

void	load_map(t_game *game);
void 	map_array(t_game *game);
void 	check_wall(t_game *game);
void	error_on_filename(void);
void	error_on_wall(t_game *game);
void	error_on_size(t_game *game);
void	error_on_map_elements(t_game *game);
void	error_on_openfile(void);
int		free_the_array(char **ret, int i);
void	exit_after_free(t_game *game);

#endif