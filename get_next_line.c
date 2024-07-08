/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:04:22 by chomobon          #+#    #+#             */
/*   Updated: 2024/07/08 11:03:50 by chomobon         ###   ########.fr       */
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

    while (buff[i] != '\0' || buff[i] != '\n') //Es un contador para reservar memoria a devolver
    {
        //Hasta que no encuetres un \n no devuelvas nada y hay que concat los caracteres
        //Todo: ver cuanta memoria necesito reservar
        //Probar buff 1 
        /*reserv[i] = buff[i];*/
        //printf("resv: %s\n", reserv);
        i++;
    }
    if (buff[i] == '\n')
        i++;
    reserv = malloc(i + 1);
    if (!reserv)
        return (NULL);
    return (reserv);
    
}

/* char	*ft_strjoin(const char *s1, const char *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*r;

	if (!s1 && !s2)
		return (NULL);
	r = ((char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!r)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		r[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		r[i + j] = s2[j];
		j++;
	}
	r[i + j] = '\0';
	return (r);
} */



int main ()
{
    int op = open("a.txt", O_RDONLY);
    //char *str = ft_read(op);
    //printf("Lo del archivo: %s\n", str);
    char *str2 = get_next_line(op);
}