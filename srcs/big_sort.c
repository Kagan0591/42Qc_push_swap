/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 09:37:26 by tchalifo          #+#    #+#             */
/*   Updated: 2022/03/07 10:24:37 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Radix bin




// Mike algo
// node_dlink	*big_sort(d_container *p_data)
// {

// }

long long int	average(node_dlink *stack) //Trouver la moyenne des nombres
{
	int		sum_of_args;
	int		size_of_stack;

	sum_of_args = 0;
	size_of_stack = ft_stksize_dlink(stack);
	while (stack != NULL)
	{
		sum_of_args = sum_of_args + stack->arg;
		stack = stack->next;
	}
	return ((float)sum_of_args / size_of_stack + 0.5f); //j aurais besoin d utiliser des float pour considerer les virgules
}
