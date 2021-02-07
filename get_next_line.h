#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define MAX_FD 256

int		get_next_line(int fd, char **line);
char	*ft_read_char(int fd, char **remainder, int *read_num);
int		ft_rewrite_line(char *temp, char **remainder, char **line);
char	*ft_gnl_strjoin(char *s1, char *s2);
int	ft_strlen(char *str);
char	*ft_strdup(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_substr(char *s, int start, int end);

#endif
