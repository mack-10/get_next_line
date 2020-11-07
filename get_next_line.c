/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 11:40:31 by sujeon            #+#    #+#             */
/*   Updated: 2020/11/07 18:58:49 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define	SIZE 100

#include <fcntl.h>	//open
#include <stdio.h>	//printf

static int	cnt_len(char *str)
{
	int len;

	len = 0;
	while (*str)
	{
		if (*str == '\n')
			break ;
		str++;
		len++;
	}
	return (len);
}

static int	cnt_str(char *str)
{
	int cnt;

	cnt = 0;
	while (*str)
	{
		if (*str == '\n')
			cnt++;
		str++;
	}
	cnt++;
	return (cnt);
}

int			get_next_line(int fd, char **line)
{
	static int	idx;
	char		str[SIZE];
	int			cnt;
	char *tmp;

	cnt = 0;
	tmp = str;
	if (!idx)
	{
		if (read(fd, str, SIZE) < 0)
			return (0);
		cnt = cnt_str(str);
		if (!(line = (char **)malloc(sizeof(char *) * cnt + 1)))
			return (0);
	}
	printf("\nidx: %d\n", idx);
	cnt = 0;
	while (idx != cnt)
	{
		tmp = ft_strchr(str, '\n');
		tmp++;
		cnt++;
	}
	printf("tmp: %s\n", tmp);
	cnt = cnt_len(tmp);
	printf("cnt: %d\n", cnt);
	if (!(line[idx] = ft_substr(tmp, 0, cnt)))
		return (0);
	printf("line[idx]: %s\n", line[idx]);
	idx++;
	return (1);
}

int main()
{
	int		fd;
	char	**line;
	int		i = 5;

	line = 0;
	fd = open("test", O_RDONLY);
	while (i--)
		get_next_line(fd, line);
	
}
