/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:04:22 by chomobon          #+#    #+#             */
/*   Updated: 2024/07/19 17:58:38 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_place_static(char *str)
{
	char	*position;
	int		len;

	position = 0;
	len = ft_strlen(ft_strchr(str, '\n'));
	if (len != 0)
		position = ft_substr(ft_strchr(str, '\n'), 0, len);
	else if (len == 0)
		position = 0;
	return (position);
}

//Esta funcion separa la linea una vez encontrado el salto de linea
char	*ft_line(char *str)
{
	char	*line;
	int		len;
	int		breakline;

	line = 0;
	len = ft_strlen(str);
	if (!ft_strchr(str, '\n') && len > 0)
		line = ft_substr(str, 0, len);
	else if (len > 0)
	{
		breakline = ft_strlen(ft_strchr(str, '\n'));
		line = ft_substr(str, 0, len - breakline);
	}
	return (line);
}

// Esta funcion es solo de lectura, y para ir almacenando las lecturas
char	*ft_read(int fd, char *reserv)
{
	char	*buff;
	int		verify;
	char	*aux;
	char	*keeper;

	verify = 1;
	aux = ft_substr(reserv, 0, ft_strlen(reserv));
	while (!ft_strchr(buff, '\n') && verify != 0)
	{
		buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buff)
			return (free (reserv), NULL);
		verify = read(fd, buff, BUFFER_SIZE);
		if (verify <= 0)
			return (free (buff), free(reserv), NULL);
		buff[verify] = '\0';
		keeper = aux;
		aux = ft_strjoin(aux, buff);
		free(keeper);
		free(aux);
	}
	return (free(buff), reserv);
}

char	*get_next_line(int fd)
{
	static char	*reserv;
	char		*aux;
	char		*line;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	aux = ft_read(fd, reserv);
	if (!aux)
	{
		if (reserv)
		{
			free(reserv);
			reserv = 0;
		}
		return (NULL);
	}
	line = ft_line(aux);
	if (!line && reserv)
		return (free (reserv), NULL);
	reserv = ft_place_static(aux);
	free(aux);
	return (line);
}

int main()
{
	char *line;
	int fd = open("a.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}