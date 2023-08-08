#include "pipex.h"

void	process_one(char **argv, t_info *info)
{
	info->infile = open(argv[1], O_RDONLY);
	if(info->infile < 0)
	{
		ft_putstr_fd("Error opening the infile", 2);
		close(info->infile); 
		exit(EXIT_FAILURE);
	}
	close(info->fd_pipe[0]); // é suposto fechar, para que a uncia ref de fd seja o process 1
	info->fd_dup[0] = dup2(info->infile, STDIN_FILENO);
	close(info->infile);
	info->fd_dup[1] = dup2(info->fd_pipe[1], STDOUT_FILENO);
	close(info->fd_pipe[1]);
	if (execute_command(argv[2], info) == 0)
	{
		free(info->arg_commands[0]);
		info->arg_commands[0] = ft_strdup(info->my_command);
		execve(info->my_command, info->arg_commands,  info->envp);
		perror("execve");
		free(info->my_command);
		free_matrix(info->arg_commands);
	}
	close(info->fd_dup[0]);
	close(info->fd_dup[1]);
	exit(EXIT_FAILURE);
}

void	process_two(char **argv, t_info *info)
{
	info->outfile = open(argv[4], O_CREAT | O_RDWR, 0644);
	if(info->outfile < 0)
	{
		ft_putstr_fd("Error opening the outfile", 2);
		close(info->outfile);
		/*free(info); */
		exit (EXIT_FAILURE) ;
	}
	info->fd_dup[0] = dup2(info->fd_pipe[0], STDIN_FILENO);
	close(info->fd_pipe[0]);
	info->fd_dup[1] = dup2(info->outfile, STDOUT_FILENO);
	close(info->outfile);
	if (execute_command(argv[3], info) == 0)
	{
		free(info->arg_commands[0]);
		info->arg_commands[0] = ft_strdup(info->my_command);
		execve(info->my_command, info->arg_commands,  info->envp);
		perror("execve");
		free(info->my_command);
		free_matrix(info->arg_commands);
	}
	close(info->fd_dup[0]);
	close(info->fd_dup[1]);
	exit(EXIT_FAILURE);
}