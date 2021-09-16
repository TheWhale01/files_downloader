#include <stdlib.h>
#include "lib.h"

int main(int ac, char **av)
{
	int i;
	int fd;
	char **lines;

	if ((fd = get_fd(ac, av)) < 0)
		return (0);
	i = -1;
	lines = read_file(fd);
	while (lines[++i])
	{
		ft_putstr(get_filename(lines[i]));
		ft_putstr("\n\n");
		dl_file(lines[i]);
		free(lines[i]);
	}
	free(lines);
	return (0);
}
