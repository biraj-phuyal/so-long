#include "so_long.h"

char **map_array(t_map *map)
{
	int fd;

	map->line = "";
	fd = open(map->filename, O_RDONLY);
	while (map->line)
	{
		map->line = get_next_line(fd);
		if (!map->line)
			return (NULL);
		
	}
	
}
