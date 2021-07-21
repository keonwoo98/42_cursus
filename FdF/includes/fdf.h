/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 20:18:23 by keokim            #+#    #+#             */
/*   Updated: 2021/07/05 20:18:26 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>

# define WIN_WIDTH 1440
# define WIN_HIEGHT 900

# define ESC 53
# define PLUS 24
# define MINUS 27
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define NUM_1 18
# define NUM_2 19
# define NUM_3 20
# define NUM_4 21
# define NUM_5 23
# define NUM_6 22
# define ISO 34
# define PAR 35

# define PI 3.14159265

typedef struct s_data
{
	int				width;
	int				height;
	int				win_width;
	int				win_height;
	int				zoom;
	int				shift_x;
	int				shift_y;
	int				z_max;
	int				z_min;
	int				z_range;
	float			alpha;
	float			beta;
	float			gamma;
	int				iso;
}t_data;

typedef struct s_fdf
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
}t_fdf;

typedef struct s_map
{
	int				**z;
	unsigned int	**color;
	t_data			*data;
	t_fdf			*fdf;
}t_map;

typedef struct s_dda
{
	float			x;
	float			x1;
	float			y;
	float			y1;
	float			step;
	float			x_inc;
	float			y_inc;
	int				z;
	int				z1;
	unsigned int	color;
}t_dda;

typedef struct s_point
{
	float			x;
	float			y;
	int				flag;
}t_point;

void			print_error(char *msg);
float			ret_max(float a, float b);
float			ret_abs(float a);
int				get_next_line(int fd, char **line);
unsigned int	ft_atoi_base(char *nbr);
void			get_map_size(char **argv, t_data **data);
void			fill_z(t_map **map, char *line, int i);
void			get_z(char **argv, t_map **map);
void			fill_color(t_map **map, char *line, int i);
void			get_color(char **argv, t_map **map);
void			win_size(t_map **map);
void			zoom_init(t_map **map);
void			shift_init(t_map **map);
void			get_z_range(t_map **map);
void			win_size_init(t_map **map);
t_fdf			*fdf_init(t_data *data);
void			my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);
void			draw(t_map **map);
void			zoom(t_dda *dda, t_map **map);
void			shift(t_dda *dda, t_map **map);
void			isometric(float *x, float *y, int z);
void			rotate_x(t_dda *dda, t_map **map);
void			rotate_y(t_dda *dda, t_map **map);
void			rotate_z(t_dda *dda, t_map **map);
void			zoom_control(int keycode, t_map **map);
void			ud_shift_control(int keycode, t_map **map);
void			lr_shift_control(int keycode, t_map **map);
void			x_control(int keycode, t_map **map);
void			y_control(int keycode, t_map **map);
void			z_control(int keycode, t_map **map);
void			projection_control(int keycode, t_map **map);
void			reset_value(t_map **map);
void			print_keys(t_fdf *fdf);
int				key_press(int keycode, t_map **map);

#endif
