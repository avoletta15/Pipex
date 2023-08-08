/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:35:19 by marioliv          #+#    #+#             */
/*   Updated: 2023/04/19 15:53:33 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char *) dst;
	s = (unsigned char *) src;
	if (dst == src || len == 0)
		return (dst);
	if (dst < src || dst >= (src + len))
	{
		while (len-- != 0)
			*d++ = *s++;
	}
	else
	{
		d += len - 1;
		s += len - 1;
		while (len-- != 0)
			*d-- = *s--;
	}
	return (dst);
}
