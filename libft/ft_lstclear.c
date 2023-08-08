/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 22:11:23 by marioliv          #+#    #+#             */
/*   Updated: 2023/04/20 23:23:51 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*bu;

	while (*lst)
	{
		bu = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = bu;
	}
	lst = NULL;
}
