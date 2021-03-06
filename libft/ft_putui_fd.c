/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putui_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 11:16:19 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/20 13:10:36 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putui_fd(unsigned int n, int fd)
{
	if (0 <= n && n <= 9)
		ft_putc_fd(n + '0', fd);
	else
	{
		ft_putui_fd(n / 10, fd);
		ft_putui_fd(n % 10, fd);
	}
}
