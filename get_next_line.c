/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 11:40:31 by sujeon            #+#    #+#             */
/*   Updated: 2020/11/16 17:37:45 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

int			get_next_line(int fd, char **line)
{
	static char	*backup;
	char		*src;
	int 		len;

	len = 0;
	if (!backup)
	{
		if (!(src = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (0);
		ft_memset(src, 0, BUFFER_SIZE + 1);
		if (read(fd, src, BUFFER_SIZE) < 0)
			return (-1);
		printf("after read : %s\n", src);
		len = cnt_len(src);
		printf("len : %d\n", len);
		if (!(*line = (char *)malloc(sizeof(char) * len + 1)))
			return (0);
		ft_strlcpy(*line, src, len + 1);
		backup = ft_strchr(src, '\n') + 1;
	}		
	else
	{
		len = cnt_len(backup);
		printf("len : %d\n", len);
		if (!(*line = (char *)malloc(sizeof(char) * len + 1)))
			return (0);
		ft_strlcpy(*line, backup, len + 1);
		if (backup)
			backup = ft_strchr(backup, '\n') + 1;
	}
	return (1);
}
