/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 10:46:45 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/19 13:15:01 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_s(t_print *print)
{
	int		output_len;
	int		precision;
	char	*s;

	s = va_arg(print->valist, char*);
	if (!s)
		s = "(null)";
	output_len = ft_strlen(s);
	precision = print->format.precision;
	if (precision == -1 || precision > output_len)
		precision = output_len;
	if (print->format.left_aligned)
	{
		ft_putstrn_fd(s, ft_min(precision, output_len), 1);
		fill_width(print->format.fill, print->format.width - precision);
	}
	else
	{
		fill_width(print->format.fill, print->format.width - precision);
		ft_putstrn_fd(s, ft_min(precision, output_len), 1);
	}
	print->char_printed += ft_max(print->format.width, precision);
}
