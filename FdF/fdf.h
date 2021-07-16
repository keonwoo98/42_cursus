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
# define ARR_UP 126
# define ARR_DOWN 125
# define ARR_LEFT 123
# define ARR_RIGHT 124
# define NUM_1 18
# define NUM_2 19
# define NUM_3 20
# define NUM_4 21
# define NUM_5 23
# define NUM_6 22
# define PLUS 24
# define MINUS 27

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
	int				z_range;
}t_data;

typedef struct s_fdf
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}t_fdf;

typedef struct s_map
{
	int				**z;
	unsigned int	**color;
	t_fdf			*fdf;
}t_map;

void			print_error(char *msg);
int				get_next_line(int fd, char **line);
unsigned int	ft_atoi_base(char *nbr);
void			get_z_range(t_data **data, t_map *map);
void			win_size_init(t_data **data);
void			zoom_shift_init(t_data **data);
t_fdf			*fdf_init(t_data *data);
void			draw(t_data *data, t_map *map);
void			print_keys(t_fdf *fdf);

#endif
