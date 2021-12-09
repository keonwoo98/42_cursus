#ifndef MICRO_PAINT_H
# define MICRO_PAINT_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_canva
{
	int			width;
	int			height;
	char		background;
}t_canva;

typedef struct s_shape
{
	char		type;
	float		x;
	float		y;
	float		width;
	float		height;
	char		background;
}t_shape;

#endif
