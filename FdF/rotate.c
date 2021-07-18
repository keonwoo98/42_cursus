#include "fdf.h"

void
	rotate_x(t_dda *dda, t_map **map)
{
	float	y;
	float	y1;

	y = dda->y;
	y1 = dda->y1;
	dda->y = y * cos((*map)->data->alpha) - dda->z * sin((*map)->data->alpha);
	dda->y1 = y1 * cos((*map)->data->alpha) - dda->z1 * sin((*map)->data->alpha);
	dda->z = y * sin((*map)->data->alpha) + dda->z * cos((*map)->data->alpha);
	dda->z1 = y1 * sin((*map)->data->alpha) + dda->z1 * cos((*map)->data->alpha);
}

void
	rotate_y(t_dda *dda, t_map **map)
{
	float	x;
	float	x1;

	x = dda->x;
	x1 = dda->x1;
	dda->x = x * cos((*map)->data->beta) + dda->z * sin((*map)->data->beta);
	dda->x1 = x1 * cos((*map)->data->beta) + dda->z1 * sin((*map)->data->beta);
	dda->z = -x * sin((*map)->data->beta) + dda->z * cos((*map)->data->beta);
	dda->z1 = -x1 * sin((*map)->data->beta) + dda->z1 * cos((*map)->data->beta);
}

void
	rotate_z(t_dda *dda, t_map **map)
{
	float	x;
	float	x1;

	x = dda->x;
	x1 = dda->x1;
	dda->x = x * cos((*map)->data->gamma) - dda->y * sin((*map)->data->gamma);
	dda->x1 = x1 * cos((*map)->data->gamma) - dda->y1 * sin((*map)->data->gamma);
	dda->y = x * sin((*map)->data->gamma) + dda->y * cos((*map)->data->gamma);
	dda->y1 = x1 * sin((*map)->data->gamma) + dda->y1 * cos((*map)->data->gamma);
}
