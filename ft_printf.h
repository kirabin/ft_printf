/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:01:50 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/18 19:26:39 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>  // delete on push
# include "libft/libft.h"

typedef int			bool;  // why write 2x times?

// %[flags][width][.precision]type
typedef struct		s_format
{
	int				width;
	int				precision;     // .
	bool			left_aligned;  // -
	char			fill;
	char			type;
	// void			*value;        // string representation of printed element
}					t_format;

typedef struct		s_print
{
	int				char_printed;  // excluding \0 of strings 
	va_list			valist;
	t_format		format;
}					t_print;


int		ft_printf(const char *format, ...);
void	fill_width(char fill, int n);
void	print_c(t_print *print);

#endif