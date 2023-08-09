/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:49:57 by marioliv          #+#    #+#             */
/*   Updated: 2023/07/03 13:56:04 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	l;

	l = ft_strlen_gnl(s);
	if (len > l - start)
		len = l - start;
	if (start >= l)
	{
		str = malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = (char *)malloc(len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	ft_strlcpy_gnl(str, s + start, len + 1);
	return (str);
}

size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen_gnl(src);
	if (size != 0)
	{
		while ((src[i] != '\0') && (i < size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (len);
}

char	*ft_strdup_gnl(const char *s)
{
	char	*str;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen_gnl(s);
	str = (char *)malloc(len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*str;
	int		a;
	int		i;

	a = 0;
	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen_gnl(s1) + ft_strlen_gnl(s2)
				+ 1));
	if (!str || !s1 || !s2)
		return (NULL);
	while (s1[a] != '\0')
	{
		str[i] = s1[a];
		a++;
		i++;
	}
	a = -1;
	while (s2[++a] != '\0')
	{
		str[i] = s2[a];
		i++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr_gnl(const char *s, int c)
{
	const char	*str;

	str = s;
	while (*str && *str != (char)c)
		str++;
	if (*str == (char)c)
		return ((char *)&*str);
	else
		return (NULL);
}
