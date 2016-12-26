/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmaker.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 23:45:31 by ikryvenk          #+#    #+#             */
/*   Updated: 2016/12/24 00:12:08 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_read_from_file(int op)
{
	char	buf[22];
	int		rd;

	g_mas_y = ft_memalloc(sizeof(int) * 4);
	g_mas_x = ft_memalloc(sizeof(int) * 4);
	while ((rd = read(op, buf, 21)) == 21)
	{
		if (ft_validator(buf, rd))
			initialise_figure(&g_list, g_mas_x, g_mas_y, 4);
		else
			return (0);
		g_count++;
	}
	if (rd == 20)
	{
		if (ft_validator(buf, rd))
			initialise_figure(&g_list, g_mas_x, g_mas_y, 4);
		else
			return (0);
		g_count++;
	}
	else
		return (0);
	return (1);
}
