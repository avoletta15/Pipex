/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marioliv <marioliv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:52:45 by marioliv          #+#    #+#             */
/*   Updated: 2023/08/09 14:31:29 by marioliv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	find_env_paths(t_info *info)
{
	int	i;

	i = 0;
	while (info->envp[i] && info->envp)
	{
		if (ft_strncmp(info->envp[i], "PATH=", 5) == 0)
		{
			info->env_paths = ft_split(&info->envp[i][5], ':');
			return ;
		}
		i++;
	}
}

void	define_command(char *cmd, t_info *info)
{
	info->arg_commands = ft_split(cmd, ' ');
}

int	relative_path(t_info *info)
{
	char	*backup;
	int		i;

	i = 0;
	if (info->arg_commands[0] && ft_strchr(info->arg_commands[0], '/') == NULL)
	{
		while (info->env_paths && info->env_paths[i])
		{
			backup = ft_strjoin(info->env_paths[i], "/");
			info->my_command = ft_strjoin(backup, info->arg_commands[0]);
			free(backup);
			if (access(info->my_command, F_OK) != -1)
			{
				if (info->env_paths)
					free_matrix(info->env_paths);
				return (0);
			}
			free(info->my_command);
			i++;
		}
	}
	return (1);
}

int	absolute_path(t_info *info)
{
	if (info->arg_commands[0] && access(info->arg_commands[0], F_OK) != -1)
	{
		info->my_command = ft_strdup(info->arg_commands[0]);
		if (info->env_paths)
			free_matrix(info->env_paths);
		return (0);
	}
	else
		return (1);
}

/* cmd = argv */
int	execute_command(char *cmd, t_info *info)
{
	char	*str;

	define_command(cmd, info);
	if (absolute_path(info) == 0)
		return (0);
	else if (relative_path(info) == 0)
		return (0);
	if (info->arg_commands[0])
		str = ft_strjoin("command not found: ", cmd);
	else
		str = ft_strjoin("command not found: ", "''");
	ft_putendl_fd(str, 2);
	free(str);
	return (1);
}
