/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:04:22 by chomobon          #+#    #+#             */
/*   Updated: 2024/08/06 19:21:14 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_place_static(char *str)
{
	char	*position;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (free(str), NULL);
	position = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!position)
		return (free(str), NULL);
	i++;
	j = 0;
	while (str[i])
		position[j++] = str[i++];
	position[j] = '\0';
	return (free(str), position);
}

//Esta funcion separa la linea una vez encontrado el salto de linea
char	*ft_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		line = (char *)malloc(sizeof(char) * (i + 2));
	else
		line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

// Esta funcion es solo de lectura, y para ir almacenando las lecturas
char	*ft_read(int fd, char *reserv)
{
	char	*buff;
	int		verify;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (free (reserv), NULL);
	while (!ft_strchr(reserv, '\n') && !ft_strchr(reserv, '\0'))
	{
		verify = read(fd, buff, BUFFER_SIZE);
		if (verify <= 0)
			return (free (buff), free(reserv), NULL);
		buff[verify] = '\0';
		reserv = ft_strjoin(reserv, buff);
		reserv[ft_strlen(reserv) + 1] = '\n';
	}
	return (free(buff), reserv);
}

char	*get_next_line(int fd)
{
	static char	*reserv;
	char		*line;

	if (fd <= 0 && BUFFER_SIZE <= 0)
		return (NULL);
	reserv = ft_read(fd, reserv);
	if (!reserv)
		return (NULL);
	line = ft_line(reserv);
	if (!line)
		return (free (reserv), reserv = NULL);
	reserv = ft_place_static(reserv);
	return (line);
}

int main()
{
	char *line;
	int fd = open("43_no_nl.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}