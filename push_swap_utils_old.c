#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	numbers;
	int	negative;

	numbers = 0;
	negative = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative = negative * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		numbers = (numbers * 10) + (*str - 48);
		str++;
	}
	return (numbers * negative);
}

long long int	ft_atoll(const char *str)
{
	long long int	numbers;
	int			negative;

	numbers = 0;
	negative = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative = negative * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		numbers = (numbers * 10) + (*str - 48);
		str++;
	}
	return (numbers * negative);
}

void	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if ((nbr / 10) != 0)
		ft_putnbr(nbr / 10);
	ft_putchar((nbr % 10) + 48);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	decimal_to_base(int base, int nb)
{
	int	num;
	int	quotient;
	int	remainder;
	int	i;

	num = 0;
	quotient = nb;
	remainder = 0;
	i = 0;

	while (quotient != 0)
	{
		remainder = (quotient % base);
		quotient = (quotient / base);
		num = ((remainder * pow(10, i)) + num);
		i++;
	}
	return (num);
}

