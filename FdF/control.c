#include "fdf.h"

int
	key_press(int keycode, t_map **map)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == PLUS || keycode == MINUS)
		zoom_control(keycode, map);
	if (keycode == UP || keycode == DOWN)
		ud_shift_control(keycode, map);
	if (keycode == LEFT || keycode == RIGHT)
		lr_shift_control(keycode, map);
	return (0);
}

void
	zoom_control(int keycode, t_map **map)
{
	if (keycode == PLUS)
	{
		mlx_clear_window((*map)->fdf->mlx, (*map)->fdf->win);
		(*map)->data->zoom++;
		draw(map);
	}
	if (keycode == MINUS)
	{
		mlx_clear_window((*map)->fdf->mlx, (*map)->fdf->win);
		if ((*map)->data->zoom > 0)
			(*map)->data->zoom--;
		draw(map);
	}
}

void
	ud_shift_control(int keycode, t_map **map)
{
	if (keycode == UP)
	{
		mlx_clear_window((*map)->fdf->mlx, (*map)->fdf->win);
		(*map)->data->shift_y -= 30;
		draw(map);
	}
	if (keycode == DOWN)
	{
		mlx_clear_window((*map)->fdf->mlx, (*map)->fdf->win);
		(*map)->data->shift_y += 30;
		draw(map);
	}
}

void
	lr_shift_control(int keycode, t_map **map)
{
	if (keycode == LEFT)
	{
		mlx_clear_window((*map)->fdf->mlx, (*map)->fdf->win);
		(*map)->data->shift_x -= 30;
		draw(map);
	}
	if (keycode == RIGHT)
	{
		mlx_clear_window((*map)->fdf->mlx, (*map)->fdf->win);
		(*map)->data->shift_x += 30;
		draw(map);
	}
}
