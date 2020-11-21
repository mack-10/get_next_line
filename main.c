#include "get_next_line.h"

//gnl

int main()
{
	int		fd;
	char	*line;
	int		i = 4;

	line = 0;
	fd = open("test.txt", O_RDONLY);
	while (i--)
	{
		printf("gnl: %d\n", get_next_line(fd, &line));
		printf("line: %s\n", line);
		free(line);
		line = NULL;
		if (i > 0)
			printf("\n--------------------\n\n");
	}	
}