#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H


# define GNL_ERR	-1
# define GNL_EOF	0
# define GNL_READ	1

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int				get_next_line(int fd, char **line);
char		*ft_strjoin_and_free(char *s1, char *s2);
int		ft_strlen(char *s);
char		*ft_strdup(char *str);
char	*ft_strchr(const char *s, int c);
char		*ft_substr(char *str, int start, int end);
void	ft_bzero(void *s, size_t n);
int				ft_make_one_line(char *buf_join, char **save, char **line);
char			*ft_read_or_save(char **save, int fd, int *rc);

#endif
