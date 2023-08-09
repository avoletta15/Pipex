/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:52:32 by marioliv          #+#    #+#             */
/*   Updated: 2023/08/09 15:41:46 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exeve_free(t_info *info)
{
	free(info->arg_commands[0]);
	info->arg_commands[0] = ft_strdup(info->my_command);
	execve(info->my_command, info->arg_commands, info->envp);
	perror("execve");
	free(info->my_command);
}

void	process_one(char **argv, t_info *info)
{
	info->infile = open(argv[1], O_RDONLY);
	if (info->infile < 0)
	{
		close_pipe(info->fd_pipe);
		perror("pipex");
		free_matrix(info->env_paths);
		exit(EXIT_FAILURE);
	}
	close(info->fd_pipe[0]);
	info->fd_dup[0] = dup2(info->infile, STDIN_FILENO);
	if (info->fd_dup[0] == -1)
		error();
	info->fd_dup[1] = dup2(info->fd_pipe[1], STDOUT_FILENO);
	if (info->fd_dup[1] == -1)
		error();
	close(info->infile);
	close(info->fd_pipe[1]);
	if (execute_command(argv[2], info) == 0)
		ft_exeve_free(info);
	else
		free_matrix(info->env_paths);
	free_matrix(info->arg_commands);
	close_pipe(info->fd_dup);
	exit(EXIT_FAILURE);
}

void	process_two(char **argv, t_info *info)
{
	info->outfile = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0644);
	if (info->outfile < 0)
	{
		close_pipe(info->fd_pipe);
		perror("pipex");
		free_matrix(info->env_paths);
		exit(EXIT_FAILURE);
	}
	info->fd_dup[0] = dup2(info->fd_pipe[0], STDIN_FILENO);
	if (info->fd_dup[0] == -1)
		error();
	close(info->fd_pipe[0]);
	info->fd_dup[1] = dup2(info->outfile, STDOUT_FILENO);
	if (info->fd_dup[1] == -1)
		error();
	close(info->outfile);
	if (execute_command(argv[3], info) == 0)
		ft_exeve_free(info);
	else
		free_matrix(info->env_paths);
	free_matrix(info->arg_commands);
	close_pipe(info->fd_dup);
	exit(EXIT_FAILURE);
}
