#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	char	src[1000];
	char	*line;
	int		fd;
	int		fd1;
	int		fd2;
	int		n;
	int		n1;
	int		n2;
	int		i = 1;
	int		j = 1;


	//fd = 180;
	//fd = open("/home/user/get_next_line/42TESTERS-GNL/files/alphabet", O_RDONLY);
	//fd = open("/home/user/get_next_line/test.txt", O_RDONLY);
	fd1 = open("/home/user/get_next_line/42TESTERS-GNL/files/alphabet", O_RDONLY);
	fd2 = open("/home/user/get_next_line/42TESTERS-GNL/files/empty_lines", O_RDONLY);

	//01
	/*line = NULL;
	while ((n = get_next_line(fd, &line)) > 0)
	{
		printf("%2d: [%d] %s\n", i, n, line);
		free_p(&line);
		i++;
	}
	if (n == -1)
		printf("error\n");
	else
	{
		printf("%2d: [%d] %s\n", i, n, line);
		free_p(&line);
	}*/

	//02
	//line의 주솟값이 NULL
	/*n = get_next_line(fd, NULL);
	pr intf("n = %d\n", n);
	printf("error\n");*/

	//03
	//여러개의 fd
	while (n1 || n2)
	{
		if ((n1 = get_next_line(fd1, &line)) > 0)
		{
			printf("[fd1] %2d: [%d] %s\n", i, n1, line);
			free_p(&line);
			i++;
		}
		else if (!n1 && i)
		{
			printf("[fd1] %2d: [%d] %s\n", i, n1, line);
			free_p(&line);
			i = 0;
		}
		if ((n2 = get_next_line(fd2, &line)) > 0)
		{
			printf("[fd2] %2d: [%d] %s\n", j, n2, line);
			free_p(&line);
			j++;
		}
		else if (!n2 && j)
		{
			printf("[fd2] %2d: [%d] %s\n", j, n2, line);
			free_p(&line);
			j = 0;
		}
	}
}
