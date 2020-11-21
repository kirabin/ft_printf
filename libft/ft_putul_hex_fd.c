/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putul_hex_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 18:49:39 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/21 12:46:05 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putul_hex_fd(unsigned long n, int is_upper, int fd)
{
	if (0 <= n && n <= 9)
		ft_putc_fd(n + '0', fd);
	else if (10 <= n && n <= 15)
	{
		if (is_upper)
			ft_putc_fd(n - 10 + 'A', 1);
		else
			ft_putc_fd(n - 10 + 'a', 1);
	}
	else
	{
		ft_putul_hex_fd(n / 16, is_upper, fd);
		ft_putul_hex_fd(n % 16, is_upper, fd);
	}
}
