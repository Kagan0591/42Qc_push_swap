/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 09:37:26 by tchalifo          #+#    #+#             */
/*   Updated: 2022/03/10 10:18:07 by tchalifo         ###   ########.fr       */
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
	int		bit_sorting_limit;

	i = 31;
	if (ft_stksize_dlink(p_data->stack_a) <= 100)
		bit_sorting_limit = 24;
	else
		bit_sorting_limit = 22;
	while (i > bit_sorting_limit)
	{
		while (nbrchr(p_data->stack_a, 0, i) == 1)
		{
			// ft_putstr("\n\nnum position: \n");
			// ft_putstr("\n###--------STACK-A--------###\n");
			// ft_print_stack_dlink(p_data->stack_a);
			// ft_putstr("\n\n###--------STACK-B--------###\n");
			// ft_print_stack_dlink(p_data->stack_b);
			if (p_data->stack_a->arg_binary[i] == 0)
				push_to_b(p_data);
			else
				p_data->stack_a = rotate_a(p_data->stack_a);
		}
		// ft_putstr("\n\nnum position: \n");
		// ft_putstr("\n###--------STACK-A--------###\n");
		// ft_print_stack_dlink(p_data->stack_a);
		// ft_putstr("\n\n###--------STACK-B--------###\n");
		// ft_print_stack_dlink(p_data->stack_b);
		while (p_data->stack_b != NULL)
		{
			push_to_a(p_data);
			// ft_putstr("\n\nnum position: \n");
			// ft_putstr("\n###--------STACK-A--------###\n");
			// ft_print_stack_dlink(p_data->stack_a);
			// ft_putstr("\n\n###--------STACK-B--------###\n");
			// ft_print_stack_dlink(p_data->stack_b);
		}
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

