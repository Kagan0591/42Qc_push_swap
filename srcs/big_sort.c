/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 09:37:26 by tchalifo          #+#    #+#             */
/*   Updated: 2022/03/14 15:01:13 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	convert_tobin(node_dlink *stack_node, unsigned int nb)
{
	int		i;

	i = 31;
	while ((nb / 2) != 0)
	{
		stack_node->arg_binary[i] = (nb % 2);
		nb = nb / 2;
		i--;
	}
	stack_node->arg_binary[i] = (nb % 2);
}

static void	args_to_args_binary(node_dlink *stack)
{
	while (stack != NULL)
	{
		convert_tobin(stack, stack->arg);
		stack = stack->next;
	}
}

static int	nbrchr_doublyll(node_dlink *stack, int nb, int pos)
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
	args_to_args_binary(p_data->stack_a);
	if (ft_stksize_dlink(p_data->stack_a) <= 100)
		bit_sorting_limit = 24;
	else
		bit_sorting_limit = 22;
	while (i > bit_sorting_limit)
	{
		while (nbrchr_doublyll(p_data->stack_a, 0, i) == 1)
		{
			if (p_data->stack_a->arg_binary[i] == 0)
				push_to_b(p_data);
			else
				p_data->stack_a = rotate_a(p_data->stack_a);
		}
		while (p_data->stack_b != NULL)
			push_to_a(p_data);
		i--;
	}
	return (p_data->stack_a);
}
