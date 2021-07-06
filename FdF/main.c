/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 11:38:43 by keokim            #+#    #+#             */
/*   Updated: 2021/07/05 11:38:46 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int
	key_press(int keycode, void *param)
{
    if (keycode == KEY_ESC)
        exit(0);
    return (0);
}

void
	fdf(void)
{
    void    *mlx;
    void    *win;
    void    *param;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 500, 500, "fdf");
    mlx_key_hook(win, key_press, param);
    mlx_loop(mlx);
}

int
	read_map(int fd)
{
	char	*line;
	t_list	lst;

	while (get_next_line(fd, &line) > 1)
	{
		parse_map(line, &lst);
		free(line);
		line = NULL;
	}
}

int
	parse_map(char *line, t_list *lst)
{
	
}

int
	main(int argc, char **argv)
{
	int		fd;

	if (argc < 2)
	{
		perror("Useage : ./fdf [File]");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Open fail");
		return (0);
	}
	read_map(fd);
}
