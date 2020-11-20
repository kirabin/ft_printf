/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:12:40 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/20 16:34:09 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	- Doesn't get affected by length
*/

void	print_c(t_print *print)
{
	unsigned char	arg;

	arg = (unsigned char)va_arg(print->valist, int);
	print->f.arg_len = 1;
	if (print->f.left_aligned)
	{
		ft_putuc_fd(arg, 1);
		fill_width(print->f.fill, print->f.width - print->f.arg_len);
	}
	else
	{
		fill_width(print->f.fill, print->f.width - print->f.arg_len);
		ft_putuc_fd(arg, 1);
	}
	print->printed += ft_max(print->f.width, print->f.arg_len);
}
