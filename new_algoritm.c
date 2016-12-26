/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_algoritm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 23:46:08 by ikryvenk          #+#    #+#             */
/*   Updated: 2016/12/24 17:08:31 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_dot	*intersection_search(int y, int x, t_dot *list)
{
	int	delta_y;
	int	delta_x;
	int	i;

	delta_y = y - list->y;
	delta_x = x - list->x;
	i = 0;
	while (i < 4)
	{
		if ((list->y + delta_y) >= g_map_size
				|| (list->x + delta_x) >= g_map_size
				|| g_field[list->y + delta_y][list->x + delta_x] != -1)
			return (NULL);
		if ((list->y + delta_y) < 0 || (list->x + delta_x) < 0)
			return (NULL);
		list = list->next;
		i++;
	}
	return (list);
}

void	write_figure(int y, int x, int number, t_dot *list)
{
	int	delta_y;
	int	delta_x;
	int	i;

	delta_y = y - list->y;
	delta_x = x - list->x;
	i = 0;
	while (i < 4)
	{
		g_field[list->y + delta_y][list->x + delta_x] = number;
		list = list->next;
		i++;
	}
}

int		find_figure(t_dot *list, int number)
{
	t_dot	*tmp;
	int		y;
	int		x;

	if (number == g_count)
		return (1);
	y = 0;
	while (y < g_map_size)
	{
		x = 0;
		while (x < g_map_size)
		{
			tmp = list;
			if ((tmp = intersection_search(y, x, tmp)))
			{
				write_figure(y, x, number, list);
				if (find_figure(tmp, number + 1))
					return (1);
				write_figure(y, x, -1, list);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		map_creater(void)
{
	t_dot	*list;
	int		number;

	number = 0;
	circulate(list = g_list);
	g_map_size = int_sqrt(g_count);
	g_field = NULL;
	ft_intarr();
	while (!find_figure(list, number))
	{
		ft_memdel(g_field);
		g_map_size++;
		ft_intarr();
	}
	ft_putintarr(g_field);
	return (0);
}
