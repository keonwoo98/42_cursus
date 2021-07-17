/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 12:47:56 by keokim            #+#    #+#             */
/*   Updated: 2021/07/17 12:47:59 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void
	isometric(float *x, float *y, int z)
{
	float pre_x;
	float pre_y;

	pre_x = *x;
	pre_y = *y;
	*x = (pre_x * cos(PI / 6 * -1)) - (pre_y * sin(PI / 3 * -1));
	*y = (pre_x * sin(PI / 6 * -1)) + (pre_y * cos(PI / 3 * -1)) - z;
}

void
	zoom(float *x, float *y, int *z, t_data *data)
{
	*x *= data->zoom;
	*y *= data->zoom;
	*z *= data->zoom;
}

void
	shift(float *x, float *y, t_data *data)
{
	*x += data->shift_x;
	*y += data->shift_y;
}

void
	dda_algorithm(float x, float y, int flag, t_map *map)
{
	float	x1;
	float	y1;
	float	x_inc;
	float	y_inc;
	int		step;
	int		z;
	int		z1;
	int		color;

	x1 = x;
	y1 = y;
	if (flag == 0)
		x1++;
	else if (flag == 1)
		y1++;
	z = map->z[(int)y][(int)x];
	z1 = map->z[(int)y1][(int)x1];
	color = map->color[(int)y][(int)x];
	zoom(&x, &y, &z, map->data);
	zoom(&x1, &y1, &z1, map->data);
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	shift(&x, &y, map->data);
	shift(&x1, &y1, map->data);
	step = return_max(return_mod(x1 - x), return_mod(y1 - y));
	x_inc = (x1 - x) / step;
	y_inc = (y1 - y) / step;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(map->fdf->mlx, map->fdf->win, x, y, color);
		x += x_inc;
		y += y_inc;
	}
}

void
	draw(t_map *map)
{
	int		x;
	int		y;
	int		flag;

	print_keys(map->fdf);
	y = 0;
	while (y < map->data->height - 1)
	{
		x = 0;
		while (x < map->data->width)
		{
			if (x < map->data->width - 1)
			{
				flag = 0;
				dda_algorithm(x, y, flag, map);
			}
			if (y < map->data->height - 1 && x != 0)
			{
				flag = 1;
				dda_algorithm(x, y, flag, map);
			}
			x++;
		}
		y++;
	}
}
