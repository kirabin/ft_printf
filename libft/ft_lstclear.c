/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmilan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:13:04 by dmilan            #+#    #+#             */
/*   Updated: 2020/10/31 17:18:37 by dmilan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*node;
	t_list	*temp;

	node = *lst;
	if (!del || !*lst)
		return ;
	while (node)
	{
		del(node->content);
		temp = node;
		node = node->next;
		free(temp);
	}
	*lst = NULL;
}
