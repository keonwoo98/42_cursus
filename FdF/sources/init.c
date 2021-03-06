/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:10:40 by keokim            #+#    #+#             */
/*   Updated: 2021/07/17 18:10:42 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void
	zoom_init(t_map **map)
{
	float	zoom_x;
	float	zoom_y;
	int		i;
	int		j;

	(*map)->data->zoom = 1;
	zoom_x = (*map)->data->width;
	zoom_y = (*map)->data->height;
	if ((*map)->data->z_range > zoom_y)
		zoom_y += (*map)->data->z_max;
	i = zoom_x;
	j = zoom_y;
	while (i < ((*map)->data->win_width / 2) && j < (*map)->data->win_height)
	{
		i += zoom_x;
		j += zoom_y;
		(*map)->data->zoom++;
	}
}

void
	shift_init(t_map **map)
{
	float	center_x;
	float	center_y;
	float	center_z;

	(*map)->data->shift_x = 0;
	(*map)->data->shift_y = 0;
	center_x = 0;
	center_y = (*map)->data->height - 1;
	center_z = (*map)->z[(int)center_y][(int)center_x];
	isometric(&center_x, &center_y, center_z);
	(*map)->data->shift_x = \
		(*map)->data->win_width / 2 - center_x * (*map)->data->zoom;
	(*map)->data->shift_y = \
		(*map)->data->win_height - center_y * (*map)->data->zoom;
	if ((*map)->data->width == 500)
		(*map)->data->shift_y += 100;
	if ((*map)->data->width <= 100 && (*map)->data->z_min < 0)
		(*map)->data->shift_y -= 30;
	if ((*map)->data->width == 200 && (*map)->data->z_range < 20)
		(*map)->data->shift_x -= 120;
	if ((*map)->data->width == 27 && (*map)->data->z_min < 0)
		(*map)->data->shift_y -= 180;
	if ((*map)->data->height % 10 == 4 && (*map)->data->z_min == 0)
		(*map)->data->shift_x += 60;
}

void
	win_size_init(t_map **map)
{
	(*map)->data->win_width = 1440;
	(*map)->data->win_height = 850;
}

void
	get_z_range(t_map **map)
{
	int		x;
	int		y;
	int		min;
	int		max;

	min = 0;
	max = 0;
	y = 0;
	while (y < (*map)->data->height)
	{
		x = 0;
		while (x < (*map)->data->width)
		{
			if ((*map)->z[y][x] < min)
				min = (*map)->z[y][x];
			if ((*map)->z[y][x] > max)
				max = (*map)->z[y][x];
			x++;
		}
		y++;
	}
	(*map)->data->z_max = max;
	(*map)->data->z_min = min;
	(*map)->data->z_range = max - min;
}

t_fdf
	*fdf_init(t_data *data)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		print_error("Malloc error");
	fdf->mlx = mlx_init();
	if (fdf->mlx == NULL)
		print_error("Mlx error");
	fdf->win = mlx_new_window(fdf->mlx, \
		data->win_width, data->win_height, "fdf");
	if (fdf->win == NULL)
		print_error("Mlx error");
	fdf->img = mlx_new_image(fdf->mlx, data->win_width, data->win_height);
	if (fdf->img == NULL)
		print_error("Mlx error");
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bpp, \
		&fdf->line_length, &fdf->endian);
	return (fdf);
}
