/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:00:09 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/19 19:40:46 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_di(t_print *print)
{
	
}
// {
// 	int		precision;
// 	int		d;
// 	char	*num_as_str;

// 	d = va_arg(print->valist, int);
// 	if (d < 0)
// 		print->format.is_negative = 1;
// 	print->format.arg_len = ft_leni(d) - print->format.is_negative;
// 	num_as_str = ft_itoa(d);
// 	precision = print->format.precision;
// 	if (precision != -1)
// 	{
// 		print->format.fill = ' ';
// 	}
// 	if (precision == -1 || print->format.arg_len > precision)
// 		precision = print->format.arg_len;
// 	if (print->format.precision == 0)
// 	{
// 		print->format.arg_len = 0;
// 		precision = 0;
// 	}		
// 	if (print->format.left_aligned)
// 	{
// 		fill_width('-', print->format.is_negative);
// 		fill_width('0', precision - print->format.arg_len);
// 		if (print->format.precision != 0)
// 			ft_putstr_fd(num_as_str + print->format.is_negative, 1);
// 		fill_width(print->format.fill, print->format.width - precision - print->format.is_negative);
// 	}
// 	else
// 	{
// 		if (print->format.fill == ' ')
// 			fill_width(print->format.fill, print->format.width - precision - print->format.is_negative);
// 		fill_width('-', print->format.is_negative);
// 		if (print->format.fill == '0')
// 			fill_width(print->format.fill, print->format.width - precision - print->format.is_negative);
// 		fill_width('0', precision - print->format.arg_len);
// 		if (print->format.precision != 0)
// 			ft_putstr_fd(num_as_str + print->format.is_negative, 1);
// 	}
// 	print->char_printed += ft_max(print->format.width, precision);
// 	free(num_as_str);
// }
