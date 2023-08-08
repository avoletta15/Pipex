/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:37:55 by marioliv          #+#    #+#             */
/*   Updated: 2023/04/19 15:20:04 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	if (*s)
	{
		while (s[len] != (char)c && len >= 0)
			len--;
	}
	if (s[len] == (char)c)
		return ((char *)&*s + len);
	else
		return (NULL);
}
