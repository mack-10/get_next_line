/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 11:40:31 by sujeon            #+#    #+#             */
/*   Updated: 2020/11/20 14:33:20 by sujeon           ###   ########.fr       */
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

static void		free_line(char *str)
{
	free(str);
	str = NULL;
}

static void		if_backup(char *backup, char **line)
{
	int len;

	len = cnt_len(backup);
	if (!(*line = (char *)malloc(sizeof(char) * len + 1)))
	{
		free_line(*line);
		return (-1);
	}
	ft_strlcpy(*line, backup, len + 1);
	}
}

int				get_next_line(int fd, char ***line)
{
	static char	*backup;
	char		*src;
	int			loc;
	int 		len;
	int			n;

	loc = 0;
	if (backup)
		if_backup(backup, line);
	while (1)
	{
		if (!(src = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
			return (-1);
		ft_memset(src, '\0', BUFFER_SIZE + 1);
		if ((n = read(fd, src, BUFFER_SIZE)) < 0)
			return (-1);
		len = cnt_len(src);
		if (!((*line + loc) = (char *)malloc(sizeof(char) * (len + 1))))
		{
			free_line(*line);
			return (-1);
		}
		ft_strlcpy(*line + loc, src, len + 1);
		if (ft_strchr(src, '\n'))
		{
			backup = ft_strchr(src, '\n') + 1;
			break ;
		}
		else
			loc += BUFFER_SIZE + 1;
	}
	if (!n)
		return (0);
	else
		return (1);
}