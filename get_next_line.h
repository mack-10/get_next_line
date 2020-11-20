/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 11:43:44 by sujeon            #+#    #+#             */
/*   Updated: 2020/11/20 17:24:12 by sujeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//1 필수
#include <unistd.h>	//write, read
#include <stdlib.h>	//malloc, free
#include <stddef.h>	//size_t

//2 제출시 제거
#include <fcntl.h>	//open
#include <stdio.h>	//printf
#define BUFFER_SIZE 3

int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *str);
size_t  	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	    ft_strlcat(char *dst, const char *src, size_t size);
char    	*ft_strjoin(char *s1, char const *s2);
char	    *ft_substr(char const *s, unsigned int start, size_t len);

#endif