#include "get_next_line.h"

int get_next_line(const int fd, char **line)
{
	static char piece_line[BUFF_SIZE];
	char *temp;
	int readed;
	int nb_char_topass;

	*line = NULL;
	while (ft_strchr(piece_line, '\n') == NULL)
	{
		temp = ft_strdup(*line);
		free(*line);
		*line = ft_strnew(ft_strlen(piece_line) + ft_strlen(temp));
		ft_memcpy(*line, temp, ft_strlen(temp));
		free(temp);
		ft_strcat(*line, piece_line);
		if ((readed = read(fd, piece_line, BUFF_SIZE)) == -1)
			return (-1);
		if (readed == 0)
			return (0);
	}

	nb_char_topass = ft_strchr(piece_line, '\n') - piece_line;
	temp = ft_strdup(*line);
	free(*line);
	*line = ft_strnew(nb_char_topass + ft_strlen(temp));
	ft_memcpy(*line, temp, ft_strlen(temp));
	free(temp);
	ft_strncat(*line, piece_line, nb_char_topass);
	ft_strcpy(piece_line, piece_line + nb_char_topass + 1);
	return (1);
}
