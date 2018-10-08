#include "get_next_line.h"
// TODO utiliser ft_strjoin
int get_next_line(const int fd, char **line)
{
	static char *piece_line;
	char *temp;
	int readed;
	int nb_char_rest;

	*line = NULL; // mis à null pour être free
	temp = NULL;	// mis à null pour être free

	if (!piece_line)
		piece_line = ft_strnew(BUFF_SIZE);

	while (ft_strchr(piece_line, '\n') == NULL)
	{
		free(temp);
		temp = ft_strdup(*line);
		free(*line);
		*line = ft_strnew(ft_strlen(piece_line) + ft_strlen(temp));

		ft_memcpy(*line, temp, ft_strlen(temp));
		ft_strcat(*line, piece_line);
		if ((readed = read(fd, piece_line, BUFF_SIZE)) == -1)
			return (-1); // erreur de lecture
		if (readed == 0)
			return (0);
	}

	nb_char_rest = ft_strchr(piece_line, '\n') - piece_line;
	free(temp);
	temp = ft_strdup(*line);
	free(*line);
	*line = ft_strnew(nb_char_rest + ft_strlen(temp));
	ft_memcpy(*line, temp, ft_strlen(temp));
	ft_strncat(*line, piece_line, nb_char_rest);
	piece_line = piece_line + nb_char_rest + 1; // le +1 est pour passer le \n !!
	// ft_putstr(*line);
	// ft_putstr("\n");

	return (1);
}
