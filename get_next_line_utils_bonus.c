/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 10:09:50 by codespace         #+#    #+#             */
/*   Updated: 2024/09/27 10:09:52 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s || !s[0])
		return (NULL);
	while (*s != '\0')
	{
		s++;
		if (*s == (char)c)
			return ((char *)(s));
	}
	if ((char) c == '\0')
		return ((char *) s);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	int	x;

	x = 0;
	if (!str || !str[x])
		return (0);
	while (str[x])
		x++;
	return (x);
}

char	*ft_strjoin(char *first_str, char *buf)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!first_str)
	{
		first_str = (char *)malloc(1 * sizeof(char) + 1);
		if (!first_str || !buf)
			return (NULL);
		first_str[0] = '\0';
	}
	str = malloc(sizeof(char) * ((ft_strlen(first_str) + ft_strlen(buf)) + 2));
	if (!str)
		return (free(first_str), NULL);
	i = -1;
	j = 0;
	if (first_str)
		while (first_str[++i] != '\0')
			str[i] = first_str[i];
	while (buf[j] != '\0')
		str[i++] = buf[j++];
	str[i++] = '\0';
	return (free(first_str), str);
}
