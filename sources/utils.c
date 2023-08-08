#include "pipex.h"

void	find_env_paths(t_info *info)
{
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
}


void	define_command(char *cmd, t_info *info)
{
	info->arg_commands = ft_split(cmd, ' ');
	ft_printf("arg_command: %s\n", info->arg_commands[0]);
}

/* cmd = argv */
int	execute_command(char *cmd, t_info *info)
{
	ft_printf("execute command: inside\n");
	char	*backup;
	int		i;
	
	i = 0;
	define_command(cmd, info);
	if (ft_strchr(info->arg_commands[0],'/') == NULL)
	{
		while (info->env_paths && info->env_paths[i])
		{
			backup = ft_strjoin(info->env_paths[i], "/");
			info->my_command = ft_strjoin(backup, info->arg_commands[0]);
			free(backup);
			if(access(info->my_command, F_OK) != -1)
			{
				if (info->env_paths)
					free_matrix(info->env_paths);
				return(0);
			}
			free(info->my_command);
			i++;
		}
	}
	else if (access(info->arg_commands[0], F_OK) != -1)
	{
		info->my_command = ft_strdup(info->arg_commands[0]);
		return (0);
	}
	backup = ft_strjoin("command not found: ", cmd);
	ft_putstr_fd(backup, 2);
	free(backup);
	free(info->arg_commands);
	free_matrix(info->env_paths);
	return(1);
}
