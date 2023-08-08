/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 12:37:20 by marioliv          #+#    #+#             */
/*   Updated: 2023/04/19 15:12:13 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_len(const char *str, char c)
{
	size_t	count;

	count = 1;
	while (*str != 0)
	{
		if (*str != c && (*(str + 1) == c || *(str + 1) == 0))
		{
			count++;
		}
		str++;
	}
	return (count);
}

static char	*ft_word(char const *str, int start, int end)
{
	char	*new;
	int		k;

	k = 0;
	new = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!new)
		return (NULL);
	while (start < end)
	{
		new[k] = str[start];
		start++;
		k++;
	}
	new[k] = '\0';
	return (new);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	i = 0;
	j = 0;
	index = -1;
	split = (char **)malloc(((ft_word_len(s, c))) * sizeof(char *));
	if (!split || !s)
		return (NULL);
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j] = ft_word(s, index, i);
			index = -1;
			j++;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}
