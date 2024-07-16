/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:04:22 by chomobon          #+#    #+#             */
/*   Updated: 2024/07/16 15:49:44 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* char    *ft_read(int fd, char *reserv)
{
    char    *buff;
    //char    *line;
    int     count_wd;

    buff = malloc(BUFFER_SIZE + 1);
    if (!buff)
        return(NULL);
    if (BUFFER_SIZE <= 0)
        return(NULL);
    count_wd = 1;
    
    while (reserv && !ft_strchr(reserv, '\n')) //&& count_wd < 0
    {
        printf("entraaaaaaaaaaaa\n");
        count_wd = read(fd, buff, BUFFER_SIZE);
        if (count_wd == -1)
            return(NULL);
        buff[count_wd] = '\0';
        reserv = ft_strjoin(reserv, buff);
        //printf("line: %s\n", line);
        printf("buff: %s\n", buff);
        printf("reserv: %s\n", reserv);
        break;
    }
    return (reserv);
} */

char    *get_next_line(int fd)
{
    static char *reserv;
    char    *line;
    char    *buff;
    char    *sub_str;
    int     i;
    char    *aux;

    buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
    reserv = ft_strdup("");
    if(!buff)
        return(NULL);
    while (!ft_strchr(buff, '\n'))
    {
        i = read(fd, buff, BUFFER_SIZE);
        if (i <= 0)
        {            
            free(buff);
            return(NULL);
        }
        // printf("BUFF: %s\n", buff);
        // printf("AAA: %s\n",ft_strchr(buff, '\n'));
        buff[i] = '\0';
        //aux = ft_strdup(reserv);
        //printf("aux: %s\n", aux);
        reserv = ft_strjoin(reserv, buff);
        // printf("esto es reserv: %s\n", reserv);
        //free(aux);
        // printf("hola bucle");
        //free(buff);
        line = ft_strchr(reserv, '\n');
        sub_str = ft_substr(reserv, 0, ft_strlen(reserv) - ft_strlen(line));
        buff = reserv;
        reserv = ft_strdup(line);
        free(buff);
        return(sub_str);
    }
    


        
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
    //char *str = ft_read(op);
    //printf("Lo del archivo: %s\n", str);
    while ((line = get_next_line(fd)) != NULL)
    {
        // printf("entra bucle");
        printf("%s", line);
        free(line);
        // break;
    }
    close(fd);
    return (0);
}