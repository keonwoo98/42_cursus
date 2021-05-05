/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keokim <keokim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 10:58:11 by keokim            #+#    #+#             */
/*   Updated: 2021/05/05 11:04:38 by keokim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*calloc(size_t count, size_t size)
{
	void	*cal;

	if (!(cal = malloc(count * size)))
		return (NULL);
	ft_bzero(cal, (count * size));
	return (cal);
}
