/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 09:37:26 by tchalifo          #+#    #+#             */
/*   Updated: 2022/03/20 18:00:58 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	convert_tobin(t_dlinklst *stack_node, unsigned int nb)
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

static void	args_to_args_binary(t_dlinklst *stack)
{
	while (stack != NULL)
	{
		convert_tobin(stack, stack->arg);
		stack = stack->next;
	}
}

static int	nbrchr_doublyll(t_dlinklst *stack, int nb, int pos)
{
	while (stack != NULL)
	{
		if (stack->arg_binary[pos] == nb)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static void	binary_sorting(t_container *p_data, int total_mouv, int bit_limit)
{
	int		i;
	int		mouvemenents;

	i = 31;
	while (i > bit_limit)
	{
		mouvemenents = total_mouv;
		while (nbrchr_doublyll(p_data->stack_a, 0, i) == 1)
		{
			if (p_data->stack_a->arg_binary[i] == 0)
				push_to_b(p_data);
			else
				p_data->stack_a = rotate_a(p_data->stack_a, 0);
			mouvemenents--;
		}
		while (mouvemenents != 0)
		{
			p_data->stack_a = rotate_a(p_data->stack_a, 0);
			mouvemenents--;
		}
		while (p_data->stack_b != NULL)
			push_to_a(p_data);
		i--;
	}
}

t_dlinklst	*big_sort(t_container *p_data)
{
	int		bit_limit;
	int		original_stack_size;

	original_stack_size = ft_stksize_dlink(p_data->stack_a);
	args_to_args_binary(p_data->stack_a);
	if (original_stack_size <= 100)
		bit_limit = 24;
	else
		bit_limit = 22;
	binary_sorting(p_data, original_stack_size, bit_limit);
	return (p_data->stack_a);
}
