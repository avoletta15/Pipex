/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariaavoletta <mariaavoletta@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:10:39 by marioliv          #+#    #+#             */
/*   Updated: 2023/06/28 08:12:55 by mariaavolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* %c - prints a single character */
int	ft_character(char c)
{
	write(1, &c, 1);
	return (1);
}

/* %s - prints a string */
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

/* %d || %i || %u - prints a decimal (base 10) number */
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

/* %u - prints a unsigned decimal (base 10) number */
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

/* %x &&
	%X- prints a number in hexadecimal (base 16)
	low and highcase format */
size_t	ft_hexa(unsigned long n, char *hexa_case)
{
	if (n < 16)
		return (ft_character(hexa_case[n]));
	return (ft_hexa(n / 16, hexa_case) + ft_character(hexa_case[n % 16]));
}

/* %p - the void
	* pointer argument has to be printed in hexadecimal format */
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
