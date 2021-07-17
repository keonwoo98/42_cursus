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

# define KEY_ESC 53

# define PI 3.14159265

typedef struct s_data
{
    int				width;
	int				height;
	int				zoom;
	int				shift_x;
	int				shift_y;
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

void			print_error(char *msg);
float			return_max(float a, float b);
float			return_mod(float a);
int				get_next_line(int fd, char **line);
unsigned int	ft_atoi_base(char *nbr);
void			get_map_size(char **argv, t_data **data);
void			fill_z(t_map **map, char *line, int i);
void			get_z(char **argv, t_map **map);
void			fill_color(t_map **map, char *line, int i);
void			get_color(char **argv, t_map **map);
void			get_z_range(t_map **map);
void			win_size_init(t_data **data);
void			zoom_shift_init(t_data **data);
t_fdf			*fdf_init(t_data *data);
void			draw(t_map *map);
void			print_keys(t_fdf *fdf);
void			free_int(int **arr, int height);
void			free_uint(unsigned int **arr, int height);

#endif
