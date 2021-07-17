/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:10:59 by keokim            #+#    #+#             */
/*   Updated: 2021/07/17 18:11:03 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void
	isometric(float *x, float *y, int z)
{
	float	pre_x;
	float	pre_y;

	pre_x = *x;
	pre_y = *y;
	*x = (pre_x * cos(PI / 6 * -1)) - (pre_y * sin(PI / 3 * -1));
	*y = (pre_x * sin(PI / 6 * -1)) + (pre_y * cos(PI / 3 * -1)) - z;
}

void
	zoom(t_dda *dda, t_map **map)
{
	dda->x *= (*map)->data->zoom;
	dda->y *= (*map)->data->zoom;
	dda->z *= (*map)->data->zoom;
	dda->x1 *= (*map)->data->zoom;
	dda->y1 *= (*map)->data->zoom;
	dda->z1 *= (*map)->data->zoom;
}

void
	shift(t_dda *dda, t_map **map)
{
	dda->x += (*map)->data->shift_x;
	dda->y += (*map)->data->shift_y;
	dda->x1 += (*map)->data->shift_x;
	dda->y1 += (*map)->data->shift_y;
}
