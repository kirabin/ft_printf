# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 14:39:50 by dmilan            #+#    #+#              #
#    Updated: 2020/11/18 19:31:49 by dmilan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
FLAGS = -Wall -Wextra -Werror

all: $(NAME)
	gcc -g *.c -Llibft -lft          # remove g flag
	./$(NAME)
	
fclean:
	rm $(NAME)

lib_all: 
	make -f libft/Makefile

lib_re:
	make

re: fclean all