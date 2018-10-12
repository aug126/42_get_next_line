/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoat <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 12:37:39 by adoat             #+#    #+#             */
/*   Updated: 2018/10/12 12:44:44 by adoat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ready_copy(char **line, int nb_char_piece)
{
	char	*temp;

	if (*line == NULL)
		temp = ft_strdup("");
	else if (!(temp = ft_strdup(*line)) && *line)
		return (-1);
	free(*line);
	if ((*line = ft_strnew(nb_char_piece + ft_strlen(temp))) == NULL)
		return (-1);
	ft_memcpy(*line, temp, ft_strlen(temp));
	free(temp);
	return (0);
}

static int	while_no_n(char **line, char *piece_line, const int fd)
{
	int		readed;

	if (ready_copy(line, ft_strlen(piece_line)) == -1)
		return (-1);
	ft_strcat(*line, piece_line);
	if ((readed = read(fd, piece_line, BUFF_SIZE)) == -1)
		return (-1);
	ft_bzero(piece_line + readed, BUFF_SIZE - readed);
	if (readed == 0)
		return (**line == '\0' ? 0 : 2);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	piece_line[BUFF_SIZE + 1];
	int			nb_char_topass;
	int			value;

	if (!line)
		return (-1);
	*line = NULL;
	while (ft_strchr(piece_line, '\n') == NULL)
	{
		value = while_no_n(line, piece_line, fd);
		if (value == -1 || value == 0)
			return (value);
		if (value == 2)
			break ;
	}
	if (ft_strchr(piece_line, '\n') != NULL)
		nb_char_topass = ft_strchr(piece_line, '\n') - piece_line;
	else
		nb_char_topass = ft_strchr(piece_line, '\0') - piece_line;
	if (ready_copy(line, nb_char_topass) == -1)
		return (-1);
	ft_strncat(*line, piece_line, nb_char_topass);
	if ((int)ft_strlen(piece_line) == nb_char_topass + 1)
		ft_bzero(piece_line, nb_char_topass + 1);
	else
		ft_strcpy(piece_line, piece_line + nb_char_topass + 1);
	return (1);
}
