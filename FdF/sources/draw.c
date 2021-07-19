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
	init_dda(t_point point, t_dda *dda)
{
	dda->x = point.x;
	dda->y = point.y;
	if (point.flag == 0)
	{
		dda->x1 = point.x + 1;
		dda->y1 = point.y;
	}
	if (point.flag == 1)
	{
		dda->x1 = point.x;
		dda->y1 = point.y + 1;
	}
}

void
	get_data(t_dda *dda, t_map **map)
{
	dda->z = (*map)->z[(int)dda->y][(int)dda->x];
	dda->z1 = (*map)->z[(int)dda->y1][(int)dda->x1];
	dda->color = (*map)->color[(int)dda->y][(int)dda->x];
}

void
	dda_algorithm(t_dda *dda, t_map **map)
{
	int		steps;

	steps = 0;
	dda->step = ret_max(ret_abs(dda->x1 - dda->x), ret_abs(dda->y1 - dda->y));
	dda->x_inc = (dda->x1 - dda->x) / dda->step;
	dda->y_inc = (dda->y1 - dda->y) / dda->step;
	while (steps <= dda->step)
	{
		mlx_pixel_put((*map)->fdf->mlx, (*map)->fdf->win, \
			dda->x, dda->y, dda->color);
		dda->x += dda->x_inc;
		dda->y += dda->y_inc;
		steps++;
	}
}

void
	projection(t_point point, t_dda *dda, t_map **map)
{
	init_dda(point, dda);
	get_data(dda, map);
	zoom(dda, map);
	rotate_x(dda, map);
	rotate_y(dda, map);
	rotate_z(dda, map);
	if ((*map)->data->iso)
	{
		isometric(&dda->x, &dda->y, dda->z);
		isometric(&dda->x1, &dda->y1, dda->z1);
	}
	shift(dda, map);
}

void
	draw(t_map **map)
{
	t_point	point;
	t_dda	dda;

	print_keys((*map)->fdf);
	point.y = -1;
	while (++point.y < (*map)->data->height - 1)
	{
		point.x = -1;
		while (++point.x < (*map)->data->width)
		{
			if (point.x < (*map)->data->width - 1)
			{
				point.flag = 0;
				projection(point, &dda, map);
				dda_algorithm(&dda, map);
			}
			if (point.y < (*map)->data->height - 1 && point.x != 0)
			{
				point.flag = 1;
				projection(point, &dda, map);
				dda_algorithm(&dda, map);
			}
		}
	}
}
