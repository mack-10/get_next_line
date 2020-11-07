#include <stdio.h>
#include <fcntl.h>

int main()
{
	int		fd;
	int 	len = 0;
	int		idx = 0;
	char	a;
	char	str[5][6];

	fd = open("a", O_RDONLY);
	while (read(fd, &a, 1) > 0)
	{
		if (a == '\n')
			break ;
		str[0][idx] = a;	
		idx++;
	}	
	printf("%d\n", len);
	printf("%s\n", str[0]);
}
