/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:17:11 by chomobon          #+#    #+#             */
/*   Updated: 2024/08/07 15:03:30 by chomobon         ###   ########.fr       */
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

char	*ft_strdup(char *s1)
{
	char	*d;
	size_t	l;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	l = ft_strlen(s1);
	d = malloc(l + 1);
	if (!d)
		return (NULL);
	while (i < l && s1[i])
	{
		d[i] = s1[i];
		i++;
	}
	d[i] = '\0';
	return (d);
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substr;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
