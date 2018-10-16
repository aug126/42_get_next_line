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

	fd = 0;

	while (fd < 256)
	{
		fd = open("file1", O_RDONLY);
		printf("open %d\n", fd);
		if (fd == -1)
			return (0);
	}

	while ((ret = get_next_line(fd, &line)))
		printf("%d : %s\n", ret, line);
	printf("%d : %s\n", ret, line);

	while (fd > 2)
		close (fd--);

	return (0);
}
