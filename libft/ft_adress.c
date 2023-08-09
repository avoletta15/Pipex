/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_adress.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:43:54 by marioliv          #+#    #+#             */
/*   Updated: 2023/07/03 13:49:01 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_adress(unsigned long int loc)
{
	int	i;

	i = 0;
	if (loc == 0)
		i += ft_string("0x0");
	else
	{
		i += ft_string("0x");
		i += ft_hexa(loc, HEXALOW);
	}
	return (i);
}
