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
	init_dda(float x, float y, int flag, t_dda *dda)
{
	dda->x = x;
	dda->y = y;
	if (flag == 0)
	{
		dda->x1 = x + 1;
		dda->y1 = y;
	}
	if (flag == 1)
	{
		dda->x1 = x;
		dda->y1 = y + 1;
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
	dda_algorithm(float x, float y, int flag, t_map **map)
{
	t_dda	dda;

	init_dda(x, y, flag, &dda);
	get_data(&dda, map);
	zoom(&dda, map);
	isometric(&dda.x, &dda.y, dda.z);
	isometric(&dda.x1, &dda.y1, dda.z1);
	shift(&dda, map);
	dda.step = ret_max(ret_abs(dda.x1 - dda.x), ret_abs(dda.y1 - dda.y));
	dda.x_inc = (dda.x1 - dda.x) / dda.step;
	dda.y_inc = (dda.y1 - dda.y) / dda.step;
	while ((int)(dda.x - dda.x1) || (int)(dda.y - dda.y1))
	{
		mlx_pixel_put((*map)->fdf->mlx, (*map)->fdf->win, dda.x, dda.y, dda.color);
		dda.x += dda.x_inc;
		dda.y += dda.y_inc;
	}
}

void
	draw(t_map **map)
{
	int		x;
	int		y;
	int		flag;

	print_keys((*map)->fdf);
	y = 0;
	while (y < (*map)->data->height - 1)
	{
		x = 0;
		while (x < (*map)->data->width)
		{
			if (x < (*map)->data->width - 1)
			{
				flag = 0;
				dda_algorithm(x, y, flag, map);
			}
			if (y < (*map)->data->height - 1 && x != 0)
			{
				flag = 1;
				dda_algorithm(x, y, flag, map);
			}
			x++;
		}
		y++;
	}
}
