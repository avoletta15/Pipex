/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:41:56 by marioliv          #+#    #+#             */
/*   Updated: 2023/04/14 16:24:01 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int a)
{
	if (a >= 'a' && a <= 'z')
		a = a - 32;
	return (a);
}

/*#include <stdio.h>
int	main(void)
{
	printf("%d\n", ft_toupper('a'));
	return(0);
}*/