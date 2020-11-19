/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:12:32 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/19 18:48:41 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		print_xn(t_print *print, int is_upper)
{
	int				output_len;
	unsigned int	u;

	u = (unsigned int)va_arg(print->valist, unsigned int);
	output_len = ft_lenui_hex(u);
	if (print->format.left_aligned)
	{
		ft_putui_hex_fd(u, is_upper, 1);
		fill_width(print->format.fill, print->format.width - output_len);
	}
	else
	{
		fill_width(print->format.fill, print->format.width - output_len);
		ft_putui_hex_fd(u, is_upper, 1);
	}
	print->char_printed += ft_max(print->format.width, output_len);
}

static void		print_xl(t_print *print, int is_upper)
{
	int				output_len;
	unsigned long	l;

	l = (unsigned long)va_arg(print->valist, unsigned long);
	output_len = ft_lenul_hex(l);
	if (print->format.left_aligned)
	{
		ft_putul_hex_fd(l, is_upper, 1);
		fill_width(print->format.fill, print->format.width - output_len);
	}
	else
	{
		fill_width(print->format.fill, print->format.width - output_len);
		ft_putul_hex_fd(l, is_upper, 1);
	}
	print->char_printed += ft_max(print->format.width, output_len);
}

void			print_x(t_print *print, int is_upper)
{
	if (print->format.length == 'n')
		print_xn(print, is_upper);
	if (print->format.length == 'l')
		print_xl(print, is_upper);
	// if (print->format.length == 'L')
	// 	print_xn(print, is_upper);
	// if (print->format.length == 'h')
	// 	print_xn(print, is_upper);
	// if (print->format.length == 'H')
	// 	print_xn(print, is_upper);
}
