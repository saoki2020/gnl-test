#include "mini_gnl.h"

size_t	ft_strlen(const char *str)
{
	size_t len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char*)s;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if ((char)c == '\0' && str[i] == '\0')
		return (&str[i]);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*dest;

	dest = (char *)malloc(ft_strlen(s1) + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	get_len(size_t len, size_t start, size_t s_len)
{
	size_t	subs_len;

	if (len <= s_len - start)
		subs_len = len;
	else
		subs_len = s_len - start;
	return (subs_len);
}



char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	s_len;

	i = 0;
	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (len <= 0 || s_len < start)
		str = (char *)malloc(1);
	else
	{
		str = (char *)malloc(get_len(len, start, s_len) + 1);
		if (str == NULL)
			return (NULL);
		while (i < len && (start + i) < s_len)
		{
			str[i] = s[start + i];
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}


size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size != 0)
	{
		while (src[i] && (dest_len + i) < (size - 1))
		{
			dest[dest_len + i] = src[i];
			i++;
		}
	}
	dest[dest_len + i] = '\0';
	if (size < dest_len)
		return (size + src_len);
	else
		return (dest_len + src_len);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	if (src == NULL || dest == NULL)
		return (0);
	i = 0;
	if (size != 0)
	{
		while (i < size - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_str;
	char	*str;

	if (s1 == NULL && s2 == NULL)
	{
		str = (char *)malloc(1);
		str[0] = '\0';
		return (str);
	}
	else if (s1 == NULL && s2 != NULL)
		return (ft_strdup(s2));
	else if (s1 != NULL && s2 == NULL)
		return (ft_strdup(s1));
	else
	{
		len_str = ft_strlen(s1) + ft_strlen(s2);
		str = (char *)malloc(len_str + 1);
		if (str == NULL)
			return (NULL);
		ft_strlcpy(str, (char *)s1, (ft_strlen(s1) + 1));
		ft_strlcat(str, (char *)s2, (len_str + 1));
		return (str);
	}
}
