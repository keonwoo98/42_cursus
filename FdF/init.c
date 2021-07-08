#include "fdf.h"

t_fdf
	*fdf_init(void)
{
    t_fdf	*fdf;

	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		print_error("Malloc error");
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, 1000, 800, "fdf");
	// fdf->img = mlx_new_image(fdf->mlx, 1920, 1080);
	// fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel), &(fdf->size_line), &(fdf->endian));
	return (fdf);
}
