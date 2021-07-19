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
	// *x = (pre_x * cos(0.4636 * -1)) - (pre_y * sin(1.1071 * -1));
	// *y = (pre_x * sin(0.4636 * -1)) + (pre_y * cos(1.1071 * -1)) - z;
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

void
	print_keys(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 20, 20, 0xffffff, "Exit : Esc");
	mlx_string_put(fdf->mlx, fdf->win, 20, 40, 0xffffff, "Zoom : + / -");
	mlx_string_put(fdf->mlx, fdf->win, 20, 60, 0xffffff, "Shift : Arrow Keys");
	mlx_string_put(fdf->mlx, fdf->win, 20, 80, 0xffffff, "Rotate x : 1 / 2");
	mlx_string_put(fdf->mlx, fdf->win, 20, 100, 0xffffff, "Rotate y : 3 / 4");
	mlx_string_put(fdf->mlx, fdf->win, 20, 120, 0xffffff, "Rotate z : 5 / 6");
	mlx_string_put(fdf->mlx, fdf->win, 20, 140, 0xffffff, "Isometric : I");
	mlx_string_put(fdf->mlx, fdf->win, 20, 160, 0xffffff, "Parallel : P");
}
