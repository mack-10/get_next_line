#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd;
	char src[100];
	int index = -1;
	
	fd = open("test.txt", O_RDONLY);
	read(fd, src, 100);

	while(src[++index])
	{
		if (src[index] == '\n')
			printf("catch!!\n");
	}
	printf("src: %s\n", src);
}