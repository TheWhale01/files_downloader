#include <fcntl.h>
#include <unistd.h>
#include "lib.h"

int get_fd(int ac, char **av)
{
	int fd;

	if (ac == 1)
		return (0);
	else if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) < 0)
		{
			ft_fputstr("Could not open the file.\n", STDERR);
			return (-1);
		}
		return (fd);
	}
	else if (ac > 2)
		ft_fputstr("Too many arguments.\n", STDERR);
	return (-1);
}
