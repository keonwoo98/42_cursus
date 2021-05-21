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
	// *line = ft_substr(*temp, 0, is_line);
	// ptr = ft_strdup(&(*temp)[is_line + 1]);
	free(*temp);
	*temp = ptr;
	return (1);
}

int					return_remain(char **temp, char **line, int read_size)
{
	int				idx;

	if (read_size < 0)
		return (-1);
	if (*temp && (idx = chk_newline(*temp)) >= 0)
		return (sep_line(temp, line, idx));
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
	char			buffer[BUFFER_SIZE + 1];
	static char		*temp[OPEN_MAX];

	if ((fd < 0) || !line || (BUFFER_SIZE <= 0))
		return (-1);
	while ((read_size = read(fd, buffer, BUFFER_SIZE)) > 0)
	{
		buffer[read_size] = '\0';
		temp[fd] = ft_strjoin(temp[fd], buffer);
		is_line = chk_newline(temp[fd]);
		if (is_line >= 0)
			return (sep_line(&temp[fd], line, is_line));
	}
	return (return_remain(&temp[fd], line, read_size));
	return (0);
}

#include <stdio.h>
#include <fcntl.h>

int		main(void)
{
	char	*line;
	int		ret;
	int		fd;

	fd = open("./test.txt", O_RDONLY);
//	fd = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("get_next_line : %s\n", line);
		printf("return value : %d\n\n", ret);
		free(line);
	}
	printf("get_next_line : %s\n", line);
	printf("return value : %d\n", ret);
	free(line);
	close(fd);
	return (0);
}
