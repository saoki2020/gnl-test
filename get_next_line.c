
#include "get_next_line.h"

int				ft_make_one_line(char *buf_join, char **save, char **line)
{
	int			len;

	len = 0;
	if (buf_join == NULL || save == NULL || line == NULL)
		return (GNL_ERR);
	while (buf_join[len] != '\n' && buf_join[len] != '\0')
	{
		len++;
	}
	if (buf_join[len] == '\n')
	{
		*line = ft_substr(buf_join, 0, len);
		*save = ft_strdup(&buf_join[len + 1]);
		free(buf_join);
		buf_join = NULL;
		return (GNL_READ);
	}
	*line = ft_strdup(buf_join);
	free(buf_join);
	buf_join = NULL;
	return (GNL_EOF);
}

char			*ft_read_or_save(char **save, int fd, int *rc)
{
	char		*buf;

	if (save == NULL)
		return (NULL);
	if (*save != NULL)
	{
		buf = *save;
		*save = NULL;
		*rc = GNL_READ;
	}
	else
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return (NULL);
		*rc = read(fd, buf, BUFFER_SIZE);
		if (*rc < 0)
		{
			free(buf);
			buf = NULL;
			return (NULL);
		}
		buf[*rc] = '\0';
	}
	return (buf);
}

int				get_next_line(int fd, char **line)
{
	static char	*save;
	char		*buf;
	char		*buf_join;
	int			rc;

	if (fd == -1 || line == NULL)
		return (GNL_ERR);
	buf_join = NULL;
	while (1)
	{
		buf = ft_read_or_save(&save, fd, &rc);
		if (buf == NULL)
			return (GNL_ERR);
		if (buf_join == NULL)
			buf_join = ft_strdup(buf);
		else
			buf_join = ft_strjoin_and_free(buf_join, buf);
		if (ft_strchr(buf, '\n') || rc == GNL_EOF)
			break ;
		free(buf);
		buf = NULL;
	}
	free(buf);
	buf = NULL;
	return (ft_make_one_line(buf_join, &save, line));
}
