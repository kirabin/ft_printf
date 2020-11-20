/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 10:46:45 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/20 15:55:02 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_s(t_print *print)
{
	int		arg_len;
	char	*arg;

	arg = va_arg(print->valist, char*);
	if (!arg)
		arg = "(null)";
	arg_len = ft_strlen(arg);
	if (!print->f.precision_given || print->f.precision > arg_len ||
		print->f.precision < 0)
		print->f.precision = arg_len;
	if (!print->f.left_aligned)
		fill_width(print->f.fill, print->f.width - print->f.precision);
	ft_putstrn_fd(arg, ft_min(print->f.precision, arg_len), 1);
	if (print->f.left_aligned)
		fill_width(print->f.fill, print->f.width - print->f.precision);
	print->printed += ft_max(print->f.width, print->f.precision);
}
