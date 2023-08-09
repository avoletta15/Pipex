/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 13:44:49 by marioliv          #+#    #+#             */
/*   Updated: 2023/07/03 13:44:50 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char	*ft_strchr_gnl(const char *s, int c);
char	*ft_strdup_gnl(const char *s);
size_t	ft_strlen_gnl(const char *s);
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t size);
char	*get_line(int fd, char *buffer, char *backup);
char	*get_next_line(int fd);
char	*looping(char *line);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
void	*ft_memset(void *s, int a, size_t n);
void	ft_bzero(void *s, size_t n);
char	*ft_strjoin_gnl(char *s, char *c);
#endif
