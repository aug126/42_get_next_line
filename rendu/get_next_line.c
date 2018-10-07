#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static char	*piece_line;
	char	*temp;
	int			readed;
	int			test;

	line = (char **)malloc(sizeof(char*));
	*line = NULL;
	temp = NULL;

	if (!piece_line)
	{
		piece_line = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	}

	while (ft_strchr(piece_line, '\n') == NULL)
	{

		temp = ft_strdup(*line);
		free(*line);
		*line = ft_strnew(ft_strlen(piece_line) + ft_strlen(temp));
		ft_memcpy(*line, temp, ft_strlen(temp));
		ft_strcat(*line, piece_line);
		ft_putstr(*line);
		if ((readed = read(fd, piece_line, BUFF_SIZE)) == -1)
			return (-1); // erreur de lecture
		if (readed == 0)
			return (0);
	}

	test = ft_strchr(piece_line, '\n') - piece_line;
	temp = ft_strdup(*line);
	free(*line);
	*line = ft_strnew(test + ft_strlen(temp));
	ft_memcpy(*line, temp, ft_strlen(temp));
	ft_strncat(*line, piece_line, test);
	piece_line = piece_line + test + 1; // le +1 est pour passer le \n !!
	return (1);
}
