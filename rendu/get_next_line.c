#include "get_next_line.h"
#include <stdio.h>

static char	*ft_strndup(char const *s, size_t n)
{
	char	*dup;
	size_t	i;

	if (!s || !(dup = ft_strnew(n)))
		return (NULL); // ! pas protégé
	i = 0;
	while (s[i] && n--)
		dup[i++] = s[i];
	dup[i] = '\0';
	return (dup);
}

static char	*ft_strnjoin(char const *s1, char const *s2, size_t n)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2 || !(str = ft_strnew(n)))
		return (NULL); // ! pas protégé
	i = 0;
	while (s1[i] && n--)
		str[i++] = s1[i];
	j = 0;
	while (s2[j] && n--)
		str[i + j++] = s2[j];
	str[i + j] = '\0';
	return (str);
}

static int	copy_reste(char **line, char *reste)
{
	char	*ret;
	int		up_to_char;
	char	*temp;

	if (ret = ft_strchr(reste, '\n')) // possible de mettre sur 1 ligne
		up_to_char = ret - reste;
	else
		up_to_char = ft_strlen(reste);
	if (*line == NULL)
		*line = ft_strndup(reste, up_to_char);
	else
	{
		temp = *line;
		*line = ft_strnjoin(temp, reste, ft_strlen(temp) + up_to_char);
		ft_strdel(&temp);
	}
	ft_strcpy(reste, reste + up_to_char + 1);
	up_to_char = ft_strchr(reste, '\0') - reste;
	ft_bzero(reste + up_to_char, BUFF_SIZE - up_to_char);
	if (ret == NULL)
		return (0);
	printf("TEST ret = %s\n", ret);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	reste[OPEN_MAX][BUFF_SIZE + 2]; // 2 à cause du strcpy de reste dans reste quand on veut passer la suite du char \0 trouvé à la fin.
	int			ret;

	/*
	 * Verifications
	 */
	if (fd > OPEN_MAX || line == NULL || BUFF_SIZE <= 0)
	{
		printf("ERREUR du aux Vérifications !!!\n");
		return (-1);
	}
	*line = NULL; // est-ce vraiment nécessaire ? line est passé comment?
	/*
	 * si reste vide alors on lit pour pouvoir copier
	 * (et surtout voir si read returne 0)
	 */
	if (!(reste[fd][0]) && (ret = read(fd, reste[fd], BUFF_SIZE)) <= 0)
	{
		if (ret == 0)
			printf("FIN DU FICHIER + aucun reste\n");
		else if (ret == -1)
			printf("ERREUR du à la PREMIERE lecture du fichier\n");
		return (ret); // on peut retourner ret 0 ou -1 car premier ret
	}
	/*
	 * copier l'ancien reste (ou le nouveau read) avant de boucler le read
	 */
	if (ret = copy_reste(line, reste[fd]))
	{
		/* 1 si \n trouvé sinon -1 si erreur donc return value */
		if (ret == 1)
			printf("N trouvé au PREMIER copy\n");
		else if (ret == -1)
			printf("ERREUR d'allocation de mémoire au PREMIER copy\n");
		return (ret);		
		/* si 0 on n'a pas fini la ligne donc suite */
	}
	/*
	 * tant que on ne trouve pas un \n
	 * ou que ce n'est pas la fin du fichier, on va boucler
	 */
	while ((ret = read(fd, reste[fd], BUFF_SIZE)) > 0)
	{
		if (ret = copy_reste(line, reste[fd]))
		{
			if (ret == 1)
				printf("N trouvé dans copy BOUCLE\n");
			if (ret == -1)
				printf("ERREUR d'allocation de mémoire dans copy BOUCLE\n");
			// 1 si \n trouvé sinon -1 si erreur donc return value.
			return (ret);		
		}
	}
	/*
	 * protection du read si ret = -1
	 * et return 1 si fin de fichier car ret = 0 mais pour le 2eme read
	 */
	if (ret == -1)
	{
		printf("ERREUR du à la lecture en BOUCLE du fichier\n");
		return (-1);
	}
	printf("FIN FICHIER mais on a lu avant\n");
	return (1);
}
