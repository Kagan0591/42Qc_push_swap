/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:10:37 by tchalifo          #+#    #+#             */
/*   Updated: 2022/03/08 07:41:00 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
//#include "push_swap.h"

int	convert_tobase(unsigned int nb, int base)
{
	int		result;

	result = 0;
	if (base > 36)
		return (0);
	if ((nb / base) >= 1)
		convert_tobase(nb / base, base);
	if (nb % base > 9)
		result = (result * 10) + ((nb % base) + 87);
	result = (result * 10) + (nb % base);
	printf("%d\n", result);
	return (result);
}

int	main(void)
{
	int nb;

	nb = 15;
	printf("%d\n", convert_tobase(nb, 16));
	return (0);
}

// node_dlink	*decimal_to_binary(node_dlink *p_stk)
// {
// 	ft_putnbr_base2(p_stk->arg);

// }
