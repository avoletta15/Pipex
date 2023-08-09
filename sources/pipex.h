/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:52:41 by marioliv          #+#    #+#             */
/*   Updated: 2023/08/09 11:02:10 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
/* #include 	<sys/_types.h> */
# include "../libft/libft.h"
# include <sys/wait.h>

typedef struct s_info
{
	pid_t	child_one;
	pid_t	child_two;
	int		infile;
	int		outfile;
	char	**env_paths;
	int		fd_pipe[2];
	int		fd_dup[2];
	char	**arg_commands;
	char	*my_command;
	char	**envp;
}			t_info;

/* children */
void		process_one(char **argv, t_info *info);
void		process_two(char **argv, t_info *info);

/* utils */
void		find_env_paths(t_info *info);
int			execute_command(char *cmd, t_info *info);
void		close_pipe(int *fd);

/* errors */
void		error(char* msg);
void		free_matrix(char **cmd);

#endif