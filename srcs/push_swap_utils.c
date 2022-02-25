#include "push_swap.h"

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
		while (*str == ' ')
			str++;
	}
	return (numbers * negative);
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
