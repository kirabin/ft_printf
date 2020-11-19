/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:01:50 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/19 19:49:04 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>  // delete on push
# include "libft/libft.h"

typedef struct		s_format
{
	int				width;
	int				precision;
	bool			left_aligned;
	bool			is_negative;
	bool			alternate_form;
	bool			add_blank;
	bool			add_sign;
	char			fill;
	char			type;
	int				length;		// 'n' 'l' 'L' 'h' 'H'
	int				arg_len;
}					t_format;

typedef struct		s_print
{
	int				char_printed;  // excluding \0 of strings
	va_list			valist;
	t_format		format;
}					t_print;

int					ft_printf(const char *format, ...);
void				fill_width(char fill, int n);
void				print_c(t_print *print);
void				print_s(t_print *print);
void				print_p(t_print *print);
void				print_di(t_print *print);
void				print_u(t_print *print);
void				print_x(t_print *print, bool is_upper);
void				print_percent(t_print *print);

#endif
