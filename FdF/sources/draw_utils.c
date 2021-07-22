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
	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	dst = fdf->addr + (y * fdf->line_length + x * (fdf->bpp / 8));
	*(unsigned int *)dst = color;
}

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

void
	print_keys(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 20, 20, 0x00cc00, "keokim's FdF");
	mlx_string_put(fdf->mlx, fdf->win, 20, 60, 0xffff00, "Exit : Esc");
	mlx_string_put(fdf->mlx, fdf->win, 20, 80, 0xffff00, "Zoom : + / -");
	mlx_string_put(fdf->mlx, fdf->win, 20, 100, 0xffff00, "Shift : Arrow Keys");
	mlx_string_put(fdf->mlx, fdf->win, 20, 120, 0xffff00, "Rotate x : 1 / 2");
	mlx_string_put(fdf->mlx, fdf->win, 20, 140, 0xffff00, "Rotate y : 3 / 4");
	mlx_string_put(fdf->mlx, fdf->win, 20, 160, 0xffff00, "Rotate z : 5 / 6");
	mlx_string_put(fdf->mlx, fdf->win, 20, 180, 0xffff00, "Isometric : I");
	mlx_string_put(fdf->mlx, fdf->win, 20, 200, 0xffff00, "Parallel : P");
}
