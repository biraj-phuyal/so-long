#include "so_long.h"

char **map_array(t_map *map)
{
	int fd;

	map->y = 0;
	map->line = "";
	map->file = NULL;
	fd = open(map->filename, O_RDONLY);
	while (map->line)
	{
		map->line = get_next_line(fd);
		if (map->line == NULL)
			return (NULL);
		map->file = strjoin(map->file, map->line);
		free(map->line);
		if (!map->file)
			error();
		map->y++;
	}
	close(fd);
	map->map = ft_split(map->file, '\n');
	map->copy = ft_split(map->file, '\n');
	if (!map->map || !map->copy)
		error(map);
	free(map->file);
}
