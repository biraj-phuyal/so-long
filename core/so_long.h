#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define MAX_SIZE 42
# define TILE_SIZE 64
# define WIN_WIDTH 640
# define WIN_HEIGHT 512

typedef struct s_img {
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct s_player {
	int x;
	int y;
}	t_player;

typedef struct s_map {
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
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		collectibles;
}	t_map;



#endif