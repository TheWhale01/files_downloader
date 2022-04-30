#include "downloader.h"

void	create_files(t_data *data)
{
	t_list	*tmp;

	tmp = data->urls;
	while (tmp)
	{
		tmp->mb = 0;
		tmp->filename = get_filename(tmp->url);
		if ((tmp->fd = open(tmp->filename, O_CREAT | O_WRONLY, 0644)) < 0)
			safe_exit(EXIT_FAILURE, "Could not create file.", data);
		tmp = tmp->next;
	}
}

void make_connection(t_data *data)
{
	t_list	*tmp;

	tmp = data->urls;
	while (tmp)
	{
		curl_easy_setopt(data->curl, CURLOPT_URL, tmp->url);
		tmp = tmp->next;
	}
}

void	write_file(char *buff, int size, int nb, t_list *url)
{
	printf("\r%s\t(%dMB)", url->filename, url->mb / 1000000);
	fflush(stdout);
	write(url->fd, buff, size * nb);
}

void	dl_file(t_data *data)
{
	t_list	*tmp;

	tmp = data->urls;
	while (tmp)
	{
		curl_easy_setopt(data->curl, CURLOPT_WRITEFUNCTION, write_file);
		curl_easy_setopt(data->curl, CURLOPT_WRITEDATA, tmp);
		curl_easy_perform(data->curl);
		tmp = tmp->next;
	}
}