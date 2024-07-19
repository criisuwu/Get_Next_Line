/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chomobon <chomobon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 11:17:11 by chomobon          #+#    #+#             */
/*   Updated: 2024/07/19 15:23:39 by chomobon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
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
	if (str == NULL)
		return (0);
	while (str[x] != '\0')
	{
		x++;
	}
	return (x);
}

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*r;

	if (!s1 || !s2)
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
