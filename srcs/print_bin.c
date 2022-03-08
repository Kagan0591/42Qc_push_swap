/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:10:37 by tchalifo          #+#    #+#             */
/*   Updated: 2022/03/08 11:39:55 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


// int	convert_tobase(unsigned int nb, int base)
// {
// 	int		result;

// 	result = 0;
// 	if (base > 36)
// 		return (0);
// 	if ((nb / base) != 0)
// 		convert_tobase(nb / base, base);
// 	if ((nb % base) > 9)
// 	{
// 		//printf("TEST");
// 		result = ((nb % base) + 87);
// 		//result = (result * 10) + ((nb % base) + 87);
// 	}
// 	else
// 		//printf("TEST222");
// 		//result = (nb % base);
// 		result = (result * 10) + (nb % base);
// 	//printf("%d\n", result);
// 	return (result);
// }



int		*convert_tobin(unsigned int nb)
{
	int		i;
	int		*result;

	//ft_b_zero
	result = calloc(sizeof(int), 32); //int = 4 octets = 32 bits
	i = 31;
	while ((nb / 2) != 0)
	{
		ft_putchar((nb % 2) + 48);
		printf("\n I = %d\n", i);
		result[i] = (nb % 2);
		nb = nb / 2;
		i--;
	}
	ft_putchar((nb % 2) + 48);
	printf("\n I = %d\n", i);
	result[i] = (nb % 2);

	return (result);
}


int	main(void)
{
	int nb;
	int	*tab;
	int	i = 0;

	nb = 10;
	tab = convert_tobin(nb);
	while (i < 32)
	{
		printf("tab $i = %d\n", tab[i]);
		i++;
	}
	return (0);
}

// node_dlink	*decimal_to_binary(node_dlink *p_stk)
// {
// 	ft_putnbr_base2(p_stk->arg);

// }
