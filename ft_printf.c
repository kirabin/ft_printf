/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 09:56:21 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/19 19:51:05 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_format		default_format(void)
{
	t_format format;
	
	format.width = 0;
	format.precision = -1;
	format.left_aligned = 0;
	format.is_negative = 0;
	format.alternate_form = 0;
	format.add_blank = 0;
	format.add_sign = 0;
	format.fill = ' ';
	format.type = '\0';
	format.length = 'n';
	format.arg_len = 0;
	return(format);
}

static t_print		default_print(void)
{
	t_print		print;
	
	print.char_printed = 0;
	return (print);
}


static const char		*strip_format(t_print *print, const char *format_string)
{
	while (*format_string && !print->format.type)
	{
		if (*format_string == '-')
			print->format.left_aligned = 1;
		else if (*format_string == '0')
			print->format.fill = '0';
		else if (*format_string == '#')
			print->format.alternate_form = 1;
		else if (*format_string == ' ')
			print->format.add_blank = 1;
		else if (*format_string == '+')
			print->format.add_sign = 1;
		else if (*format_string == '*')
			print->format.width = va_arg(print->valist, int);
		else if (ft_isdigit(*format_string))
		{
			print->format.width = ft_atoi(format_string);
			format_string = ft_strskip(format_string, ft_isdigit) - 1;
		}
		else if (*format_string == '.')
		{
			print->format.precision = ft_atoi(++format_string);
			format_string = ft_strskip(format_string, ft_isdigit) - 1;
		}
		else if (ft_strchr("lh", *format_string))
			print->format.length = *format_string;
		else if (ft_strchr("llhh", *format_string))
		{
			print->format.length = (*format_string == 'l') ? 'L' : 'H';
			format_string++;
		}
		else if (ft_strchr("cspdiuxX%", *format_string))
			print->format.type = *format_string;
		else
			break;
		format_string++;
	}
	return (format_string);
}


static void			print_format(t_print *print)
{
	if (print->format.type == 'c')
		print_c(print);
	else if (print->format.type == 's')
		print_s(print);
	else if (print->format.type == 'p')
		print_p(print);
	else if (print->format.type == 'd' || print->format.type == 'i')
		print_di(print);
	else if (print->format.type == 'u')
		print_u(print);
	else if (print->format.type == 'x')
		print_x(print, 0);
	else if (print->format.type == 'X')
		print_x(print, 1);
	else if (print->format.type == '%')
		print_percent(print);
	// else if (print->format.type == 'n')
	// 	print_n(print, 1);
	// else if (print->format.type == 'f')
	// 	print_f(print, 1);
	// else if (print->format.type == 'g')
	// 	print_g(print, 1);
	// else if (print->format.type == 'e')
	// 	print_e(print, 1);
}


int					ft_printf(const char *format_string, ...)  // is format allowed ? 
{
	t_print 	print;

	print = default_print();
	va_start(print.valist, format_string);
	if (!format_string)
		return (0);
	while (*format_string)
	{
		if (*format_string == '%')
		{
			print.format = default_format();
			format_string = strip_format(&print, ++format_string);
			print_format(&print);
		}
		else
		{
			ft_putchar_fd(*format_string, 1);
			print.char_printed++;
			format_string++;
		}
	}	
	va_end(print.valist);
	return (print.char_printed);
}



