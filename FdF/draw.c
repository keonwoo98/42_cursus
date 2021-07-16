#include "fdf.h"

float
	return_max(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

float
	return_mod(float a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

void
	isometric(float *x, float *y, int z)
{
	// *x = (*x - *y) * cos(PI / 4);
	// *y = (*x + *y) * sin(PI / 4) - z;
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

// void
// 	my_pixel_put(int x, int y, int color, t_map *map)
// {
// 	char	*dst;

// 	dst = map->fdf->data_addr + (y * map->fdf->size_line + x * (map->fdf->bits_per_pixel / 8));
// 	*(unsigned int *)dst = color;
// }

void
	dda_algorithm(float x, float y, float x1, float y1, t_data *data, t_map *map)
{
	float	x_inc;
	float	y_inc;
	int		step;
	int		z;
	int		z1;
	int		color;

	z = map->z[(int)y][(int)x];
	z1 = map->z[(int)y1][(int)x1];
	color = map->color[(int)y][(int)x];
	zoom(&x, &y, &z, data);
	zoom(&x1, &y1, &z1, data);
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	shift(&x, &y, data);
	shift(&x1, &y1, data);
	step = return_max(return_mod(x1 - x), return_mod(y1 - y));
	x_inc = (x1 - x) / step;
	y_inc = (y1 - y) / step;
	while ((int)(x - x1) || (int)(y - y1))
	{
		// my_pixel_put(x, y, color, map);
		mlx_pixel_put(map->fdf->mlx, map->fdf->win, x, y, color);
		x += x_inc;
		y += y_inc;
	}
}

void
	draw(t_data *data, t_map *map)
{
	int		x;
	int		y;

	print_keys(map->fdf);
	y = 0;
	while (y < data->height - 1)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				dda_algorithm(x, y, x + 1, y, data, map);
			if (y < data->height - 1 && x != 0)
				dda_algorithm(x, y, x, y + 1, data, map);
			x++;
		}
		y++;
	}
	// mlx_put_image_to_window(map->fdf->mlx, map->fdf->win, map->fdf->img, 0, 0);
}
