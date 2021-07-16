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
	key_press(int keycode, t_data **data)
{
    if (keycode == KEY_ESC)
        exit(0);
	if (keycode == ARR_UP)
		(*data)->shift_y++;
	else if (keycode == ARR_DOWN)
		(*data)->shift_y--;
	else if (keycode == ARR_LEFT)
		(*data)->shift_x--;
	else if (keycode == ARR_RIGHT)
		(*data)->shift_x++;
	else if (keycode == ARR_LEFT)
		(*data)->shift_x--;
	else if (keycode == PLUS)
		(*data)->zoom++;
	else if (keycode == MINUS)
		(*data)->zoom--;

    return (0);
}

void
	print_keys(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 20, 20, 0xffffff, "shift : ← ↑ → ↓");
	mlx_string_put(fdf->mlx, fdf->win, 20, 40, 0xffffff, "zoom : + / -");
	mlx_string_put(fdf->mlx, fdf->win, 20, 60, 0xffffff, "rotate x : 1 / 2");
	mlx_string_put(fdf->mlx, fdf->win, 20, 80, 0xffffff, "rotate y : 3 / 4");
	mlx_string_put(fdf->mlx, fdf->win, 20, 100, 0xffffff, "rotate z : 5 / 6");
	mlx_string_put(fdf->mlx, fdf->win, 20, 120, 0xffffff, "Exit : Esc");
}

void
	print_error(char *msg)
{
	// if (errno == 0)
	// 	ft_putstr_fd(msg, 2);
	// else
	// 	perror(msg);
	ft_putstr_fd(msg, 2);
	write(2, "\n", 1);
	exit(1);
}

void
	free_int(int **arr, int height)
{
	int		i;

	i = 0;
	while (i < height)
		free(arr[i++]);
	free(arr);
}

void
	free_uint(unsigned int **arr, int height)
{
	int		i;

	i = 0;
	while (i < height)
		free(arr[i++]);
	free(arr);
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
	invalid_width(char **argv, t_data *data)
{
	int		fd;
	int		is_width;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error("Open fail");
	while (get_next_line(fd, &line) > 0)
	{
		is_width = count_word(line, ' ');
		free(line);
		if (is_width != data->width)
			print_error("Found wrong line length. Exiting. ");
	}
	free(line);
	close(fd);
}

void
	fill_z(t_data *data, t_map **map, char *line, int i)
{
	int		j;
	int		k;
	char	**split;

	split = ft_split(line, ' ');
	(*map)->z[i] = (int *)malloc(sizeof(int) * data->width);
	if (!((*map)->z[i]))
		print_error("Malloc error");
	j = -1;
	while (++j < data->width)
		(*map)->z[i][j] = ft_atoi(split[j]);
	k = 0;
	while (k < data->width)
		free(split[k++]);
	free(split);
}

void
	get_z(char **argv, t_data *data, t_map **map)
{
	int		fd;
	int		i;
	int		j;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error("Open fail");
	(*map)->z = (int **)malloc(sizeof(int *) * data->height);
	if (!(*map)->z)
		print_error("Malloc error");
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		fill_z(data, map, line, i++);
		free(line);
	}
	if (*line)
		fill_z(data, map, line, i);
	free(line);
	close(fd);
}

void
	fill_color(t_data *data, t_map **map, char *line, int i)
{
	int		j;
	int		k;
	char	*temp;
	char	**split;

	split = ft_split(line, ' ');
	(*map)->color[i] = (unsigned int *)malloc(sizeof(unsigned int) * data->width);
	if (!((*map)->color[i]))
		print_error("Malloc error");
	j = -1;
	while (++j < data->width)
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
	get_color(char **argv, t_data *data, t_map **map)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		print_error("Open fail");
	(*map)->color = (unsigned int **)malloc(sizeof(unsigned int *) * data->height);
	if (!(*map)->color)
		print_error("Malloc error");
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		fill_color(data, map, line, i++);
		free(line);
	}
	if (*line)
		fill_color(data, map, line, i);
	free(line);
	close(fd);
}

int
	main(int argc, char **argv)
{
	t_data	*data;
	t_map	*map;

	if (argc < 2)
		print_error("Useage : ./fdf [File]");
	data = (t_data *)malloc(sizeof(t_data));
	map = (t_map *)malloc(sizeof(t_map));
	get_map_size(argv, &data);
	invalid_width(argv, data);
	get_z(argv, data, &map);
	get_color(argv, data, &map);

	// printf("width : %d\nheight : %d\n", data->width, data->height);
	// int i = 0;
	// while (i < data->height)
	// {
	// 	int j = 0;
	// 	while (j < data->width)
	// 		printf("%3d", map->z[i][j++]);
	// 	printf("\n");
	// 	i++;
	// }
	// printf("---------------------------------------------\n");
	// int i = 0;
	// while (i < data->height)
	// {
	// 	int j = 0;
	// 	while (j < data->width)
	// 		printf("%10d", map->color[i][j++]);
	// 	printf("\n");
	// 	i++;
	// }

	get_z_range(&data, map);
	// win_size_init(&data);
	zoom_shift_init(&data);
	map->fdf = fdf_init(data);
	draw(data, map);
	mlx_key_hook(map->fdf->win, key_press, &data);
    mlx_loop(map->fdf->mlx);

	free_int(map->z, data->height);
	free_uint(map->color, data->height);
	free(map->fdf);
	free(map);
	free(data);
}
