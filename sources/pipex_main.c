#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_info *info;

	info = ft_calloc(1, sizeof(t_info));
	if (!info)
		return (0);
	info->envp = envp;
	if (argc != 5)
	{
		ft_putstr_fd("Correct Syntax: ./pipex infile cmd1 cmd2 outfile", 2);
		return(EXIT_FAILURE);
	}
	find_env_paths(info);
	if (pipe(info->fd_pipe) < 0)
		error();
	info->child_one = fork();
	if (info->child_one < 0)
		error();
	if (info->child_one == 0)
		process_one(argv, info);
	info->child_two = fork();
	if (info->child_two < 0)
		error();
	if (info->child_two == 0)
		process_two(argv, info);
	close(info->fd_pipe[0]);
	close(info->fd_pipe[1]);
	waitpid(info->child_one, NULL, 0);
	waitpid(info->child_two, NULL, 0);
	// free_matrix(info->env_paths);
	free(info);
	return (0);
}