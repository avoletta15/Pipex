/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:10:39 by marioliv          #+#    #+#             */
/*   Updated: 2023/07/03 13:43:51 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_character(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_string(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (ft_string("(null)"));
	else
	{
		while (str[i])
			i += ft_character(str[i]);
	}
	return (i);
}

int	ft_number(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (ft_string("-2147483648"));
	if (n < 0)
	{
		i += ft_character('-');
		i += ft_number(-n);
	}
	else if (n > 9)
	{
		i += ft_number((n / 10));
		i += ft_number((n % 10));
	}
	else
		i += ft_character((n + '0'));
	return (i);
}

int	ft_unsigned_number(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i += ft_unsigned_number((n / 10));
		i += ft_unsigned_number((n % 10));
	}
	else
		i += ft_character((n + 48));
	return (i);
}

size_t	ft_hexa(unsigned long n, char *hexa_case)
{
	if (n < 16)
		return (ft_character(hexa_case[n]));
	return (ft_hexa(n / 16, hexa_case) + ft_character(hexa_case[n % 16]));
}
