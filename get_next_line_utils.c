/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 17:17:56 by sujeon            #+#    #+#             */
/*   Updated: 2020/11/20 17:49:25 by sujeon           ###   ########.fr       */
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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t idx1;
	size_t idx2;
	size_t dst_len;
	size_t src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	idx1 = dst_len;
	idx2 = 0;
	while (src[idx2] && idx1 + idx2 + 1 < size)
	{
		dst[idx1 + idx2] = src[idx2];
		idx2++;
	}
	if (dst_len > size)
		return (src_len + size);
	else
	{
		dst[idx1 + idx2] = 0;
		return (src_len + dst_len);
	}
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*new_str;

	if (!s1)
		s1_len = 0;
	else
		s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(new_str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
	ft_strlcpy(new_str, s1, s1_len + 1);
	ft_strlcat(new_str + s1_len, s2, s2_len + 1);
	return (new_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *str;

	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
