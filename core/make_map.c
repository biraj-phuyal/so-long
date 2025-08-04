#include "mlx.h"
#include "get_next_line.h"
#include <stdlib.h>

void make_map()
{
	int fd;
	char **line;

	fd = open("../assets/map/map.ber", O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\n");
		return;
	}

	while ((*line = get_next_line(fd)) != NULL)
	{
		*line = get_next_line(fd)
	}
	close(fd);
	free(*line);
}