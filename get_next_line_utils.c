#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

int		ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

char		*ft_strdup(char *str)
{
	char	*newstr;
	int		strlen;
	int		i;

	if (str == NULL)
		return (NULL);
	strlen = ft_strlen(str);
	newstr = malloc(sizeof(char) * (strlen + 1));
	if (newstr == NULL)
		return (NULL);
	ft_bzero(newstr, strlen + 1);
	i = 0;
	while (str[i] != '\0')
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char	*ft_strchr(char *s, int c)
{
	char	ch;

	ch = (char)c;
	while (*s != '\0')
	{
		if (*s == ch)
		{
			return ((char *)s);
		}
		s++;
	}
	if (ch == '\0')
		return ((char *)s);
	return (NULL);
}

/*
char		*ft_substr(char *str, int start, int end)
{
	char	*newstr;
	int		strlen;

	if (str == NULL)
		return (NULL);
	strlen = ft_strlen(str);
	if (start > strlen || end <= 0)
		return (ft_strdup(""));
	newstr = malloc(sizeof(char) * (end + 1));
	if (newstr == NULL)
		return (NULL);
	while (start < end)
	{
		newstr[start] = str[start];
		start++;
	}
	newstr[start] = '\0';
	return (newstr);
}
*/

size_t	ft_get_len(size_t len, size_t start, size_t s_len)
{
	size_t	substr_len;

	if (len <= s_len - start)
		substr_len = len;
	else
		substr_len = s_len - start;
	return (substr_len);
}

char	*ft_substr(char *s, size_t start, size_t end)
{
	char	*str;
	size_t	i;
	size_t	s_len;

	i = 0;
	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start || end <= 0)
		str = (char *)malloc(1);
	else
	{
		str = (char *)malloc(ft_get_len(end, start, s_len) + 1);
		if (str == NULL)
			return (NULL);
		while (i < end && (start + i) < s_len)
		{
			str[i] = s[start + i];
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}
