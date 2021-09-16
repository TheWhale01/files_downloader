#include "lib.h"

void ft_putnbr(int nb)
{
	unsigned int nbr;

	if (nb < 0)
	{
		nbr = nb * -1;
		ft_putchar('-');
	}
	else
		nbr = nb;
	if (nbr / 10)
		ft_putchar(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}
