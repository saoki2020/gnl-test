
#include "get_next_line.h"

int				get_next_line(int fd, char **line)
{
	static char	*remainder;
	char		*buf;
	char		*temp;
	int			read_num;

	if (fd < 0 || MAX_FD <= fd || line == NULL)
		return (-1);
	temp = NULL;
	while (1)
	{
		buf = ft_read_char(fd, &remainder, &read_num);
		if (buf == NULL)
			return (-1);
		if (temp == NULL)
			temp = ft_strdup(buf);
		else
			temp = ft_gnl_strjoin(temp, buf);
		if (ft_strchr(buf, '\n') || read_num == 0)
			break ;
		free(buf);
		buf = NULL;
	}
	free(buf);
	buf = NULL;
	return (ft_rewrite_line(temp, &remainder, line));
}

/*
char			*ft_read_char(int fd, char **remainder, int *read_num)
{
	char		*buf;

	if (remainder == NULL)
		return (NULL);
	if (*remainder != NULL)
	{
		buf = *remainder;
		*remainder = NULL;
		*read_num = 1;
	}
	else
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buf == NULL)
			return (NULL);
		*read_num = read(fd, buf, BUFFER_SIZE);
		if (*read_num < 0)
		{
			free(buf);
			buf = NULL;
			return (NULL);
		}
		buf[*read_num] = '\0';
	}
	return (buf);
}
*/
char	*ft_read_char(int fd, char **remainder, int *read_num)
{
	char	*buf;

	if (remainder == NULL)
		return (NULL);
	if (*remainder == NULL)
	{
		buf = (char *)malloc(BUFFER_SIZE + 1);
		if (buf == NULL)
			return (NULL);
		*read_num = read(fd, buf, BUFFER_SIZE);
		if (*read_num < 0)
		{
			free(buf);
			buf = NULL;
			return (NULL);
		}
		buf[*read_num] = '\0';
	}
	else
	{
		buf = *remainder;
		*remainder = NULL;
		*read_num = 1;
	}
	return (buf);
}



int				ft_rewrite_line(char *temp, char **remainder, char **line)
{
	int			len;

	len = 0;
	if (temp == NULL || remainder == NULL || line == NULL)
		return (-1);
	while (temp[len] != '\n' && temp[len] != '\0')
	{
		len++;
	}
	if (temp[len] == '\n')
	{
		*line = ft_substr(temp, 0, len);
		*remainder = ft_strdup(&temp[len + 1]);
		free(temp);
		temp = NULL;
		return (1);
	}
	*line = ft_strdup(temp);
	free(temp);
	temp = NULL;
	return (0);
}

/*
char		*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
	 str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	s1 = NULL;
	return (str);
}
*/

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	s1 = NULL;
	return (str);
}
