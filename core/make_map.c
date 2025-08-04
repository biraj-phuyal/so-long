#include "../so_long.h"

void make_map(void)
{
	int fd;
	char *line;
	int row_count;

	ft_printf("Attempting to open map file...\n");
	
	fd = open("assets/map/map.ber", O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error: Cannot open map file 'assets/map/map.ber'\n");
		return;
	}

	ft_printf("Map file opened successfully, fd = %d\n", fd);
	row_count = 0;
	
	while ((line = get_next_line(fd)) != NULL)
	{
		ft_printf("Debug: line pointer = %p\n", (void*)line);
		
		if (line)
		{
			ft_printf("Row %d chars: ", row_count);
			int i = 0;
			while (line[i] != '\0' && i < 20)
			{
				ft_printf("%c", line[i]);
				i++;
			}
			ft_printf(" (len=%d)\n", i);
			row_count++;
		}
		
		if (line)
			free(line);
	}
	close(fd);
	ft_printf("Map loaded successfully with %d rows\n", row_count);
}