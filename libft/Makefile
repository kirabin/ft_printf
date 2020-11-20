# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/28 11:34:55 by dmilan            #+#    #+#              #
#    Updated: 2020/11/20 16:01:46 by dmilan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME      = libft.a
HEADER    = libft.h
CCFLAGS   = -Wall -Wextra -Werror
# SRC       = $(wildcard ./ft_*.c)
SRC       = ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isblank.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_isspace.c \
			ft_itoa.c \
			ft_uitoa.c \
			ft_leni.c \
			ft_lenui.c \
			ft_lenui_hex.c \
			ft_lenul_hex.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstfind.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstmerge.c \
			ft_lstnew.c \
			ft_lstrev.c \
			ft_lstsize.c \
			ft_max.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memset.c \
			ft_min.c \
			ft_putc_fd.c \
			ft_putuc_fd.c \
			ft_puti_fd.c \
			ft_putstr_fd.c \
			ft_putstrn_fd.c \
			ft_putui_fd.c \
			ft_putui_hex_fd.c \
			ft_putul_hex_fd.c \
			ft_split.c \
			ft_strchr.c \
			ft_strcount.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strjoinfree.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strmapi.c \
			ft_strncmp.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_strskip.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_swapi.c
OBJ       = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

%.o: %.c $(HEADER)
	gcc -c $(CCFLAGS) $<

$(NAME): $(OBJ) 
	ar -rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

build: $(NAME)
	gcc -g $(CCFLAGS) main.c -L. -lft