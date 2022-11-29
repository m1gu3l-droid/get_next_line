/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:25:53 by fnovais-          #+#    #+#             */
/*   Updated: 2022/11/28 18:07:01 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*next_line(char *s1)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	while (s1[i] && s1[i] != '\n')
		i++;
	if (!s1[i])
	{
		free(s1);
		return (NULL);
	}
	next = (char *)malloc(sizeof(char) * (ft_strlen(s1) - i + 1));
	if (!next)
		return (NULL);
	i++;
	j = 0;
	while (s1[i])
		next[j++] = s1[i++];
	next[j] = '\0';
	free(s1);
	return (next);
}

char	*read_line(int fd, char *s1)
{
	int		reading;
	char	*s2;

	s2 = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!s2)
		return (NULL);
	reading = 1;
	while (!ft_strchr(s1, '\n') && reading != 0)
	{
		reading = read(fd, s2, BUFFER_SIZE);
		if (reading == -1)
		{
			free(s2);
			free(s1);
			return (NULL);
		}
		s2[reading] = '\0';
		s1 = ft_join(s1, s2);
	}
	free(s2);
	return (s1);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[4096];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = read_line(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_cpy((char *)buffer[fd]);
	buffer[fd] = next_line(buffer[fd]);
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*s2;

	fd = open("42_with_nl", O_RDONLY);
	if (fd == -1)
		printf("Error\n");
	s2 = get_next_line(fd);
	printf("%s\n", s2);
	s2 = get_next_line(fd);
	printf("%s\n", s2);
	s2 = get_next_line(fd);
	printf("%s\n", s2);
	s2 = get_next_line(fd);
	printf("%s\n", s2);
	s2 = get_next_line(fd);
	printf("%s\n", s2);
	close(fd);
	return (0);
}
*/
