#include "mini_gnl.h"

 int		get_next_line(int fd, char **line)
 {
 	static char *buf;
		char *tmp;
		char *lbp;
 	int			ret;

 	if (!line || fd < 0)
 		return (-1);
 	*line = buf;
		buf = NULL;
 	ret = 1;
 	if (!*line || !ft_strchr(*line, '\n'))
 		ret = read_newline(fd, line);
 	if (!(lbp = ft_strchr(*line, '\n')))
 		return (ret);
 	tmp = ft_substr(*line, 0, lbp - *line);
 	buf = ft_strdup(lbp + 1);
 	free(*line);
 	*line = tmp;
 	return (ret);
 }

	  int		read_newline(int fd, char **line)
  {
  	int		ret;
  	char	buf[BUFFER_SIZE + 1];
  	char	*tmp;

  	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
  	{
  		buf[ret] = '\0';
  		if (!*line)
  			tmp = ft_strdup(buf);
  		else
  			tmp = ft_strjoin(*line, buf);
  		if (*line)
  			free(*line);
  		*line = tmp;
  		if (ft_strchr(buf, '\n'))
  			break ;
  	}
  	if (ret > 0)
  		ret = 1;
  	return (ret);
  }
