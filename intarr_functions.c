/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intarr_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 23:46:27 by ikryvenk          #+#    #+#             */
/*   Updated: 2016/12/24 17:52:22 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_intarr(void)
{
	int	x;
	int	y;

	y = 0;
	g_field = (int**)malloc(sizeof(*g_field) * g_map_size);
	while (y < g_map_size)
		g_field[y++] = (int*)malloc(sizeof(int) * g_map_size);
	y = 0;
	while (y < g_map_size)
	{
		x = 0;
		while (x < g_map_size)
			g_field[y][x++] = -1;
		y++;
	}
}

void	ft_putintarr(int **arr)
{
	int y;
	int x;

	y = 0;
	while (y < g_map_size)
	{
		x = 0;
		while (x < g_map_size)
		{
			if (arr[y][x] == -1)
				ft_putstr(".");
			else
				ft_putchar('A' + arr[y][x]);
			x++;
		}
		y++;
		ft_putstr("\n");
	}
}
