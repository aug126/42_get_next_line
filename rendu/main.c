#include "libft.h"
#include "get_next_line.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	fd;
	char	**line;

	fd = open(argv[argc - 1], O_RDONLY);
	if(fd == -1)
	{
		ft_putstr_fd("erreur d'ouverture de fichier\n", 2);
		return (0);
	}
	get_next_line(fd, line);
	return (0);
}
