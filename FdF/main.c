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

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY_ESC 53

int     key_press(int keycode, void *param)
{
    if (keycode == KEY_ESC)
        exit(0);
    return (0);
}

int     main(void)
{
    void    *mlx;
    void    *win;
    void    *param;

    mlx = mlx_init();
    win = mlx_new_window(mlx, 500, 500, "FdF");
    mlx_key_hook(win, key_press, param);
    mlx_loop(mlx);
}
