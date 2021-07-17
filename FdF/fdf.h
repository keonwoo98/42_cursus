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
# include "./Libft/libft.h"
// # include <mlx.h>
# include "./minilibx/mlx.h"
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
}t_data;

typedef struct s_fdf
{
	void			*mlx;
	void			*win;
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
// void			zoom_shift_init(t_data **data);
t_fdf			*fdf_init(t_data *data);
void			draw(t_map **map);
void			zoom(t_dda *dda, t_map **map);
void			shift(t_dda *dda, t_map **map);
void			isometric(float *x, float *y, int z);
void			zoom_control(int keycode, t_map **map);
void			ud_shift_control(int keycode, t_map **map);
void			lr_shift_control(int keycode, t_map **map);
void			print_keys(t_fdf *fdf);
int				key_press(int keycode, t_map **map);
void			free_int(int **arr, int height);
void			free_uint(unsigned int **arr, int height);

#endif
