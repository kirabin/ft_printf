/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:02:48 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/19 19:24:54 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_u(t_print *print)
{
	int				output_len;
	unsigned int	u;
	int				precision;
	char			*num_as_str;
	bool			is_negative;

	is_negative = 0;
	u = (unsigned int)va_arg(print->valist, unsigned int);
	if (u < 0)
		is_negative = 1;
	output_len = ft_lenui(u) - is_negative;
	num_as_str = ft_uitoa(u);
	precision = print->format.precision;
	if (precision != -1)
		print->format.fill = ' ';
	if (precision == -1 || output_len > precision)
		precision = output_len;
	if (print->format.precision == 0)
	{
		output_len = 0;
		precision = 0;
	}		
	if (print->format.left_aligned)
	{
		fill_width('-', is_negative);
		fill_width('0', precision - output_len);
		if (print->format.precision != 0)
			ft_putstr_fd(num_as_str + is_negative, 1);
		fill_width(print->format.fill, print->format.width - precision - is_negative);
	}
	else
	{
		if (print->format.fill == ' ')
			fill_width(print->format.fill, print->format.width - precision - is_negative);
		fill_width('-', is_negative);
		if (print->format.fill == '0')
			fill_width(print->format.fill, print->format.width - precision - is_negative);
		fill_width('0', precision - output_len);
		if (print->format.precision != 0)
			ft_putstr_fd(num_as_str + is_negative, 1);
	}
	print->char_printed += ft_max(print->format.width, precision);
	free(num_as_str);
}
