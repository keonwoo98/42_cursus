#include "fdf.h"

void
	x_control(int keycode, t_map **map)
{
	if (keycode == NUM_1)
		(*map)->data->alpha -= 0.1;
	if (keycode == NUM_2)
		(*map)->data->alpha += 0.1;
}

void
	y_control(int keycode, t_map **map)
{
	if (keycode == NUM_3)
		(*map)->data->beta -= 0.1;
	if (keycode == NUM_4)
		(*map)->data->beta += 0.1;
}

void
	z_control(int keycode, t_map **map)
{
	if (keycode == NUM_5)
		(*map)->data->gamma -= 0.1;
	if (keycode == NUM_6)
		(*map)->data->gamma += 0.1;
}

void
	projection_control(int keycode, t_map **map)
{
	if (keycode == ISO)
	{
		reset_value(map);
		(*map)->data->iso = 1;
		zoom_init(map);
		shift_init(map);
	}
	if (keycode == PAR)
	{
		reset_value(map);
		(*map)->data->iso = 0;
		zoom_init(map);
		(*map)->data->shift_x =
			(*map)->data->win_width / 2 - (*map)->data->width * (*map)->data->zoom / 2;
		(*map)->data->shift_y =
			(*map)->data->win_height / 2 - (*map)->data->height * (*map)->data->zoom / 2;
	}
}
