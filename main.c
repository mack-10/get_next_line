#include "get_next_line.h"

int main()
{
	int		fd;
	char	*line;
	int		i = 4;

	line = 0;
	fd = open("test.txt", O_RDONLY);
	while (i--)
	{
		get_next_line(fd, &line);
		printf("line: %s\n", line);
		printf("\n-------------------\n\n");
		ft_memset(line, 0, 15);
	}		
}
