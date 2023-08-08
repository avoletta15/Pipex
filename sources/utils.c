#include "pipex.h"

void	find_env_paths(t_info *info)
{
	printf("find_env_path: inside\n"); //ok
	int	i;

	i = 0;
	while(info->envp[i] && info->envp)
	{
		if (ft_strncmp(info->envp[i], "PATH=", 5) == 0)
		{
			info->env_paths = ft_split(&info->envp[i][5], ':');
			if (!info->env_paths)
				free_matrix(info->env_paths);
			return ;
		}
		i++;
	}
	
	//memory is being allocated to env_paths (0x608000000020)
}


void	define_command(char *cmd, t_info *info)
{
	info->arg_commands = ft_split(cmd, ' ');
	if (!info->arg_commands)
		free_matrix(info->arg_commands);
	ft_printf("Define Command\n");
}

/* cmd = argv */
int	execute_command(char *cmd, t_info *info)
{
	ft_printf("Execute Command\n");
	char	*backup;
	int		i;

	i = 0;
	define_command(cmd, info);
	if(!info->my_commands)
		return(1);
	while (info->env_paths && info->env_paths[i])
	{
		backup = ft_strjoin(info->env_paths[i], "/");
		info->my_commands[i] = ft_strjoin(backup, info->arg_commands[0]);
		if(access(info->my_commands[i], F_OK) != -1)
			return(0);
		i++;
	}
	backup = ft_strjoin("command not found: ", cmd);
	ft_putstr_fd(backup, 2);
	free(backup);
	free_matrix(info->env_paths);
	return(1);
}
