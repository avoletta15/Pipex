/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:11:56 by marioliv          #+#    #+#             */
/*   Updated: 2023/04/20 23:28:01 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*bu;

	if (!lst)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	bu = lst->next;
	while (bu)
	{
		ft_lstadd_back(&new, ft_lstnew(f(bu->content)));
		bu = bu->next;
	}
	del(bu);
	return (new);
}
