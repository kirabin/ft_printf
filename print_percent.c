/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:35:23 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/20 16:27:02 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percent(t_print *print)
{
	print->f.arg_len = 1;
	if (print->f.left_aligned)
	{
		ft_putc_fd('%', 1);
		fill_width(' ', print->f.width - print->f.arg_len);
	}
	else
	{
		fill_width(print->f.fill, print->f.width - print->f.arg_len);
		ft_putc_fd('%', 1);
	}
	print->printed += ft_max(print->f.width, print->f.arg_len);
}
