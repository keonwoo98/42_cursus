#include "fdf.h"

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
	(*map)->data->z_range = max - min;
}

void
	zoom_shift_z_init(t_data **data)
{

	if ((*data)->z_range >= 15 && (*data)->z_range < 50 && (*data)->width < 200)
		(*data)->zoom = 20;
	else if ((*data)->z_range >= 50 && (*data)->z_range < 100 && (*data)->width <= 200)
	{
		(*data)->zoom = 12;
		(*data)->shift_y += 200;
	}
	else if ((*data)->z_range >= 100 && (*data)->z_range < 200 && (*data)->width <= 20)
	{
		(*data)->zoom = 7;
		(*data)->shift_x += 250;
		(*data)->shift_y -= 100;
	}
	else if ((*data)->z_range >= 100 && (*data)->z_range < 200 && (*data)->width == 100)
	{
		(*data)->zoom = 4;
		(*data)->shift_x *= 2.5;
		(*data)->shift_y += 250;
	}
	else if ((*data)->z_range >= 200)
	{
		(*data)->zoom = 2;
		(*data)->shift_x *= 6;
		(*data)->shift_y += 90;
	}
}

void
	zoom_shift_init(t_data **data)
{
	(*data)->shift_x = WIN_WIDTH / 4;
	(*data)->shift_y = WIN_HIEGHT / 1.7;
	if ((*data)->width <= 11)
		(*data)->zoom = WIN_WIDTH / (*data)->width / 4;
	else if ((*data)->width < 50)
		(*data)->zoom = WIN_WIDTH / (*data)->width / 3;
	else if ((*data)->width <= 100)
	{
		(*data)->zoom = WIN_WIDTH / (*data)->width / 2;
		(*data)->shift_x = WIN_WIDTH / 10;
		(*data)->shift_y = WIN_HIEGHT / 2;
	}
	else if ((*data)->width <= 200)
	{
		(*data)->zoom = WIN_WIDTH / (*data)->width / 1.3;
		(*data)->shift_x = WIN_WIDTH / 25;
		(*data)->shift_y = WIN_HIEGHT / 1.5;
	}
	else
	{
		(*data)->zoom = WIN_WIDTH / (*data)->width;
		(*data)->shift_x = -120;
		(*data)->shift_y = WIN_HIEGHT / 1.7;
	}
	zoom_shift_z_init(data);
}

t_fdf
	*fdf_init(t_data *data)
{
    t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		print_error("Malloc error");
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_WIDTH, WIN_HIEGHT, "fdf");
	return (fdf);
}
