#ifndef MINI_GNL_H
# define MINI_GNL_H

# define MAX_FD 1024
# define BUFFER_SIZE 100

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>



int				get_next_line(int fd, char **line);
int		read_newline(int fd, char **line);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
size_t	get_len(size_t len, size_t start, size_t s_len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcat(char *dest, char *src, size_t size);
size_t	ft_strlcpy(char *dest, char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
