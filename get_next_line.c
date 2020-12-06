/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 02:17:24 by sujeon            #+#    #+#             */
/*   Updated: 2020/12/06 02:28:13 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void			free_p(char **p)
{
	free(*p);
	*p = NULL;
}

static int		find_n(char *src)
{
	int len;

	len = 0;
	if (src[0] == '\n')
		return (1);
	while (src[len])
	{
		if (src[len] == '\n')
			return (len);
		len++;
	}
	return (0);
}

static int		last_line(char **line, char **backup)
{
	int len;

	len = ft_strlen(*backup);
	*line = ft_substr(*backup, 0, len);
	free_p(backup);
	return (0);
}

static int		put_line(char **line, char **backup)
{
	int		len;
	char	*src;

	len = find_n(*backup);
	if (!len)
		return (last_line(line, backup));
	src = ft_strdup(*backup);
	free_p(backup);
	if (src[0] == '\n')
	{
		*line = ft_strdup("");
		if (src[1])
			*backup = ft_strdup(src + 1);
	}
	else
	{
		*line = ft_substr(src, 0, len);
		if (src[len] == '\n')
			*backup = ft_strdup(src + len + 1);
	}
	free_p(&src);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char	*backup[1024];
	char		src[BUFFER_SIZE + 1];
	int			n;

	while ((n = read(fd, src, BUFFER_SIZE)) > 0)
	{
		src[n] = 0;
		backup[fd] = ft_strjoin(backup[fd], src);
		if (find_n(backup[fd]))
			return (put_line(line, &backup[fd]));
	}
	if (n == -1)
		return (-1);
	if (backup[fd])
		return (put_line(line, &backup[fd]));
	else
	{
		*line = ft_strdup("");
		return (0);
	}
}
