/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:04:22 by chomobon          #+#    #+#             */
/*   Updated: 2024/07/04 13:55:05 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static char *new_line;
    char *str;

    str = ft_read(fd);
    new_line = ft_strchr(str, '\n');
    
    printf("This is str: %s\n" , str);
    printf("This is new_line: %s\n" ,new_line);
}

char    *ft_read(int fd)
{
    char    *reserv;
    char    *buff;
    int     count_wd;
    int     i;

    i = 0;
    buff = malloc(BUFFER_SIZE + 1);
    if (!buff)
        return(NULL);
    count_wd = read(fd, buff, BUFFER_SIZE);
    reserv = malloc(ft_strlen(buff) + 1);
    if (!reserv)
        return (NULL);
    while (buff[i] != '\0')
    {
        reserv[i] = buff[i];
        i++;
    }
    return (reserv);
    
}

int main ()
{
    int op = open("a.txt", O_RDONLY);
    //char *str = ft_read(op);
    //printf("Lo del archivo: %s\n", str);
    char *str2 = get_next_line(op);
}