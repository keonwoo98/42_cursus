/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:33:29 by keokim            #+#    #+#             */
/*   Updated: 2021/05/21 17:30:30 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		chk_newline(char *temp)
{
	int			i;

	i = 0;
	while (temp[i])
	{
		if (temp[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		sep_line(char **temp, char **line, int is_line)
{
	char			*ptr;

	(*temp)[is_line] = '\0';
	*line = ft_strdup(*temp);
	ptr = ft_strdup(*temp + is_line + 1);
	free(*temp);
	*temp = ptr;
	return (1);
}

int		return_remain(char **temp, char **line, int read_size)
{
	int		i;

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
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int				is_line;
	int				read_size;
	char			*buffer;
	static char		*temp[OPEN_MAX];

	if ((fd < 0) || !line || (BUFFER_SIZE <= 0))
		return (-1);
	if (!(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((read_size = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[read_size] = '\0';
		temp[fd] = ft_strjoin(temp[fd], buffer);
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
