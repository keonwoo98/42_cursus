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

void
	print_keys(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 20, 20, 0xffffff, "Exit : Esc");
	mlx_string_put(fdf->mlx, fdf->win, 20, 40, 0xffffff, "zoom : + / -");
	mlx_string_put(fdf->mlx, fdf->win, 20, 60, 0xffffff, "shift : Arrow Keys");
}

void
	print_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	write(2, "\n", 1);
	exit(1);
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
	win_size(t_map **map)
{
	get_z_range(map);
	win_size_init(map);
	zoom_init(map);
	shift_init(map);
}

int
	main(int argc, char **argv)
{
	t_map	*map;

	if (argc != 2)
		print_error("Useage : ./fdf [File]");
	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
		print_error("Malloc error");
	map->data = (t_data *)malloc(sizeof(t_data));
	if (!map->data)
		print_error("Malloc error");
	get_map_size(argv, &map->data);
	invalid_width(argv, map->data);
	get_z(argv, &map);
	get_color(argv, &map);
	win_size(&map);
	map->fdf = fdf_init(map->data);
	draw(&map);
	mlx_key_hook(map->fdf->win, key_press, &map);
	mlx_loop(map->fdf->mlx);
	free_int(map->z, map->data->height);
	free_uint(map->color, map->data->height);
	free(map->fdf);
	free(map->data);
	free(map);
}
