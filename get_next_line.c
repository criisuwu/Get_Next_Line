/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:04:22 by chomobon          #+#    #+#             */
/*   Updated: 2024/07/19 13:08:50 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_line(char *str)
{
    
}
// Esta funcion es solo de lectura, y para ir almacenando las lecturas
char *ft_read(int fd, char *reserv)
{
    char    *buff;
    int     verify;
    char    *aux;
    char    *keeper;

    verify = 1;
    aux = ft_substr(reserv, 0, ft_strlen(reserv));
    while(!ft_strchr(buff, '\n') && verify > 0)
    {
        buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
        if(!buff)
            return (NULL);
        verify = read(fd, buff, BUFFER_SIZE);
        if (verify <= 0)
            return (free (buff), free(reserv), NULL);
        buff[verify] = '\0';
        keeper = aux;
        aux = ft_strjoin(aux, buff);
        free(keeper);
        free(aux);
        // printf("buff: %s\n", buff);
        // printf("reserv: %s\n", reserv);
        // printf("aux: %s\n", aux);
    }
    return (free (buff), reserv);
}

char    *get_next_line(int fd)
{
    static char *reserv;
    char    *line;
    char    *sub_str;
    char    *aux;

    if (fd <= 0 || BUFFER_SIZE <= 0)
        return (NULL);
    reserv = ft_read(fd, reserv);
    if (!aux)
        return (NULL);
    line = ft_strchr(reserv, '\n');
    printf("line: %s\n", line);
    sub_str = ft_substr(reserv, 0, ft_strlen(reserv) - ft_strlen(line));
    printf("sub_str: %s\n", sub_str);
    return (sub_str);

    /* while (!ft_strchr(buff, '\n') && i > 0)
    {
        line = ft_strchr(reserv, '\n');
        sub_str = ft_substr(reserv, 0, ft_strlen(reserv) - ft_strlen(line));
        buff = reserv;
        printf("buff: %s\n", buff);
        reserv = line;
        aux = sub_str;
        sub_str = ft_strjoin(aux, reserv);
        free(aux);
        printf("sub_str: %s\n", sub_str);
        printf("reserv: %s\n", reserv);
    }
    return(sub_str);
     */


        
/*         line = ft_strdup(ft_strchr(buff, '\n'));
        sub_str = buff;
        if(line)
        {
            sub_str = ft_substr(buff, 0, ft_strlen(buff) - ft_strlen(line));
        }
    
    free(buff);
    free(sub_str);
    sub_str = ft_strdup(reserv);
    reserv = ft_strdup(line);
    printf("%s\n", sub_str); */
    // if (!reserv)
    // {
    //     reserv = malloc(BUFFER_SIZE +1);
    //     {
    //         if (!reserv)
    //             return (NULL);
    //         reserv[0] = '\0';
    //     }
    // }
    // line = ft_read(fd, reserv);
    // line = ft_strchr(line, '\n');
    
    // printf("This is str: %s\n" , str);
    // printf("This is new_line: %s\n" ,new_line);
    // printf("%s esto es mi reserv", reserv);
    // return(reserv);
}

int main ()
{
    char *line;
    int fd = open("a.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        // printf("entra bucle");
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}