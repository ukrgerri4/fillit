/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 23:45:22 by ikryvenk          #+#    #+#             */
/*   Updated: 2016/12/24 19:55:50 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		main(int argc, char **argv)
{
	int		op;

	g_list = NULL;
	g_count = 0;
	if (argc == 2)
	{
		if ((op = open(argv[1], O_RDONLY)) != -1)
		{
			if (!(ft_read_from_file(op)))
				ft_error();
			else if (g_count > 26)
				ft_error();
			map_creater();
		}
		else
			ft_error();
	}
	else
		ft_putstr("usage: ./fillit file_name\n");
	return (0);
}
