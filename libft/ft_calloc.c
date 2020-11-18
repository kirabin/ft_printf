/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:54:38 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/02 20:06:59 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*res;
	unsigned int	i;

	i = 0;
	res = malloc(size * count);
	if (!res)
		return (0);
	while (i < size * count)
		res[i++] = 0;
	return (res);
}
