/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:51:58 by tchalifo          #+#    #+#             */
/*   Updated: 2022/03/20 18:01:39 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Pour sort 5 nombres,
 * 1. Je divise en deux ma stack. Les 2 plus petits element
 * seront push vers b.
 * 2. Les 3 autres nombres seront sort avec micro-sort.
 * 3. Les 2 nombres restant dans la stack b sont transfere
 * dans la stack a en verifiant que le plus grand soit pus en premier.
 */

#include "push_swap.h"

static int	find_smaller_num_pos(t_dlinklst *stack, int num)
{
	int	count;

	count = 0;
	while (stack != NULL && stack->arg != num)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}

t_dlinklst	*best_case(t_dlinklst *stack, int num_position)
{
	if (ft_stksize_dlink(stack) \
		<= ((ft_stksize_dlink(stack) / 2) + num_position))
	{
		while ((ft_stksize_dlink(stack) - num_position) != 0)
		{
			stack = reverse_rotate_a(stack, 0);
			num_position++;
		}
	}
	else if (num_position > 0)
	{
		while (num_position > 0)
		{
			stack = rotate_a(stack, 0);
			num_position--;
		}
	}
	return (stack);
}

static void	mini_push_to_b_smaller_value(t_container *p_data)
{
	int	num_position;
	int	value_to_find;

	value_to_find = 0;
	while (ft_stksize_dlink(p_data->stack_a) > 3)
	{
		num_position = find_smaller_num_pos(p_data->stack_a, value_to_find);
		if (num_position > 0)
			p_data->stack_a = best_case(p_data->stack_a, num_position);
		push_to_b(p_data);
		value_to_find++;
	}
}

t_dlinklst	*mini_sort(t_container *p_data)
{
	mini_push_to_b_smaller_value(p_data);
	p_data->stack_a = micro_sort(p_data->stack_a);
	if (ft_stksize_dlink(p_data->stack_b) == 2)
	{
		if (p_data->stack_b->arg < p_data->stack_b->next->arg)
			swap_b(p_data->stack_b);
		while (p_data->stack_b != NULL)
			push_to_a(p_data);
	}
	else if (ft_stksize_dlink(p_data->stack_b) == 1)
		push_to_a(p_data);
	ft_stkclear_dlink(p_data->stack_b);
	return (p_data->stack_a);
}
