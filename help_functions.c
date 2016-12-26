/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 23:46:21 by ikryvenk          #+#    #+#             */
/*   Updated: 2016/12/24 19:54:43 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		int_sqrt(int count)
{
	int	i;
	int	nb;

	i = 1;
	nb = 0;
	while (nb < (count * 4))
	{
		nb = i * i;
		if (nb < count * 4)
			i++;
	}
	return (i);
}

int		mod(int a, int b)
{
	int	val;

	val = 0;
	if (a - b < 0)
		val = (a - b) * -1;
	else
		val = (a - b);
	return (val);
}

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(0);
}
