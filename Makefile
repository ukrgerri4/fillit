# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ikryvenk <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/16 16:01:16 by ikryvenk          #+#    #+#              #
#    Updated: 2016/12/24 17:54:11 by ikryvenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

WWW = -Wall -Wextra -Werror

OBJECTS = main.o strmaker.o validator.o new_algoritm.o help_functions.o intarr_functions.o libft_functions.o list_functions.o

all: $(NAME)

$(NAME): $(OBJECTS)
	gcc $(WWW) -o $(NAME) $(OBJECTS)

%.o: ./%.c
	gcc $(WWW) -o $@ -c $<

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
