int copy_line(char **line, char *piece_line)
{
  int temp;

  temp = ft_strdup(*line);
  free(*line);
  *line = ft_strnew(ft_strlen(piece_line) + ft_strlen(temp));
  ft_memcpy(*line, temp, ft_strlen(temp));
  free(temp);
  return (0);
}