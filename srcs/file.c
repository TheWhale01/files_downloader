#include <unistd.h>
#include <stdlib.h>
#include "lib.h"

char *re_alloc(char buff[BUFF_LEN], int bytes, char *str)
{
	int i;
	int j;
	char *string;

	if (!(string = malloc(sizeof(char) * (bytes + ft_strlen(str) + 1))))
		return (0);
	i = 0;
	j = 0;
	while (str[i])
	{
		string[i] = str[i];
		i++;
	}
	while (j < bytes)
		string[i++] = buff[j++];
	string[i] = '\0';
	if (*str)
		free(str);
	return (string);
}

char **read_file(int fd)
{
	int bytes;
	char *str;
	char **lines;
	char buff[BUFF_LEN];

	str = "";
	while ((bytes = read(fd, buff, BUFF_LEN)))
		str = re_alloc(buff, bytes, str);
	close(fd);
	lines = ft_split(str, "\n");
	if (*str)
		free(str);
	return (lines);
}
