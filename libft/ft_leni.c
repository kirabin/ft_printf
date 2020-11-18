/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leni.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <dmilan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 12:26:45 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/17 10:07:10 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_leni(int n)
{
	int len;

	len = !(n > 0);
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}