/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puti_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:59:43 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/20 13:10:06 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puti_fd(int n, int fd)
{
	if (0 <= n && n <= 9)
		ft_putc_fd(n + '0', fd);
	else if (n >= 10)
	{
		ft_puti_fd(n / 10, fd);
		ft_puti_fd(n % 10, fd);
	}
	else
	{
		ft_putc_fd('-', fd);
		if (n / 10)
			ft_puti_fd(-(n / 10), fd);
		ft_puti_fd(-(n % 10), fd);
	}
}
