/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeon <sujeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 11:43:44 by sujeon            #+#    #+#             */
/*   Updated: 2020/11/16 21:25:22 by sujeon           ###   ########.fr       */
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
#define BUFFER_SIZE 32

int			get_next_line(int fd, char **line);
size_t		ft_strlen(const char *str);
char		*ft_strchr(const char *s, int c);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
void		*ft_memset(void *b, int c, size_t len);

#endif