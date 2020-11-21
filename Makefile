# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 14:39:50 by dmilan            #+#    #+#              #
#    Updated: 2020/11/21 13:25:57 by dmilan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME      = libftprintf.a
LIB       = libft/libft.a
FLAGS     = -Wall -Wextra -Werror
SRC       = fill_width.c \
			ft_printf.c \
			ft_printf_support.c \
			print_c.c \
			print_di.c \
			print_p.c \
			print_s.c \
			print_u.c \
			print_x.c \
			print_percent.c
OBJ       = $(SRC:.c=.o)
HEADER    = ft_printf.h

all: $(NAME)

$(LIB):
	make all -C libft/

$(NAME): $(OBJ) $(LIB)
	ar -rc $(NAME) $(OBJ) libft/*.o
	ranlib $(NAME)

build:
	gcc $(FLAGS) main.c $(SRC) -lftprintf -L.
	./a.out

%.o: %.c $(HEADER)
	gcc -g -c $(FLAGS) $<

clean:
	$(MAKE) clean -C libft/
	rm -f $(OBJ)

fclean: clean
	$(MAKE) fclean -C libft/
	rm -f $(NAME)

re: fclean all

run: 
	./$(NAME)