/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/26 09:20:21 by keokim            #+#    #+#             */
/*   Updated: 2021/05/26 09:30:32 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int			chk_newline(char *temp)
{
	int				i;

	i = 0;
	while (temp[i])
	{
		if (temp[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int			sep_line(char **temp, char **line, int is_line)
{
	char			*ptr;

	(*temp)[is_line] = '\0';
	*line = ft_strdup(*temp);
	if (!(*line))
		return (-1);
	ptr = ft_strdup(*temp + is_line + 1);
	if (!ptr)
		return (-1);
	free(*temp);
	*temp = ptr;
	return (1);
}

static int			return_remain(char **temp, char **line, int read_size)
{
	int				i;

	if (read_size < 0)
		return (-1);
	if (*temp && (i = chk_newline(*temp)) >= 0)
		return (sep_line(temp, line, i));
	else if (*temp)
	{
		*line = *temp;
		*temp = 0;
		return (0);
	}
	*line = ft_strdup("");
	if (!(*line))
		return (-1);
	return (0);
}

int					get_next_line(int fd, char **line)
{
	int				is_line;
	int				read_size;
	char			*buffer;
	static char		*temp[MAX_FD];

	if ((fd < 0) || !line || (BUFFER_SIZE <= 0))
		return (-1);
	if (!(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((read_size = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[read_size] = '\0';
		temp[fd] = ft_strjoin(temp[fd], buffer);
		if (!(temp[fd]))
			return (-1);
		is_line = chk_newline(temp[fd]);
		if (is_line >= 0)
		{
			free(buffer);
			return (sep_line(&temp[fd], line, is_line));
		}
	}
	free(buffer);
	return (return_remain(&temp[fd], line, read_size));
}
