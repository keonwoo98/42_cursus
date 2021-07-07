/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:38:43 by keokim            #+#    #+#             */
/*   Updated: 2021/07/05 11:38:46 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int
	key_press(int keycode, void *param)
{
    if (keycode == KEY_ESC)
        exit(0);
    return (0);
}

void
	error(char *msg)
{
	perror(msg);
	exit(1);
}

void
	fdf(void)
{
    void    *mlx;
    void    *win;
    void    *param;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 500, 500, "fdf");
    mlx_key_hook(win, key_press, param);
    mlx_loop(mlx);
}

void
	get_map_size(char **argv, t_data **data)
{
	int		fd;
	int		width;
	int		height;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error("Open fail");
	height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		width = count_word(line, ' ');
		height++;
		free(line);
		line = NULL;
	}
	if (*line)
		height++;
	free(line);
	close(fd);
	(*data)->width = width;
	(*data)->height = height;
}

void
	get_z(char **argv, t_data *data, t_map **map)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	char	**split;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error("Open fail");
	(*map)->z = (int **)malloc(sizeof(int *) * data->height);
	if (!(*map)->z)
		error("Malloc error");
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		split = ft_split(line, ' ');
		(*map)->z[i] = (int *)malloc(sizeof(int) * data->width);
		if (!((*map)->z[i]))
			error("Malloc error");
		j = -1;
		while (++j < data->width)
			(*map)->z[i][j] = ft_atoi(split[j]);
		i++;
		free(line);
		int k = 0;
		while (split[k])
			free(split[k++]);
		free(split);
	}
	split = ft_split(line, ' ');
	(*map)->z[i] = (int *)malloc(sizeof(int) * data->width);
	if (!((*map)->z[i]))
		error("Malloc error");
	j = -1;
	while (++j < data->width)
		(*map)->z[i][j] = ft_atoi(split[j]);
	i++;
	free(line);
	int k = 0;
	while (split[k])
		free(split[k++]);
	free(split);
	close(fd);
}

void
	get_color(char **argv, t_data *data, t_map **map)
{
	int		fd;
	int		i;
	int		j;
	char	*line;
	char	*temp;
	char	**split;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error("Open fail");
	(*map)->color = (unsigned int **)malloc(sizeof(unsigned int *) * data->height);
	if (!(*map)->color)
		error("Malloc error");
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		split = ft_split(line, ' ');
		(*map)->color[i] = (unsigned int *)malloc(sizeof(unsigned int) * data->width);
		if (!((*map)->color[i]))
			error("Malloc error");
		j = -1;
		while (++j < data->width)
		{
			if (ft_strchr(split[j], ','))
			{
				split[j] = ft_strchr(split[j], ',');
				split[j]++;
				split[j]++;
				split[j]++;
				(*map)->color[i][j] = ft_atoi_base(split[j]);
			}
			else
				(*map)->color[i][j] = 0;
		}
		i++;
		free(line);
	}
	split = ft_split(line, ' ');
	(*map)->color[i] = (unsigned int *)malloc(sizeof(unsigned int) * data->width);
	if (!((*map)->color[i]))
		error("Malloc error");
	j = -1;
	while (++j < data->width)
	{
		if (ft_strchr(split[j], ','))
		{
			split[j] = ft_strchr(split[j], ',');
			split[j]++;
			split[j]++;
			split[j]++;
			(*map)->color[i][j] = ft_atoi_base(split[j]);
		}
		else
			(*map)->color[i][j] = 0;
	}
	free(line);
	close(fd);
}

int
	main(int argc, char **argv)
{
	int		fd;
	t_data	*data;
	t_map	*map;

	if (argc < 2)
		error("Useage : ./fdf [File]");
	data = (t_data *)malloc(sizeof(t_data));
	map = (t_map *)malloc(sizeof(t_map));
	get_map_size(argv, &data);
	get_z(argv, data, &map);
	get_color(argv, data, &map);
	int i = 0;
	printf("width : %d\nheight : %d\n", data->width, data->height);
	while (i < data->height)
	{
		int j = 0;
		while (j < data->width)
			printf("%3d", map->z[i][j++]);
		printf("\n");
		i++;
	}
	printf("---------------------------------------------\n");
	i = 0;
	while (i < data->height)
	{
		int j = 0;
		while (j < data->width)
			printf("%5d", map->color[i][j++]);
		printf("\n");
		i++;
	}
	while (1);
}
