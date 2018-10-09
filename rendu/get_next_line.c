#include "get_next_line.h"

int ready_copy(char **line, int nb_char_piece)
{
	char *temp;

	temp = ft_strdup(*line);
	free(*line);
	*line = ft_strnew(nb_char_piece + ft_strlen(temp));
	ft_memcpy(*line, temp, ft_strlen(temp));
	free(temp);
	return (0);
}

int while_no_n(char **line, char *piece_line, const int fd)
{
	int readed;

	ready_copy(line, ft_strlen(piece_line));
	ft_strcat(*line, piece_line);
	if ((readed = read(fd, piece_line, BUFF_SIZE)) == -1)
		return (-1);
	if (readed == 0)
		return (0);
	return (1);
}

int get_next_line(const int fd, char **line)
{
	static char piece_line[BUFF_SIZE];
	int nb_char_topass;
	int value;

	*line = NULL;
	while (ft_strchr(piece_line, '\n') == NULL)
	{
		value = while_no_n(line, piece_line, fd);
		if (value == -1 || value == 0)
			return value;
	}

	nb_char_topass = ft_strchr(piece_line, '\n') - piece_line;
	ready_copy(line, nb_char_topass);
	ft_strncat(*line, piece_line, nb_char_topass);
	ft_strcpy(piece_line, piece_line + nb_char_topass + 1);
	return (1);
}
