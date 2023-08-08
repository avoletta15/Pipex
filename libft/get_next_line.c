#include "get_next_line.h"

char	*looping(char *line)
{
	char	*backup;
	size_t	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\n')
	{
		if (line[++i] == '\0')
		{
			backup = NULL;
			return (NULL);
		}
		backup = ft_substr_gnl(line, i, ft_strlen_gnl(line) - (i - 1));
		line[i] = '\0';
		return (backup);
	}
	return (NULL);
}

char	*get_line(int fd, char *buffer, char *line)
{
	int	i;

	i = -1; /* read retorna o numero real de bytes lidos, do contrario,
		retorna <0 */
	while (i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
			/* queremos saber em qual posicao da linha o nosso contadro estaa*/
		if (i < 0)
			return (NULL); /* nesse caso, o file nao existe ou deu erro */
		else if (i == 0)   /* nesse caso, o file nao tem nada dentro */
			break ;
		buffer[i] = '\0';
		if (!line)
			line = ft_strdup_gnl("");
		line = ft_strjoin_gnl(line, buffer);
		if (ft_strchr_gnl(buffer, '\n'))
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char *backup;
		/*static variable --> vai preservar o ultimo valor toda vez que a funcao for chamada. ex.: se o valor inicial = 0
	roda a funcao, o valor passa a ser 10,
		da prxima vez que a funcao for chamada, o valor vai ser 10*/
	char *buffer;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0) /* fe = 0 - nao tem file
	/ BUFFER_SIZE <= 0 nao tem "contador de letras para correr a linha"*/
		return (NULL);
	buffer = (char *)malloc(sizeof(char *) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	line = get_line(fd, buffer, backup);
	free(buffer);
	if (!line)
	{
		free(backup);
		backup = NULL;
		return (NULL);
	}
	backup = looping(line);
	return (line);
}