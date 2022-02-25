/* Pour sort 5 nombres,
 * 1. Je divise en deux ma stack. Les 2 plus petits element
 * seront push vers b.
 * 2. Les 3 autres nombres seront sort avec micro-sort.
 * 3. Les 2 nombres restant dans la stack b sont transfere
 * dans la stack a en verifiant que le plus grand soit pus en premier.
 */

#include "push_swap.h"

static int	find_smaller_num_pos(node_dlink *stack, int num)
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

static void	mini_push_to_b_smaller_value(d_container *p_data)
{
	int	num_position;
	int	value_to_find;

	value_to_find = 0;
	while (ft_stksize_dlink(p_data->stack_a) > 3)
	{
		num_position = find_smaller_num_pos(p_data->stack_a, value_to_find);
		if (ft_stksize_dlink(p_data->stack_a) <= ((ft_stksize_dlink(p_data->stack_a) / 2) + num_position))
			while ((ft_stksize_dlink(p_data->stack_a) - num_position) != 0)
			{
				p_data->stack_a = reverse_rotate_a(p_data->stack_a);
				num_position++;
			}
		else if (num_position > 0)
			while (num_position > 0)
			{
				p_data->stack_a = rotate_a(p_data->stack_a);
				num_position--;
			}
		push_to_b(p_data);
		value_to_find++;
	}
}

node_dlink	*mini_sort(d_container *p_data)
{
	mini_push_to_b_smaller_value(p_data);
	p_data->stack_a = micro_sort(p_data->stack_a);
	if (p_data->stack_b)
	{
		if (p_data->stack_b->arg < p_data->stack_b->next->arg)
			swap_b(p_data->stack_b);
		while(p_data->stack_b != NULL)
			push_to_a(p_data);
	}
	ft_stkclear_dlink(p_data->stack_b);
	return (p_data->stack_a);
}
