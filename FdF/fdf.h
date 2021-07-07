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
# include <mlx.h>
// # include "./minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define KEY_ESC 53

typedef struct s_data
{
    int				width;
	int				height;
}t_data;

typedef struct s_map
{
	int				**z;
	unsigned int	**color;
}t_map;

int				get_next_line(int fd, char **line);
unsigned int	ft_atoi_base(char *nbr);

#endif
