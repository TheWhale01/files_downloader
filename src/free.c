#include "downloader.h"

void	safe_free(void *ptr)
{
	if (ptr)
		free(ptr);
}

void	free_data(t_data *data)
{
	t_list	*tmp;

	tmp = data->urls;
	while (tmp)
	{
		close(tmp->fd);
		tmp = tmp->next;
	}
	curl_easy_cleanup(data->curl);
	clear_list(&data->urls);
}

void	safe_exit(int exit_code, char *exit_msg, t_data *data)
{
	if (exit_code != EXIT_SUCCESS)
		fprintf(stderr, "%s\n", exit_msg);
	free_data(data);
	exit(exit_code);
}