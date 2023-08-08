/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaavoletta <mariaavoletta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:34:41 by marioliv          #+#    #+#             */
/*   Updated: 2023/06/26 17:25:44 by mariaavolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		a;
	int		i;

	a = 0;
	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str || !s1 || !s2)
		return (NULL);
	while (s1[a] != '\0')
	{
		str[i] = s1[a];
		a++;
		i++;
	}
	a = 0;
	while (s2[a] != '\0')
	{
		str[i] = s2[a];
		a++;
		i++;
	}
	str[i] = '\0';
	return (str);
}
