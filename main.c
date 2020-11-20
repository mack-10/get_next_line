#include "get_next_line.h"

int main()
{
	int		fd;
	char	*line;
	int		i = 4;

	line = 0;
	fd = open("test.txt", O_RDONLY);
	/*
	while (i--)
	{
		get_next_line(fd, &line);
		printf("line: %s\n", line);
		if (i > 0)
			printf("\n--------------------\n\n");
	}*/

	get_next_line(fd, &line);
	while (1)
		;
	
}
