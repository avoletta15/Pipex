#include "pipex.h"

void	process_one(char **argv, t_info *info)
{
	info->infile = open(argv[1], O_RDONLY);
	if (info->infile < 0)
	{
		perror("Error opening the infile");
		exit (EXIT_FAILURE);
	}
	close(info->fd_pipe[0]); // é suposto fechar, para que a uncia ref de fd seja o process 1
	info->fd_dup[0] = dup2(info->infile, STDIN_FILENO);
	close(info->fd_pipe[1]);
	info->fd_dup[1] = dup2(info->fd_pipe[1], STDOUT_FILENO);
	if (execute_command(argv[2], info) == 0)
	{

		execve(info->arg_commands[0], &info->my_command,  info->envp);
		printf("Process 1: execute command - ok\n");
		
		free(info->my_command);
		// free(info->envp);
	}
	//perror("execve");
	close(info->infile);
	close(info->fd_dup[0]);
	close(info->fd_dup[1]);
	exit(EXIT_FAILURE);
}

void	process_two(char **argv, t_info *info)
{
	info->outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC , 0644);

	ft_printf("fd outfile: %d\n", info->outfile);

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
		printf("Process 2: execute command - ok\n");
		execve(info->arg_commands[0], &info->my_command, info->envp);
	}
	//perror("execve");
	close(info->outfile);
	close(info->fd_dup[0]);
	close(info->fd_dup[1]);
	exit(EXIT_FAILURE);
}