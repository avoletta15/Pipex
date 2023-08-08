/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:40:29 by marioliv          #+#    #+#             */
/*   Updated: 2023/04/14 16:24:07 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int a)
{
	if (a >= 'A' && a <= 'Z')
		a = a + 32;
	return (a);
}

/*#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_tolower('A'));
	return(0);
}*/