/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 12:33:29 by keokim            #+#    #+#             */
/*   Updated: 2021/05/21 12:03:09 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
}

#include <stdio.h>
#include <fcntl.h>

int		main(void)
{
	char	*line;
	int		ret;
	int		fd;

	fd = open("test", O_RDONLY);
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
