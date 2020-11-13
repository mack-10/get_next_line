/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 11:40:31 by sujeon            #+#    #+#             */
/*   Updated: 2020/11/13 14:55:54 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <fcntl.h>	//open
#include <stdio.h>	//printf

static int	cnt_len(char *str)
{
	int len;

	len = 0;
	while (*str)
	{
		if (!(str = ft_strchr(str, '\n')))
			break ;
		len++;
	}
	return (len);
}

int			get_next_line(int fd, char **line)
{
	char		str[BUFFER_SIZE];

	
}

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
	}		
}
