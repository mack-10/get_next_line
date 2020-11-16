/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 17:17:56 by sujeon            #+#    #+#             */
/*   Updated: 2020/11/16 21:23:09 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	int idx;

	idx = 0;
	while (s[idx])
	{
		if (s[idx] == (char)c)
			return ((char *)s + idx);
		idx++;
	}
	if (s[idx] == (char)c)
		return ((char *)s + idx);
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		idx;
	size_t		src_len;

	if (!src)
		return (0);
	src_len = ft_strlen(src);
	idx = 0;
	if (!size || !src)
		return (src_len);
	while (idx + 1 < size && src[idx])
	{
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = 0;
	return (src_len);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		*((unsigned char *)b + i) = c;
		i++;
	}
	return (b);
}
