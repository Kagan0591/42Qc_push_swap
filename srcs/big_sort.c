/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 09:37:26 by tchalifo          #+#    #+#             */
/*   Updated: 2022/03/08 17:00:29 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Radix bin
static int	*convert_tobin(unsigned int nb)
{
	int		i;
	int		*result;

	//ft_b_zero
	result = calloc(sizeof(int), 32); //int = 4 octets = 32 bits
	i = 31;
	while ((nb / 2) != 0)
	{
		result[i] = (nb % 2);
		nb = nb / 2;
		i--;
	}
	result[i] = (nb % 2);

	return (result);
}

void	args_to_args_binary(node_dlink *stack)
{
	while (stack != NULL)
	{
		stack->arg_binary = convert_tobin(stack->arg);
		stack = stack->next;
	}

}

static int	nbrchr(node_dlink *stack, int nb, int pos)
{
	while (stack != NULL)
	{
		if (stack->arg_binary[pos] == nb)
			return (1);
		stack = stack->next;
	}
	return (0);
}

node_dlink	*big_sort(d_container *p_data)
{
	int		i;

	i = 31;
	while (i > 22)
	{
		while ((p_data->stack_a != NULL) && nbrchr(p_data->stack_a, 0, i) == 1)
		{
			if (p_data->stack_a->arg_binary[i] == 0)
				push_to_b(p_data);
			else
				p_data->stack_a = rotate_a(p_data->stack_a);
		}
		p_data->stack_a = return_to_top(p_data->stack_a);
		while (p_data->stack_b != NULL)
			push_to_a(p_data);
		i--;
	}
	return (p_data->stack_a);
}
















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

