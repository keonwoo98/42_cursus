/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 18:10:25 by keokim            #+#    #+#             */
/*   Updated: 2021/07/17 18:10:29 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "./Libft/libft.h"

int
	key_press(int keycode, t_map **map)
{
	if (keycode == ESC)
		exit(0);
	mlx_clear_window((*map)->fdf->mlx, (*map)->fdf->win);
	ft_bzero((*map)->fdf->addr, (*map)->data->win_width * \
		(*map)->data->win_height * ((*map)->fdf->bpp / 8));
	if (keycode == PLUS || keycode == MINUS)
		zoom_control(keycode, map);
	if (keycode == UP || keycode == DOWN)
		ud_shift_control(keycode, map);
	if (keycode == LEFT || keycode == RIGHT)
		lr_shift_control(keycode, map);
	if (keycode == NUM_1 || keycode == NUM_2)
		x_control(keycode, map);
	if (keycode == NUM_3 || keycode == NUM_4)
		y_control(keycode, map);
	if (keycode == NUM_5 || keycode == NUM_6)
		z_control(keycode, map);
	if (keycode == ISO || keycode == PAR)
		projection_control(keycode, map);
	draw(map);
	print_keys((*map)->fdf);
	return (0);
}

void
	zoom_control(int keycode, t_map **map)
{
	if (keycode == PLUS)
		(*map)->data->zoom++;
	if (keycode == MINUS)
		if ((*map)->data->zoom > 0)
			(*map)->data->zoom--;
}

void
	ud_shift_control(int keycode, t_map **map)
{
	if (keycode == UP)
		(*map)->data->shift_y -= 30;
	if (keycode == DOWN)
		(*map)->data->shift_y += 30;
}

void
	lr_shift_control(int keycode, t_map **map)
{
	if (keycode == LEFT)
		(*map)->data->shift_x -= 30;
	if (keycode == RIGHT)
		(*map)->data->shift_x += 30;
}
