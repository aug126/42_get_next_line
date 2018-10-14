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
	int ret;

	fd = open("file1.txt", O_RDONLY);

	while ((ret = get_next_line(fd, &line)))
		printf("%d : %s\n", ret, line);
	printf("%d : %s\n", ret, line);

	return (0);
}
