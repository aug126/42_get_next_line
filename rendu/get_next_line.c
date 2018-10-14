/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adoat <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/14 16:47:30 by adoat             #+#    #+#             */
/*   Updated: 2018/10/14 16:53:56 by adoat            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_strndup(char const *s, size_t n)
{
	char	*dup;
	size_t	i;

	if (!s || !(dup = ft_strnew(n)))
		return (NULL);
	i = 0;
	while (s[i] && n--)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2 || !(str = ft_strnew(n)))
		return (NULL);
	i = 0;
	while (s1[i] && n--)
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] && n--)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

static int	copy_reste(char **line, char *reste)
{
	char	*ret;
	int		up_to_char;
	char	*temp;

	ret = ft_strchr(reste, '\n');
	up_to_char = ret ? (ret - reste) : ft_strlen(reste);
	if (!(*line))
	{
		if (!(*line = ft_strndup(reste, up_to_char)))
			return (-1);
	}
	else
	{
		temp = *line;
		if (!(*line = ft_strnjoin(temp, reste, ft_strlen(temp) + up_to_char)))
			return (-1);
		ft_strdel(&temp);
	}
	ft_strcpy(reste, reste + up_to_char + 1);
	up_to_char = ft_strchr(reste, '\0') - reste;
	ft_bzero(reste + up_to_char, BUFF_SIZE - up_to_char);
	if (ret == NULL)
		return (0);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	reste[OPEN_MAX][BUFF_SIZE + 2];
	int			ret;

	if (fd < 0 || fd > OPEN_MAX || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	*line = NULL;
	if (!(reste[fd][0]) && (ret = read(fd, reste[fd], BUFF_SIZE)) <= 0)
		return (ret);
	if ((ret = copy_reste(line, reste[fd])))
		return (ret);
	while ((ret = read(fd, reste[fd], BUFF_SIZE)) > 0)
	{
		if ((ret = copy_reste(line, reste[fd])))
		{
			return (ret);
		}
	}
	if (ret == -1)
		return (-1);
	return (1);
}
