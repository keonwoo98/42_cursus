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
	*x = (*x - *y) * cos(PI / 4);
	*y = (*x + *y) * sin(PI / 4) - z;
}

void
	zoom(float *x, float *y, int *z)
{
	int		zoom;

	zoom = 20;
	*x *= zoom;
	*y *= zoom;
	*z *= zoom;
}

void
	move(float *x, float *y, int *z)
{
	int		move;

	move = 400;
	*x += move;
	*y += move;
	*z += move;
}

void
	dda_algorithm(float x, float y, float x1, float y1, t_fdf *fdf, t_map *map)
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
	// color = (z) ? 0xe80c0c : 0xffffff;
	zoom(&x, &y, &z);
	zoom(&x1, &y1, &z1);
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	move(&x, &y, &z);
	move(&x1, &y1, &z1);
	step = return_max(return_mod(x1 - x), return_mod(y1 - y));
	x_inc = (x1 - x) / step;
	y_inc = (y1 - y) / step;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(fdf->mlx, fdf->win, x, y, color);
		x += x_inc;
		y += y_inc;
	}
}

void
	draw(t_data *data, t_map *map, t_fdf *fdf)
{
	int		x;
	int		y;

	print_keys(fdf);
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				dda_algorithm(x, y, x + 1, y, fdf, map);
			if (y < data->height - 1)
				dda_algorithm(x, y, x, y + 1, fdf, map);
			x++;
		}
		y++;
	}
}
