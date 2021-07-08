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
	*x = (*x - *y) * cos(0.523599);
	*y = (*x + *y) * sin(0.523599) - z;
}

void
	bresenham(float x, float y, float x1, float y1, t_fdf *fdf, t_map *map)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;
	int		color;

	z = map->z[(int)y][(int)x];
	z1 = map->z[(int)y1][(int)x1];
	x *= 30;
	y *= 30;
	x1 *= 30;
	y1 *= 30;
	color = (z || z1) ? 0xe80c0c : 0xffffff;
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	// x *= 2;
	// y *= 2;
	// x1 *= 2;
	// y1 *= 2;
	x_step = x1 - x;
	y_step = y1 - y;
	max = return_max(return_mod(x_step), return_mod(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(fdf->mlx, fdf->win, x, y, color);
		x += x_step;
		y += y_step;
	}
}

void
	draw(t_data *data, t_map *map, t_fdf *fdf)
{
	int		x;
	int		y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(x, y, x + 1, y, fdf, map);
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, fdf, map);
			x++;
		}
		y++;
	}
}
