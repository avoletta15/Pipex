/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:12:34 by marioliv          #+#    #+#             */
/*   Updated: 2023/04/14 16:24:43 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int a, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *) s;
	while (n > 0)
	{
		*ptr++ = a;
		n--;
	}
	return (s);
}

/*#include <stdio.h>
int	main(void)
{
	char ptr[] = "rafael eh um fofo";
	ft_memset(ptr, 65, 6);
	printf("%s\n", ptr);
	return(0);
}*/