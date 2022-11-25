/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   old_get_next_line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:25:36 by fnovais-          #+#    #+#             */
/*   Updated: 2022/11/25 00:00:37 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join(char const *s1, char const *s2)
{
	char	*new;
	size_t	size;

	if (!s1 || !s2)
		return ("aqui");
	size = (ft_strlen(s1) + ft_strlen(s2) + 1);
	new = malloc(sizeof(char) * size);
	if (!new)
		return (NULL);
	ft_strlcpy((void *)new, (const void *)s1, size);
	ft_strlcat(new, s2, size);
	return (new);
}

char	*new_l(char *buff)
{
	int		i;
	int		j;
	char	*str;
	char	*new;

	i = 0;
	j = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
		{
			str = ft_calloc(1, (sizeof(char *) * i + 1));
			new = ft_calloc(1, (sizeof(char *) * i + 1));
			new = ft_join((char const *)new, (char const *)buff);
			ft_strlcpy(str, (const char *)buff, i + 1);
			return (str);
		}
		i++;
	}
	return (NULL);
}

char	*where(char *buff)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	if (!buff)
		return (NULL);
	while (buff && buff[i] != '\n')
		i++;
	str = malloc(sizeof(char) * ((ft_strlen(buff) - i) + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (buff[i])
	{
		str[j++] = buff[i++];
	}
	str[j] = '\0';
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	int			reading;
	char		*join_buf;
	static char	*buf1;

	buf1 = malloc(sizeof(char) * BUFFER_SIZE);
	reading = read(fd, buf1, BUFFER_SIZE);
	while (reading > 0)
	{
		if (!(new_l(buf1)))
		{
			join_buf = ft_join((const char *)join_buf, (const char *)(buf1));
			reading = read(fd, buf1, BUFFER_SIZE);
		}
		else
		{
			join_buf = ft_join((const char *)join_buf, \
			(const char *)(new_l(buf1)));
			buf1 = where(buf1);
			return (join_buf);
		}
	}
	return (NULL);
}

int	main(void)
{
	int		fd;
	char	*s2;

	fd = open("criacao.txt", O_RDONLY);
	if (fd == -1)
		printf("Error\n");
	s2 = get_next_line(fd);
	printf("%s\n", s2);
	s2 = get_next_line(fd);
	printf("%s\n", s2);
	s2 = get_next_line(fd);
	printf("%s\n", s2);
	close(fd);
	return (0);
}
