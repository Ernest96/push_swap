#include "push_swap.h"
#define AC_RED     "\x1b[31m"
#define AC_GREEN   "\x1b[32m"
#define AC_YELLOW  "\x1b[33m"
#define AC_BLUE    "\x1b[34m"
#define AC_MAGENTA "\x1b[35m"
#define AC_CYAN    "\x1b[36m"
#define AC_RESET   "\x1b[0m"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putchar('-');
		ft_putnbr(nb / - 10);
		ft_putchar('8');
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb < 10 && nb >= 0)
	{
		ft_putchar(nb + 48);
		return ;
	}
	if (nb != -2147483648)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

int8_t	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

void	ft_error(void)
{
	write(1, AC_RED, 5);
	write(1, "Error\n", 6);
	write(1, AC_RESET, 4);
	exit(0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i == 0 && (*(s1 + j) != 0 || *(s2 + j) != 0))
	{
		i = *(unsigned char *)(s1 + j) - *(unsigned char *)(s2 + j);
		j++;
	}
	return (i);
}