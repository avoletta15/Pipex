#include "pipex.h"

void	process_one(char **argv, t_info *info)
{
	printf("process one: inside");
	info->infile = open(argv[1], O_RDONLY);
	if (info->infile < 0)
	{
		perror("Error opening the infile");
		exit (EXIT_FAILURE);
	}
	close(info->fd_pipe[0]); // é suposto fechar, para que a uncia ref de fd seja o process 1
	info->fd_dup[0] = dup2(info->infile, STDIN_FILENO);
	close(info->infile);
	info->fd_dup[1] = dup2(info->fd_pipe[1], STDOUT_FILENO);
	// close(info->fd_pipe[1]);
	// if (execute_command(argv[2], info) == 0)
	// {
	// 	execve(info->my_commands[0], info->my_commands, info->envp);
	// 	perror("execve");
	// }
	// close(info->fd_dup[0]);
	// close(info->fd_dup[1]);
	// free(info);
	// exit(EXIT_FAILURE);
}

void	process_two(char **argv, t_info *info)
{
	printf("process two: inside");
	info->outfile = open(argv[4], O_CREAT, O_RDWR, 0644);
	if (info->outfile < 0)
	{
		perror("Error opening the outfile");
		exit (EXIT_FAILURE);
	}
	close(info->fd_pipe[0]);
	info->fd_dup[0] = dup2(info->fd_pipe[0], STDIN_FILENO);
	info->fd_dup[1] = dup2(info->outfile, STDOUT_FILENO);
	close(info->fd_pipe[0]);
	if (execute_command(argv[3], info) == 0)
	{
		execve(info->my_commands[0], info->my_commands, info->envp);
		perror("execve");
	}
	close(info->outfile);
	close(info->fd_dup[0]);
	close(info->fd_dup[1]);
	free(info);
	exit(EXIT_FAILURE);
}