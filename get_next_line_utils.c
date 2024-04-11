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
//y aparte deberia de unir cada str que lea; aparte debe de hacer otra reserva
//nueva de memoria (para las dos str que se van a unir) para poder unirlas
char   *get_next_line(int fd)
{
	static char	*mark;
	char		*lecture;
	char		*chr_checker;
	int			i;
	char		*mem_res;

	lecture = ft_read(fd);
	chr_checker = ft_strchr(lecture, '\n');
	i = 0;
	while (lecture)
	{
		if (chr_checker[i] == '\n')
		{
			mark = chr_checker;
			mem_res = ft_strdup(mark);

		}
		else
		{
			mem_res = ft_strdup(lecture);
			return (mem_res);
		}
	}
}


//Esta funcion principalmente lee, pero tambien hace una reserva de memoria
//para poder guardar la str leida del numero de caracteres del BUFFER_SIZE
//Devuelve la reserva de memoria con el str copiado
// ! Falta hacer la liberacion de memoria *No se si se hace arriba en
// ! get_next_line*
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
		while (buff[i] != '\0')
		{
			reserv[i] = buff[i];
			i++;
		}
		return (reserv);
    }
}

//Esto detecta el caracter que le pasemos. Que en nuestro caso es el
//salto de linea;
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

//Duplica la str en el sitio asignado, en este caso será usado para
//duplicar la str si no encuentra el salto de linea
char	*ft_strdup(const char *s1)
{
	char	*d;
	size_t	l;
	size_t	i;

	i = 0;
	l = ft_strlen(s1);
	d = malloc(l + 1);
	if (d == '\0')
		return (NULL);
	while (i < l && s1[i])
	{
		d[i] = s1[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

// Esta la utilizare para despues de guardar el puntero del salto
// de linea en la estatica, siga leyendo y con el strjoin pueda unir
// ambas str con el salto de linea
// ? No si si realmente voy bien encaminada pero espero que si vaya bien
// ? Because if not i'm going to fvckin cry
char	*ft_getgoing(int fd)
{
	
}