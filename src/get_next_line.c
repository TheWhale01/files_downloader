#include "downloader.h"

char	*ft_get_line(char *memory)
{
	int		i;
	char	*line;
	int		j;

	i = 0;
	if (!memory || !*memory)
		return (NULL);
	while (memory[i] && memory[i] != '\n')
		i++;
	if (memory[i] == '\n')
		i++;
	line = malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	j = i;
	i = -1;
	while (++i < j)
		line[i] = memory[i];
	line[i] = '\0';
	return (line);
}

char	*ft_buff_to_memory(int fd, char *memory)
{
	char	*buff;
	int		reader;

	reader = 1;
	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	*buff = '\0';
	while (!strchr(buff, '\n') && reader != 0)
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buff);
			free(memory);
			return (NULL);
		}
		buff[reader] = '\0';
		memory = ft_strjoin(memory, buff);
	}
	free(buff);
	if (!*memory && !reader)
	{
		free(memory);
		return (NULL);
	}
	return (memory);
}

char	*ft_reset_memory(char *memory, char *line)
{
	char	*new;
	int		len_memory;
	int		len_line;

	if (!memory || !line)
		return (NULL);
	len_memory = strlen(memory);
	len_line = strlen(line);
	if (len_line == 0)
	{
		free(memory);
		return (NULL);
	}
	new = malloc((len_memory - len_line + 1) * sizeof(char));
	memcpy(new, memory + len_line, len_memory - len_line + 1);
	free(memory);
	return (new);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*memory;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	memory = ft_buff_to_memory(fd, memory);
	if (!memory)
		return (NULL);
	line = ft_get_line(memory);
	if (!line)
		return (NULL);
	memory = ft_reset_memory(memory, line);
	return (line);
}
