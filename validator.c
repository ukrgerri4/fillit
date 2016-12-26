/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 23:45:43 by ikryvenk          #+#    #+#             */
/*   Updated: 2016/12/24 16:26:39 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_count_hashs(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		if (*str == '#')
			i++;
		str++;
	}
	if (i != 4)
		return (0);
	return (1);
}

static int	ft_characters_checker(char *str, int rd)
{
	int		i;
	int		j;

	j = 0;
	while (j < 20)
	{
		i = 0;
		while (*str && i < 4)
		{
			if (*str != '.' && *str != '#' && *str)
				return (0);
			str++;
			i++;
			j++;
		}
		if (*(str++) != '\n' && !*str)
			return (0);
		j++;
	}
	if (rd == 21 && *str != '\n')
		return (0);
	return (1);
}

static void	ft_write_coordinates(char *str)
{
	int *mas_x;
	int *mas_y;
	int x;
	int y;

	mas_y = g_mas_y;
	mas_x = g_mas_x;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 5)
		{
			if (*str == '#')
			{
				*mas_y++ = y;
				*mas_x++ = x;
			}
			x++;
			str++;
		}
		y++;
	}
}

static int	ft_figure_validator(char *str)
{
	int j;
	int i;
	int count;

	ft_write_coordinates(str);
	i = 0;
	count = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (mod(g_mas_y[i], g_mas_y[j]) + mod(g_mas_x[i], g_mas_x[j]) == 1)
				count++;
			j++;
		}
		i++;
	}
	if (count != 6 && count != 8)
		return (0);
	return (1);
}

int			ft_validator(char *str, int rd)
{
	if (!ft_count_hashs(str))
		return (0);
	if (!ft_characters_checker(str, rd))
		return (0);
	if (!ft_figure_validator(str))
		return (0);
	return (1);
}
