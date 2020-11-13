/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 11:40:31 by sujeon            #+#    #+#             */
/*   Updated: 2020/11/13 15:49:57 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*backup;
	char		*src;
	int 		len;

	len = 0;
	if (!(src = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (0);
	ft_memset(src, '\0', BUFFER_SIZE + 1);
	read(fd, src, BUFFER_SIZE);
	len = cnt_len(src);
	printf("len : %d\n", len);
	if (!(*line = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	if (!backup)
		ft_strlcpy(*line, src, len + 1);	
	else
		ft_strlcpy(*line, backup, len + 1);	
	backup = ft_strchr(src, '\n') + 1;
	printf("line: %s\n", *line);
	return (1);
}
