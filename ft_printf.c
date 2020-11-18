/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 09:56:21 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/18 19:52:40 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_print		default_print(void)
{
	t_print		print;
	
	print.char_printed = 0;
	print.format.width = 0;
	print.format.precision = 0;
	print.format.left_aligned = 0;
	print.format.fill = ' ';
	print.format.type = '\0';
	// print.format.value = NULL;
	return (print);
}


static const char		*strip_format(t_print *print, const char *format_string)
{
	while (*format_string)
	{
		if (*format_string == '-')
			print->format.left_aligned = 1;
		else if (*format_string == '0')
			print->format.fill = '0';
		else if (*format_string == '*')
			print->format.width = va_arg(print->valist, int);
		else if (ft_isdigit(*format_string))
		{
			print->format.width = ft_atoi(format_string);
			format_string += ft_leni(print->format.width);
		}
		else if (*format_string == '.')
		{
			print->format.precision = ft_atoi(++format_string);
			format_string += ft_leni(print->format.precision) - 1;
		}
		else if (ft_strchr("cspdiuxX%", *format_string))
		{
			print->format.type = *format_string++;
			break;
		}
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
	// else if (print->format.type == 's')
	// 	print_s(print);
	// ...
}


int					ft_printf(const char *format_string, ...)  // is format allowed ? 
{
	t_print 	print;
	int			n;

	va_start(print.valist, format_string);
	if (!format_string)
		return (0);
	while (*format_string)
	{
		if (*format_string == '%')
		{
			print = default_print();
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


int		main(void)
{
	char c = 'K';
	ft_printf("hello %c", c);
	return (0);
}