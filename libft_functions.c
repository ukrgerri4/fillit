/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 23:46:38 by ikryvenk          #+#    #+#             */
/*   Updated: 2016/12/24 00:14:31 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_memdel(int **ap)
{
	if (!ap)
		return ;
	free(*ap);
	*ap = NULL;
}

void	ft_bzero(void *destination, size_t n)
{
	unsigned char	*s;

	if (n != 0)
	{
		s = (unsigned char*)destination;
		while (n--)
		{
			*s = 0;
			s++;
		}
	}
}

void	*ft_memalloc(size_t size)
{
	void *result;

	if (!(result = malloc(size)))
		return (NULL);
	ft_bzero(result, size);
	return (result);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char const *s)
{
	if (s)
	{
		while (*s)
		{
			ft_putchar(*s);
			s++;
		}
	}
}
