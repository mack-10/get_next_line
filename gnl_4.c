/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 14:45:44 by sujeon            #+#    #+#             */
/*   Updated: 2020/12/02 16:48:35 by sujeon           ###   ########.fr       */
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
	while (src[len])
	{
		if (src[0] == '\n')
			return (1);
		else if (src[len] == '\n')
			return (len);
		len++;
	}
	return (0);
}

static int		put_value(char **line, char *src, char **backup)
{
	int len;
	int idx;

	idx = 0;
	if (src[0] == '\n')
	{
		*line = ft_strdup("");
		if (src[1])
			*backup = ft_strdup(src + 1);
	}
	else
	{
		len = find_n(src);
		if (!len)
			len = ft_strlen(src);
		*line = ft_substr(src, 0, len);
		while (len-- && src[idx])
			idx++;
		if (src[idx])
			*backup = ft_strdup(src + idx + 1);
	}
	free_p(&src);
	return (1);
}

static int		if_end(char **line, char *src, char **backup, int n)
{
	if (n == -1)
		return (-1);
	else if (src)
	{
		put_value(line, src, backup);
		if (!backup)
			return (0);
		return (1);
	}
	else
	{
		*line = ft_strdup("");
		return (0);
	}
	
}

int				get_next_line(int fd, char **line)
{
	static char	*backup[1024];
	char		tmp[BUFFER_SIZE + 1];
	char		*src;
	int			n;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (-1);
	src = NULL;
	if (backup[fd])
	{
		src = ft_strdup(backup[fd]);
		free_p(&backup[fd]);
	}
	while ((n = read(fd, tmp, BUFFER_SIZE)) > 0)
	{
		tmp[n] = 0;
		src = ft_strjoin(src, tmp);
		if (find_n(src))
			return (put_value(line, src, &backup[fd]));
	}
	return (if_end(line, src, &backup[fd], n));
}
