#include "get_next_line.h"

int	main(int ac, char **av)
{
	int		fd;
	char	*s2;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			printf("Error\n");
		while ((s2 = get_next_line(fd)))
		{
			printf("%s\n", s2);
		}
		close(fd);
	}
	return (0);
}
