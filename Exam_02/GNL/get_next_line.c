#include "get_next_line.h"

static int				ft_strlen(char *s)
{
	int					i = 0;
	while (s[i])
		i++;
	return (i);
}

static char			*ft_strdup(char *s)
{
	int				i;
	int				len;
	char			*str;

	len = ft_strlen(s);
	if (!(str = (char *)malloc(len + 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char			*ft_strjoin(char *s1, char *s2)
{
	int				len1, len2;
	int				i = 0;
	char			*ret;

	if (!s1 || !s2)
		return (0);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(ret = (char *)malloc(len1 + len2 + 1)))
		return (0);
	while (i < len1)
	{
		ret[i] = *s1++;
		i++;
	}
	while (i < len1 + len2)
	{
		ret[i] = *s2++;
		i++;
	}
	ret[i] = 0;
	return (ret);
}

int					get_next_line(char **line)
{
	int				read_size;
	char			buffer[2];
	char			*tmp;

	if (line == NULL)
		return (-1);
	*line = ft_strdup("");
	while ((read_size = read(0, buffer, 1)) > 0)
	{
		buffer[read_size] = 0;
		if (buffer[0] == '\n')
			return (1);
		tmp = *line;
		*line = ft_strjoin(tmp, buffer);
		free(tmp);
	}
	return (read_size == 0 ? 0 : -1);
}
