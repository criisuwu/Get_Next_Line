/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:04:22 by chomobon          #+#    #+#             */
/*   Updated: 2024/07/09 13:02:15 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_read(int fd, char *reserv)
{
    char        *buff;
    int         count_wd;
    int         i;

    i = 0;
    buff = malloc(BUFFER_SIZE + 1);
    if (!buff)
        return(NULL);
    if (BUFFER_SIZE <= 0)
        return(NULL);
    count_wd = 1;
    while (reserv && !ft_strchr(reserv, '\n') && count_wd < 0)
    {
        printf("entra\n");
        //Todo: ver cuanta memoria necesito reservar
        //Probar buff 1 
        
        count_wd = read(fd, buff, BUFFER_SIZE);
        if (count_wd == -1)
            return(NULL);
        buff[count_wd] = '\0';
        reserv = ft_strjoin(reserv, buff);
        if (reserv[count_wd] == '\0')
            reserv == NULL;
        printf("%s\n", reserv); 
    }
    return (reserv);
}

char    *get_next_line(int fd)
{
    static char *reserv;
    char *str;

    if (!reserv)
    {
        reserv = malloc(1);
        {
            if (!reserv)
                return (NULL);
            reserv[0] = '\0';
        }
    }
    reserv = ft_read(fd, reserv);
    str = ft_strchr(str, '\n');
    
    // printf("This is str: %s\n" , str);
    // printf("This is new_line: %s\n" ,new_line);
    return(reserv);
}

int main ()
{
    char *line;
    int fd = open("a.txt", O_RDONLY);
    //char *str = ft_read(op);
    //printf("Lo del archivo: %s\n", str);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}