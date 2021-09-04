#include <unistd.h>
#include "lib.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void ft_fputstr(char *str, int output)
{
	while (*str)
		write(output, str++, 1);
}
