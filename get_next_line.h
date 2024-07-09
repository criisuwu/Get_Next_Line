/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:08:05 by chomobon          #+#    #+#             */
/*   Updated: 2024/07/09 12:38:01 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1

#endif

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>


char    *get_next_line(int fd);
char    *ft_read(int fd, char *reserv);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *s1);
int	     ft_strlen(const char *str);
char	*ft_strjoin(const char *s1, const char *s2);

#endif