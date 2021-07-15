#include "fdf.h"

void
	win_size_init(t_data **data)
{
	if ((*data)->width <= 11)
	{
		(*data)->win_width = 640;
		(*data)->win_height = 480;
	}
	else if ((*data)->width <= 100)
	{
		(*data)->win_width = 960;
		(*data)->win_height = 600;
	}
	else if ((*data)->width <= 200)
	{
		(*data)->win_width = 1280;
		(*data)->win_height = 720;
	}
	else
	{
		(*data)->win_width = 1440;
		(*data)->win_height = 900;
	}
}

void
	zoom_shift_init(t_data **data)
{
	if ((*data)->width <= 11)
	{
		// (*data)->zoom = ceil((*data)->win_width / (*data)->width / 3);
		(*data)->zoom = (*data)->win_width / (*data)->width / 3;
		(*data)->shift_x = (*data)->win_width / 4;
		(*data)->shift_y = (*data)->win_height / 1.5;
	}
	else if ((*data)->width <= 100)
	{
		// (*data)->zoom = ceil((*data)->win_width / (*data)->width / 2);
		(*data)->zoom = (*data)->win_width / (*data)->width / 2.5;
		(*data)->shift_x = (*data)->win_width / 4;
		(*data)->shift_y = (*data)->win_height / 1.5;
	}
	else if ((*data)->width <= 200)
	{
		// (*data)->zoom = ceil((*data)->win_width / (*data)->width);
		(*data)->zoom = (*data)->win_width / (*data)->width / 1.5;
		(*data)->shift_x = (*data)->win_width / 7;
		(*data)->shift_y = (*data)->win_height / 1.5;
	}
	else
	{
		(*data)->zoom = (*data)->win_width / (*data)->width;
		(*data)->shift_x = -120;
		(*data)->shift_y = (*data)->win_height / 1.7;
	}
}

t_fdf
	*fdf_init(t_data *data)
{
    t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		print_error("Malloc error");
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, data->win_width, data->win_height, "fdf");
	// fdf->img = mlx_new_image(fdf->mlx, data->win_width, data->win_height);
	// fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel), &(fdf->size_line), &(fdf->endian));
	return (fdf);
}
