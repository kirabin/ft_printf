/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:12:40 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/18 19:55:58 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(t_print *print)
{
	int		output_len;
	char	c;
	
	output_len = 1;
	if (print->format.left_aligned)
	{
		c = va_arg(print->valist, int);
		ft_putchar_fd(c, 1);
		fill_width(print->format.fill, print->format.width - output_len);
	}
	else
	{
		c = va_arg(print->valist, int);  //gets garbage value 
		fill_width(print->format.fill, print->format.width - output_len);
		ft_putchar_fd(c, 1);
	}
	print->char_printed += ft_max(print->format.width, output_len);
}