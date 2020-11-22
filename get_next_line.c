/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:45:44 by sujeon            #+#    #+#             */
/*   Updated: 2020/11/22 15:46:32 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			free_p(char *p)
{
	free(p);
	p = NULL;
}

static int		find_n(char *src)
{
	int len;

	len = 0;
	while (src[len])
	{
		if (src[len] == '\n')
			return (len);
		len++;
	}
	return (0);
}

static int		put_value(char **line, char *src, char **backup)
{
	int len;

	len = find_n(src);
	if (!len)
		len = ft_strlen(src);
	*line = ft_substr(src, 0, len);
	if (*(src + len + 1))
		*backup = ft_strdup(src + len + 1);
	free_p(src);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char	*backup[1024];
	char		tmp[BUFFER_SIZE + 1];
	char		*src;
	int			n;

	src = NULL;
	if (backup[fd])
	{
		src = ft_strdup(backup[fd]);
		free_p(backup[fd]);
	}
	while ((n = read(fd, tmp, BUFFER_SIZE)) > 0)
	{
		tmp[n] = 0;
		src = ft_strjoin(src, tmp);
		if (find_n(src) && n)
			return (put_value(line, src, &backup[fd]));
	}
	put_value(line, src, &backup[fd]);
	return (0);
}
