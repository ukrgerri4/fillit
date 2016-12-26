/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 23:43:56 by ikryvenk          #+#    #+#             */
/*   Updated: 2016/12/24 19:54:09 by ikryvenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct		s_dot
{
	int				x;
	int				y;
	struct s_dot	*next;
}					t_dot;

int					g_map_size;
int					g_count;
int					*g_mas_y;
int					*g_mas_x;
int					**g_field;
t_dot				*g_list;

int					ft_read_from_file(int op);
int					ft_validator(char *str, int rd);
int					map_creater(void);
t_dot				*create_element(int x, int y);
void				initialise_figure(t_dot **begin_list,
		int *x, int *y, int size);
void				element_push_back(t_dot **begin_list, int x, int y);
void				circulate(t_dot *map_start);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_bzero(void *destination, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(int **ap);
int					int_sqrt(int count);
int					mod(int a, int b);
void				ft_error(void);
void				ft_intarr(void);
void				ft_putintarr(int **arr);
#endif
