/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 17:17:56 by sujeon            #+#    #+#             */
/*   Updated: 2020/11/07 18:09:32 by sujeon           ###   ########.fr       */
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

char	*ft_strdup(const char *s)
{
	int		size;
	int		idx;
	char	*new_str;

	idx = 0;
	size = ft_strlen(s);
	if (!(new_str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (idx < size)
	{
		new_str[idx] = s[idx];
		idx++;
	}
	new_str[idx] = 0;
	return (new_str);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *str;

	if (!s || ft_strlen(s) <= (size_t)start)
		return (ft_strdup(""));
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
