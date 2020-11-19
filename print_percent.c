/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:35:23 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/19 17:40:12 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percent(t_print *print)
{
	int		output_len;
	char	c;

	c = '%';
	output_len = 1;
	if (print->format.left_aligned)
	{
		ft_putchar_fd(c, 1);
		fill_width(' ', print->format.width - output_len);
	}
	else
	{
		fill_width(print->format.fill, print->format.width - output_len);
		ft_putchar_fd(c, 1);
	}
	print->char_printed += ft_max(print->format.width, output_len);
}
