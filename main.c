#include "libft.h"
#include "get_next_line.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd;
	char *line;
	int value;

	fd = open(argv[argc - 1], O_RDONLY);
	if (argc == 1)
	{
		ft_putstr_fd("usage : ./test_gnl xFiles\n", 1);
		return (0);
	}
	else if (fd == -1)
	{
		ft_putstr_fd("erreur d'ouverture de fichier\n", 2);
		return (0);
	}
	value = get_next_line(fd, &line);
	printf("%s\n", line);
	value = get_next_line(fd, &line);
	printf("%s\n", line);
	value = get_next_line(fd, &line);
	printf("%s\n", line);
	value = get_next_line(fd, &line);
	printf("%s\n", line);
	value = get_next_line(fd, &line);
	printf("%s\n", line);
	value = get_next_line(fd, &line);
	printf("%s\n", line);
	value = get_next_line(fd, &line);
	printf("%s\n", line);
	return (0);
}
