/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:26:18 by fnovais-          #+#    #+#             */
/*   Updated: 2022/11/28 17:51:35 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_cpy(char *dst)
{
	int	d;
	char	*str;

	d = 0;
	if (!dst[d])
		return (NULL);
	while (dst[d] && dst[d] != '\n')
		d++;
	str = (char *)malloc((d + 2) * sizeof(char));
	if (!str)
		return (NULL);
	d = 0;
	while (dst[d] && dst[d] != '\n')
	{
		str[d] = dst[d];
		d++;
	}
	if (dst[d] == '\n')
	{
		str[d] = dst[d];
		d++;
	}
	str[d] = '\0';
	return (str);
}

char	*ft_strchr(const char	*s, int c)
{
	size_t		index;

	index = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[index] != c)
	{
		if (s[index] == '\0')
			return (NULL);
		index++;
	}
	return ((char *)s + index);
}

char	*ft_join(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			new[i] = s1[i];
	while (s2[j] != '\0')
		new[i++] = s2[j++];
	new[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (new);
}

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c] != '\0')
		c++;
	return (c);
}
