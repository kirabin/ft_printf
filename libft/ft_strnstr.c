/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 10:41:26 by dmilan            #+#    #+#             */
/*   Updated: 2020/11/05 17:30:46 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[j] && j < len)
	{
		if (haystack[j] == needle[i])
		{
			if (needle[++i] == '\0')
				return ((char *)haystack + j - i + 1);
		}
		else
		{
			j -= i;
			i = 0;
		}
		j++;
	}
	return (0);
}
