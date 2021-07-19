/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 10:42:54 by keokim            #+#    #+#             */
/*   Updated: 2021/07/17 10:42:56 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./Libft/libft.h"

void
	get_map_size(char **argv, t_data **data)
{
	int		fd;
	int		width;
	int		height;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error("Open fail");
	height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		width = count_word(line, ' ');
		height++;
		free(line);
	}
	if (!height)
		print_error("No data Found");
	if (*line)
		height++;
	free(line);
	close(fd);
	(*data)->width = width;
	(*data)->height = height;
}

void
	fill_z(t_map **map, char *line, int i)
{
	int		j;
	int		k;
	char	**split;

	split = ft_split(line, ' ');
	(*map)->z[i] = (int *)malloc(sizeof(int) * (*map)->data->width);
	if (!((*map)->z[i]))
		print_error("Malloc error");
	j = -1;
	while (++j < (*map)->data->width)
		(*map)->z[i][j] = ft_atoi(split[j]);
	k = 0;
	while (k < (*map)->data->width)
		free(split[k++]);
	free(split);
}

void
	get_z(char **argv, t_map **map)
{
	int		fd;
	int		i;
	int		j;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error("Open fail");
	(*map)->z = (int **)malloc(sizeof(int *) * (*map)->data->height);
	if (!(*map)->z)
		print_error("Malloc error");
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		fill_z(map, line, i++);
		free(line);
	}
	if (*line)
		fill_z(map, line, i);
	free(line);
	close(fd);
}

void
	fill_color(t_map **map, char *line, int i)
{
	int		j;
	int		k;
	char	*temp;
	char	**split;

	split = ft_split(line, ' ');
	(*map)->color[i] =
        (unsigned int *)malloc(sizeof(unsigned int) * (*map)->data->width);
	if (!((*map)->color[i]))
		print_error("Malloc error");
	j = -1;
	while (++j < (*map)->data->width)
	{
		if (ft_strchr(split[j], ','))
		{
			temp = ft_strchr(split[j], ',');
			(*map)->color[i][j] = ft_atoi_base(temp + 3);
		}
		else
			(*map)->color[i][j] = 16777215;
	}
	k = 0;
	while (split[k])
		free(split[k++]);
	free(split);
}

void
	get_color(char **argv, t_map **map)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error("Open fail");
	(*map)->color =
        (unsigned int **)malloc(sizeof(unsigned int *) * (*map)->data->height);
	if (!(*map)->color)
		print_error("Malloc error");
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		fill_color(map, line, i++);
		free(line);
	}
	if (*line)
		fill_color(map, line, i);
	free(line);
	close(fd);
}
