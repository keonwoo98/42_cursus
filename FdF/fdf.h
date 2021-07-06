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
# include "./Get_Next_Line/get_next_line.h"
// # include <mlx.h>
# include "./minilibx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define KEY_ESC 53

typedef struct s_data
{
    void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}t_data;

#endif
