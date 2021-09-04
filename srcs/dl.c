#include <fcntl.h>
#include <unistd.h>
#include <curl/curl.h>
#include "lib.h"

char *get_filename(char *url)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (url[++i])
		if (url[i] == '/')
			j = i + 1;
	return (url + j);
}

void write_file(char *buff, int size, int nb, int fd)
{
	write(fd, buff, size * nb);
}

int dl_file(char *url)
{
	int fd;
	char *filename;
	CURL *curl;

	filename = get_filename(url);
	if ((fd = open(filename, O_CREAT | O_WRONLY, 0755)) < 0)
	{
		ft_fputstr("Could not create the file.\n", STDERR);
		return (0);
	}
	if (!(curl = curl_easy_init()))
	{
		ft_fputstr("Cound not start curl.\n", STDERR);
		return (0);
	}
	curl_easy_setopt(curl, CURLOPT_URL, url);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_file);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, fd);
	curl_easy_perform(curl);
	curl_easy_cleanup(curl);
	close(fd);
	return (1);
}
