/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 20:15:16 by sujeon            #+#    #+#             */
/*   Updated: 2020/12/07 20:15:20 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int len;

	len = 0;
	if (!str)
		return (0);
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

char	*ft_strdup(char *s)
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

char	*ft_strjoin(char *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*new_str;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (!(new_str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1))))
		return (0);
	ft_strlcpy(new_str, s1, s1_len + 1);
	ft_strlcpy(new_str + s1_len, s2, s2_len + 1);
	if (s1)
		free_p(&s1);
	return (new_str);
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
