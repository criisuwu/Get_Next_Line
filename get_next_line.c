/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:04:22 by chomobon          #+#    #+#             */
/*   Updated: 2024/07/08 12:39:31 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_read(int fd)
{
    static char *reserv;
    char        *buff;
    char        *line;
    int         count_wd;
    int         i;

    i = 0;
    buff = malloc(BUFFER_SIZE + 1);
    if (!buff)
        return(NULL);
    if (BUFFER_SIZE <= 0)
        return(NULL);
    count_wd = 1;
    while (!ft_strchr(buff, '\n') && count_wd < 0)
    {
        //Hasta que no encuetres un \n no devuelvas nada y hay que concat los caracteres
        //Todo: ver cuanta memoria necesito reservar
        //Probar buff 1 
        /*reserv[i] = buff[i];*/
        //printf("resv: %s\n", reserv);
        
        count_wd = read(fd, buff, BUFFER_SIZE);
        if (count_wd == -1)
            return(NULL);
        line = ft_strjoin(line, buff);
        //leer otra vez
        //concant
        
    }
    reserv = malloc(i + 1);
    if (!reserv)
        return (NULL);
    if (buff[i] == '\n')
    {
        i++;
        reserv = buff;
    }
    return (reserv);
}

char    *get_next_line(int fd)
{
    static char *new_line;
    char *str;

    str = ft_read(fd);
    new_line = ft_strchr(str, '\n');
    
    printf("This is str: %s\n" , str);
    printf("This is new_line: %s\n" ,new_line);
    return(new_line);
}

int main ()
{
    int op = open("a.txt", O_RDONLY);
    //char *str = ft_read(op);
    //printf("Lo del archivo: %s\n", str);
    char *str2 = get_next_line(op);
}