/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_di.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:00:09 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/20 18:51:41 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_di_default(t_print *p)
{
	int		arg;

	arg = va_arg(p->valist, int);
	if (p->f.precision_given && p->f.precision == 0 && arg == 0)
	{
		fill_width(p->f.fill, p->f.width);
		return ;
	}
	p->f.arg_s = ft_itoa(arg);
	p->f.sign = arg < 0 ? '-' : p->f.sign;
	p->f.arg_len = ft_strlen(p->f.arg_s + (p->f.sign == '-'));
	p->f.precision -= p->f.arg_len;
	p->f.precision = p->f.precision < 0 ? 0 : p->f.precision;
	p->f.width -= (p->f.sign != '\0') + p->f.precision + p->f.arg_len;
	p->f.width = p->f.width < 0 ? 0 : p->f.width;
	p->f.fill = p->f.precision_given ? ' ' : p->f.fill;
	if (p->f.precision == 0 && p->f.sign != '\0' && p->f.fill == '0')
		ft_swapi(&(p->f.precision), &(p->f.width));
	fill_width(p->f.fill, p->f.width * !p->f.left_aligned);
	fill_width(p->f.sign, p->f.sign != '\0');
	fill_width('0', p->f.precision);
	ft_putstr_fd(p->f.arg_s + (p->f.sign == '-'), 1);
	fill_width(p->f.fill, p->f.width * p->f.left_aligned);
	p->printed += (p->f.sign != 0) + p->f.precision + p->f.arg_len + p->f.width;
	free(p->f.arg_s);
}

void	print_di(t_print *print)
{
	print_di_default(print);
}
