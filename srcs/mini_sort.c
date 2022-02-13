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

static void	mini_push_to_b_smaller_value(node_dlink **stack_a, node_dlink **stack_b)
{
	int	num_position;
	int	value_to_find;

	value_to_find = 0;
	while (ft_stksize_dlink(*stack_a) > 3)
	{
		ft_print_stack_dlink((*stack_a));
		num_position = find_smaller_num_pos(*stack_a, value_to_find);
		if (ft_stksize_dlink(*stack_a) <= ((ft_stksize_dlink(*stack_a) / 2) + num_position))
			while ((ft_stksize_dlink(*stack_a) - num_position) != 0)
			{
				*stack_a = reverse_rotate_a(*stack_a);
				num_position++;
			}
		else if (num_position > 0)
			while (num_position > 0)
			{
				*stack_a = rotate_a(*stack_a);
				num_position--;
			}
		push_to_b(stack_a, stack_b);
		value_to_find++;
	}
}

node_dlink	*mini_sort(node_dlink *stack_a)
{
	node_dlink *stack_b;

	stack_b = NULL;

	mini_push_to_b_smaller_value(&stack_a, &stack_b);
	stack_a = micro_sort(stack_a);
	if (stack_b)
	{
		if (stack_b->arg < stack_b->next->arg)
			swap_b(stack_b);
		while(stack_b != NULL)
			push_to_a(&stack_b, &stack_a);
	}
	ft_stkclear_dlink(stack_b);
	return (stack_a);
}
