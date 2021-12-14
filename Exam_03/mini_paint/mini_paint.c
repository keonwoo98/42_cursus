#include "mini_paint.h"

int
	canva_check(FILE *file, t_canva *canva)
{
	int		ret;

	ret = fscanf(file, "%d %d %c\n", &canva->width, &canva->height, &canva->background);
	if (ret != 3)
		return (0);
	if (canva->width <= 0 || canva->width > 300 || canva->height <= 0 || canva->height > 300)
		return (0);
	if (ret == -1)
		return (0);
	return (1);
}

char
	**background_draw(t_canva canva)
{
	int		i;
	int		j;
	int		k;
	char	**buffer;

	buffer = malloc(sizeof(*buffer) * canva.height + 1);
	for (k = 0; k < canva.height; k++)
		buffer[k] = malloc(sizeof(**buffer) * canva.width);
	buffer[k] = 0;
	for (i = 0; i < canva.height; i++)
	{
		for (j = 0; j < canva.width; j++)
			buffer[i][j] = canva.background;
	}
	return (buffer);
}

void
	shape_draw(char **buffer, t_shape shape, t_canva canva)
{
	int		x;
	int		y = 0;
	float	distance;

	if (shape.type == 'C')
	{
		while (y < canva.height)
		{
			x = 0;
			while (x < canva.width)
			{
				distance = sqrtf(powf(x - shape.x, 2.0) + powf(y - shape.y, 2.0));
				if (distance <= shape.radius)
					buffer[y][x] = shape.background;
				x++;
			}
			y++;
		}
	}
	else if (shape.type == 'c')
	{
		while (y < canva.height)
		{
			x = 0;
			while (x < canva.width)
			{
				distance = sqrtf(powf(x - shape.x, 2.0) + powf(y - shape.y, 2.0));
				if (distance <= shape.radius)
				{
					if (shape.radius - distance < 1.0)
						buffer[y][x] = shape.background;
				}
				x++;
			}
			y++;
		}
	}
}

int
	draw_check(t_shape *shape, FILE *file, char **buffer, t_canva canva)
{
	int		ret;

	while ((ret = fscanf(file, "%c %f %f %f %c\n", &shape->type, &shape->x, &shape->y, &shape->radius, &shape->background)) == 5)
	{
		if (shape->radius <= 0)
			return (0);
		if (shape->type != 'C' && shape->type != 'c')
			return (0);
		shape_draw(buffer, *shape, canva);
	}
	if (ret != -1)
		return (0);
	return (1);
}

void
	free_buffer(t_canva canva, char **buffer)
{
	for (int i = 0; i < canva.height; i++)
		free(buffer[i]);
	free(buffer);
}

int
	main(int argc, char **argv)
{
	FILE		*file;
	t_canva		canva;
	t_shape		shape;
	char		**buffer;

	if (argc != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	if (!(file = fopen(argv[1], "r")))
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	if (!canva_check(file, &canva))
	{
		write(1, "Error: Operation file corrupted\n", 32);
		fclose(file);
		return (1);
	}
	buffer = background_draw(canva);
	if (!draw_check(&shape, file, buffer, canva))
	{
		write(1, "Error: Operation file corrupted\n", 32);
		free_buffer(canva, buffer);
		fclose(file);
		return (1);
	}
	for (int i = 0; i < canva.height; i++)
	{
		for (int j = 0; j < canva.width; j++)
			write(1, &buffer[i][j], 1);
		write(1, "\n", 1);
	}
	free_buffer(canva, buffer);
	fclose(file);
	return (0);
}
