/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:01:50 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/22 16:32:52 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct		s_format
{
	int				arg_len;
	char			*arg_s;
	int				width;
	int				precision;
	t_bool			precision_given;
	t_bool			left_aligned;
	t_bool			alternate_form;
	char			fill;
	char			sign;
	char			type;
	char			length;
}					t_format;

typedef struct		s_print
{
	int				printed;
	va_list			valist;
	t_format		f;
}					t_print;

int					ft_printf(const char *format, ...);
void				fill_width(char fill, int n);
void				print_c(t_print *print);
void				print_s(t_print *print);
void				print_p(t_print *print);
int					print_di(t_print *print);
int					print_u(t_print *print);
void				print_x(t_print *print, t_bool is_upper);
void				print_percent(t_print *print);
t_print				default_print(void);
t_format			default_format(void);
const char			*get_f_length(t_print *print, const char *format_string);

#endif
