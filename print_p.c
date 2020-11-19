/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 10:53:07 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/19 18:55:56 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_p(t_print *print)
{
	int				output_len;
	void			*p;
	long			l;

	p = va_arg(print->valist, void*);
	l = (long)p;
	output_len = ft_lenul_hex(l) + 2;
	
	if (print->format.left_aligned)
	{
		ft_putstr_fd("0x", 1);
		ft_printf("%lx", l);
		fill_width(print->format.fill, print->format.width - output_len);
	}
	else
	{
		fill_width(print->format.fill, print->format.width - output_len);
		ft_putstr_fd("0x", 1);
		ft_printf("%lx", l);
	}
	print->char_printed += ft_max(print->format.width, output_len);
}
