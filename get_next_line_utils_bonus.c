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

#include "get_next_line_bonus.h"

char	*ft_cpy(char *s1)
{
	int		i;
	char	*line_cpy;

	i = 0;
	if (!s1[i])
		return (NULL);
	while (s1[i] && s1[i] != '\n')
		i++;
	line_cpy = (char *)malloc((i + 2) * sizeof(char));
	if (!line_cpy)
		return (NULL);
	i = 0;
	while (s1[i] && s1[i] != '\n')
	{
		line_cpy[i] = s1[i];
		i++;
	}
	if (s1[i] == '\n')
	{
		line_cpy[i] = s1[i];
		i++;
	}
	line_cpy[i] = '\0';
	return (line_cpy);
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
	char	*new_s1;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	new_s1 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (new_s1 == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s1)
		while (s1[++i] != '\0')
			new_s1[i] = s1[i];
	while (s2[j] != '\0')
		new_s1[i++] = s2[j++];
	new_s1[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	free(s1);
	return (new_s1);
}

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c] != '\0')
		c++;
	return (c);
}
