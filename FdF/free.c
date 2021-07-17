/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 10:46:04 by keokim            #+#    #+#             */
/*   Updated: 2021/07/17 10:46:08 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void
	free_int(int **arr, int height)
{
	int		i;

	i = 0;
	while (i < height)
		free(arr[i++]);
	free(arr);
}

void
	free_uint(unsigned int **arr, int height)
{
	int		i;

	i = 0;
	while (i < height)
		free(arr[i++]);
	free(arr);
}