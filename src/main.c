#include "downloader.h"

void	init(int ac, int *infile, char **av, t_data *data)
{
	data->urls = NULL;
	if (!(data->curl = curl_easy_init()))
		safe_exit(EXIT_FAILURE, "Failed to start curl.", data);
	if (ac == 1)
		*infile = STDIN_FILENO;
	else if (ac >= 2 && (*infile = open(av[1], O_RDONLY)) < 0)
		safe_exit(EXIT_FAILURE, "Could not open the file.", data);
}

int main(int ac, char **av)
{
	int		fd;
	t_data 	data;
	t_list	*node;

	init(ac, &fd, av, &data);
	while (1)
	{
		write(STDIN_FILENO, "downloader> ", 12);
		data.line = get_next_line(fd);
		if (!data.line)
			break ;
		if (data.line[strlen(data.line) - 1] == '\n')
			data.line[strlen(data.line) - 1] = '\0';
		node = create_node(data.line);
		if (!node)
			safe_exit(EXIT_FAILURE, "\nMemory allocation failure.", &data);
		add_node(&data.urls, node);
	}
	create_files(&data);
	make_connection(&data);
	dl_file(&data);
	close(fd);
	free_data(&data);
	return (0);
}