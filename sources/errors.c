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

/* * * * * * * * * * * * * * * * * * * * * * * *  *
* Check if my infile exists - it must do          *
* Check if my outfile exists - if not, creats it  *
* * * * * * * * * * * * * * * * * * * * * * * * * */

// void	check_files(char **argv, t_info *info)
// {
// 	info->infile = open(argv[1], O_RDONLY);
// 	info->outfile = open(argv[4], O_CREAT | O_RDWR, 0644);
// 	if(info->infile < 0)
// 	{
// 		ft_putstr_fd("Error opening the infile", 2);
// 		close(info->infile); /* close? se nem abriu? */
// 		/* free(info); */
// 		exit(EXIT_FAILURE);
// 	}
// 	if(info->outfile < 0)
// 	{
// 		ft_putstr_fd("Error opening the outfile", 2);
// 		close(info->outfile);
// 		/*free(info); */
// 		exit (EXIT_FAILURE) ;
// 	}
// /* 	if (info->infile >= 0)
// 		close(info->infile);
// 	if (info->outfile >= 0)
// 		close(info->outfile); */
// }
