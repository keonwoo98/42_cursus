#include "micro_paint.h"

int
	canva_check(FILE *file, t_canva *canva)
{
	int		ret;

	ret = fscanf(file, "%d %d %c\n", &canva->width, &canva->height, &canva->background);
	if (ret != 3)
		return (0);
	if (canva->width <= 0 || canva->width > 300 \
	|| canva->height <= 0 || canva->height > 300)
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

	if (shape.type == 'R')
	{
		while (y < canva.height)
		{
			x = 0;
			while (x < canva.width)
			{
				if (x >= shape.x && x <= shape.x + shape.width && y >= shape.y && y <= shape.y + shape.height)
					buffer[y][x] = shape.background;
				x++;
			}
			y++;
		}
	}
	else if (shape.type == 'r')
	{
		while (y < canva.height)
		{
			x = 0;
			while (x < canva.width)
			{
				if (x >= shape.x && x <= shape.x + shape.width && y >= shape.y && y <= shape.y + shape.height)
				{
					if (sqrtf(powf(x - shape.x, 2.0)) < 1 || sqrtf(powf(shape.x + shape.width - x, 2.0)) < 1 \
					|| sqrtf(powf(y - shape.y, 2.0)) < 1 || sqrtf(powf(shape.y + shape.height - y, 2.0)) < 1)
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

	while ((ret = fscanf(file, "%c %f %f %f %f %c\n", \
	&shape->type, &shape->x, &shape->y, &shape->width, &shape->height, &shape->background)) == 6)
	{
		if (shape->width <= 0.0 || shape->height <= 0.0)
			return (0);
		if (shape->type != 'R' && shape->type != 'r')
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
			printf("%c", buffer[i][j]);
		printf("\n");
	}
	free_buffer(canva, buffer);
	fclose(file);
	return (0);
}
