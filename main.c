#include "libft.h"
#include "get_next_line.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int fd1;
	int fd2;
	char *line;
	int value;

	fd1 = open("file1.txt", O_RDONLY);
	fd2 = open("file2.txt", O_RDONLY);
	if (argc == 1)
	{
		ft_putstr_fd("usage : ./test_gnl xFiles\n", 1);
		return (0);
	}
	else if (fd1 == -1 || fd2 == -1)
	{
		ft_putstr_fd("erreur d'ouverture de fichier\n", 2);
		return (0);
	}

	value = get_next_line(fd1, &line);
	printf("%d : %s\n", value, line);
	value = get_next_line(fd1, &line);
	printf("%d : %s\n", value, line);
	return (0);
}
