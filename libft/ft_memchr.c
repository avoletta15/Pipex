/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 19:51:37 by marioliv          #+#    #+#             */
/*   Updated: 2023/04/20 22:51:22 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;

	str = (char *) s;
	while (n > 1 && *str != (char)c)
	{
		str++;
		n--;
	}
	if (*str != (char)c || n == 0)
		return (NULL);
	return (str);
}
