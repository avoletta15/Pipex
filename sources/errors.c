#include "pipex.h"



void	error(void)
{
	perror("Something went wrong");
	exit(EXIT_FAILURE);
}

void	free_matrix(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
}