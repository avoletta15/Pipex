/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:50:05 by marioliv          #+#    #+#             */
/*   Updated: 2023/07/03 13:57:44 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*looping(char *line)
{
	char	*backup;
	size_t	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\n')
	{
		if (line[++i] == '\0')
		{
			backup = NULL;
			return (NULL);
		}
		backup = ft_substr_gnl(line, i, ft_strlen_gnl(line) - (i - 1));
		line[i] = '\0';
		return (backup);
	}
	return (NULL);
}

char	*get_line(int fd, char *buffer, char *line)
{
	int	i;

	i = -1;
	while (i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i < 0)
			return (NULL);
		else if (i == 0)
			break ;
		buffer[i] = '\0';
		if (!line)
			line = ft_strdup_gnl("");
		line = ft_strjoin_gnl(line, buffer);
		if (ft_strchr_gnl(buffer, '\n'))
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = get_line(fd, buffer, backup);
	free(buffer);
	if (!line)
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	backup = looping(line);
	return (line);
}
