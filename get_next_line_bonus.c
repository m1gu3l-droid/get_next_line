/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnovais- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:25:53 by fnovais-          #+#    #+#             */
/*   Updated: 2022/11/28 18:11:32 by fnovais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*next_line(char *buff)
{
	int		i;
	int		j;
	char	*next;

	i = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	next = (char *)malloc(sizeof(char) * (ft_strlen(buff) - i + 1));
	if (!next)
		return (NULL);
	i++;
	j = 0;
	while (buff[i])
		next[j++] = buff[i++];
	next[j] = '\0';
	free(buff);
	return (next);
}

char	*read_line(int fd, char *buff)
{
	int		reading;
	char	*str;

	str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	reading = 1;
	while (!ft_strchr(buff, '\n') && reading != 0)
	{
		reading = read(fd, str, BUFFER_SIZE);
		if (reading == -1)
		{
			free(str);
			return (NULL);
		}
		str[reading] = '\0';
		buff = ft_join(buff, str);
	}
	free(str);
	return (buff);
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
//	line = (char *)malloc(sizeof(char) * ft_strlen(buffer[fd]) + 1);
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
