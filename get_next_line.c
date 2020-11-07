/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 11:40:31 by sujeon            #+#    #+#             */
/*   Updated: 2020/11/07 15:21:45 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define	SIZE 100

#include <fcntl.h>	//open
#include <stdio.h>	//printf

int		get_next_line(int fd, char **line)
{
	static int	idx1;
	int			idx2;
	char		tmp[SIZE];
	int 		len;
	int			cnt;

	len = 0;
	cnt = 0;
	idx2 = 0;
	if (!idx1)
	{
		if (read(fd, &tmp, SIZE) < 0)
			return (0);
		//printf("tmp: %s\n", tmp);
		/*if (!(line = (char **)malloc(sizeof(char *) * cnt + 1)))
			return (0);*/
	}
	/*
	while (line[idx1][idx2] != '\n' && line[idx1][idx2])
	{
		line[idx1][idx2] = *tmp;
		idx2++;
		tmp++;
	}
	printf("len: %d\n", len);
	if (!(line[idx1] = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	*/
}

int main()
{
	int		fd;
	char	**line;

	fd = open("test", O_RDONLY);
	get_next_line(fd, line);
	while (1)
		;
}
