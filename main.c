#include "get_next_line.h"

int main()
{
	int		fd;
	char	*line;
	int		i = 1;
	int		n;
	char	src[1000];

	//fd = 180;
	fd = open("/home/user/gnl/42TESTERS-GNL/files/alphabet", O_RDONLY);
	//fd = open("/home/user/gnl/test.txt", O_RDONLY);

	//01
	line = NULL;
	while ((n = get_next_line(fd, &line)) != 0)
	{
		printf("%2d: [%d] %s\n", i, n, line);
		free_p(&line);
		i++;
	}
	printf("%2d: [%d] %s\n", i, n, line);
	free_p(&line);

	//02
	/*
	while (read(fd, src, 1000))
		;
	printf("%s\n", src);*/
}
