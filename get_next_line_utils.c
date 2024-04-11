/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 09:08:34 by marvin            #+#    #+#             */
/*   Updated: 2024/04/09 09:08:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//Aqui simplemente deberia de llamar en un bucle a la funcion de lectura y 
//
char   *get_next_line(int fd)
{
	char	*lecture;

	lecture = ft_read(fd);
}


//Esta funcion principalmente lee, pero tambien hace una reserva de memoria
//para poder guardar la str leida del numero de caracteres del BUFFER_SIZE
//Devuelve la reserva de memoria con el str copiado
// ! Falta hacer la liberacion de memoria
char    *ft_read(int fd)
{
    char	*buff;
    char    *reserv;
    char    *nbyte;
	int		count_wd;
	int		i;

	count_wd = 0;
	reserv = calloc(buff, 1);
    while (count_wd <= BUFFER_SIZE)
    {
		count_wd = read(fd, buff, BUFFER_SIZE);
		if (!count_wd)
			return (null);
    }
	while (buff[i] != '\0')
	{
		reserv[i] = buff[i];
		i++;
	}
	return (reserv);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != (char)c)
	{
		s++;
	}
	if (*s == (char)c)
	{
		return ((char *)(s));
	}
	return (NULL);
}

int main()
{
	ft_read
}
