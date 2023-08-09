/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:52:39 by marioliv          #+#    #+#             */
/*   Updated: 2023/08/09 11:00:32 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_info	info;

	ft_bzero(&info, sizeof(t_info));
	info.envp = envp;
	if (argc != 5)
	{
		ft_putstr_fd("Correct Syntax: ./pipex infile cmd1 cmd2 outfile", 2);
		return (EXIT_FAILURE);
	}
	find_env_paths(&info);
	if (pipe(info.fd_pipe) < 0)
		error("pipe");
	info.child_one = fork();
	if (info.child_one < 0)
		error("c1");
	if (info.child_one == 0)
		process_one(argv, &info);
	close(info.fd_pipe[1]);
	info.child_two = fork();
	if (info.child_two < 0)
		error("c2");
	if (info.child_two == 0)
		process_two(argv, &info);
	close(info.fd_pipe[0]);
	waitpid(info.child_two, NULL, 0);
	waitpid(info.child_one, NULL, 0);
	free_matrix(info.env_paths);
	return (0);
}
