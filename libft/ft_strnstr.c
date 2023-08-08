/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:35:03 by marioliv          #+#    #+#             */
/*   Updated: 2023/04/19 15:49:36 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (find[j] == 0)
		return ((char *)str);
	while (str[i] != 0)
	{
		j = 0;
		while (str[i + j] != 0 && str[i + j] == find[j] && (i + j) < len)
		{
			if (find[j + 1] == 0)
			{
				return ((char *)&str[i]);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}
