#include <unistd.h>
#include <stdlib.h>

int				ft_strlen(char *s)
{
	int			i = 0;
	while (s[i])
		i++;
	return (i);
}

char			*ft_charappend(char *line, char buff)
{
	int			i = 0;
	char		*ret;

	if (!(ret = malloc(ft_strlen(line) + 2)))
		return (0);
	while (line[i] != 0)
	{
		ret[i] = line[i];
		i++;
	}
	ret[i] = buff;
	i++;
	ret[i] = 0;
	free(line);
	return (ret);
}

int				get_next_line(char **line)
{
	int			read_size;
	char		buffer;

	if (!(*line = malloc(1)))
		return (-1);
	(*line)[0] = 0;
	while ((read_size = read(0, &buffer, 1)) > 0)
	{
		if (buffer == '\n')
			return (1);
		*line = ft_charappend(*line, buffer);
		if (*line == 0)
			return (-1);
	}
	if (read_size == -1)
		return (-1);
	else
		return (0);
}
