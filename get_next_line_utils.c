/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:26:18 by fnovais-          #+#    #+#             */
/*   Updated: 2022/11/22 15:45:24 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;

	str = malloc(nmemb * size);
	if (!str)
		return (NULL);
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	d;

	d = 0;
	if (!dst || size == 0)
		return (ft_strlen(src));
	if (!src)
		return (0);
	if (size != 0)
	{
		while (d < size -1 && src[d] != '\0')
		{
			dst[d] = src[d];
			d++;
		}
	}
	dst[d] = '\0';
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	index;

	index = 0;
	if ((!dst || !src) && size == 0)
		return (0);
	dst_len = ft_strlen(dst);
	if (size <= dst_len)
		return (ft_strlen(src) + size);
	while (src[index] && dst_len + 1 < size)
		dst[dst_len++] = src[index++];
	dst[dst_len] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[index]));
}

size_t	ft_strlen(const char *s)
{
	size_t	c;

	c = 0;
	while (s[c] != '\0')
		c++;
	return (c);
}
