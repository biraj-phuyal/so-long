#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/get_next_line/get_next_line.h"
# include "libft/ft_printf/ft_printf.h"
# include "mlx.h"

# define TILE_SIZE 64
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

typedef struct s_img {
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct s_data {
	void	*mlx;
	void	*win;
	t_img	*img;
	char	**map;
	int		player_x;
	int		player_y;
	int		exit_x;
	int		exit_y;
	int		collectibles;
}	t_data;

// Function declarations
void	make_map(void);

#endif