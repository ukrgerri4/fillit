/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 23:46:45 by ikryvenk          #+#    #+#             */
/*   Updated: 2016/12/24 00:05:48 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_dot	*create_element(int x, int y)
{
	t_dot *result;

	result = (t_dot*)malloc(sizeof(t_dot));
	if (result)
	{
		result->x = x;
		result->y = y;
		result->next = NULL;
	}
	return (result);
}

void	element_push_back(t_dot **begin_list, int x, int y)
{
	t_dot	*result;

	result = *begin_list;
	if (result)
	{
		while (result->next)
			result = result->next;
		result->next = create_element(x, y);
	}
	else
		*begin_list = create_element(x, y);
}

void	initialise_figure(t_dot **begin_list, int *x, int *y, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		element_push_back(begin_list, x[i], y[i]);
		i++;
	}
}

void	circulate(t_dot *map_start)
{
	t_dot	*current_element;

	current_element = map_start;
	while (current_element->next)
		current_element = current_element->next;
	current_element->next = map_start;
}
