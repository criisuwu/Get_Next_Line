/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:17:11 by chomobon          #+#    #+#             */
/*   Updated: 2024/07/04 15:47:30 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char *reserv;
	int i;
	int it;
	int count;

	it = 0;
	//i = (ft_strlen((char *) s) - count);
	count = 0;
	while (*s != '\0' && *s != (char)c)
	{
		//reserv[i] = s[i];
		//printf("str del strchr: %s\n", reserv);
		//printf("s del strchr: %s\n", s);
		//i++;
		//printf("iterador: %d\n", i);
		s++;
		count++;
		//printf("idk: %s\n", s);
	}
	if (*s == (char)c)
	{
		i = (ft_strlen((char *)s - count));
		printf("%d\n", i);
		while (i > 0)
			{
				reserv[it] = s[i];
				printf("it:%d\n", it);
				i--;
				printf("i:%d\n", i);
				it++;
			}
		printf("Esto es lo que deberia de imprimir: %s\n", reserv);
		return ((char *)(s));
	}
	return (NULL);
}

/* char	*ft_strdup(char *s1)
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
} */

int	ft_strlen(char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		x++;
	}
	return (x);
}

