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

static node_dlink	*mini_push_to_b_smaller_value(node_dlink **stack_a)
{
	int	num_position;
	int	value_to_find;
	node_dlink	*stack_b;

	stack_b = NULL;
	value_to_find = 0;
	while (ft_stksize_dlink(*stack_a) > 3)
	{
		num_position = find_smaller_num_pos(*stack_a, value_to_find);
		if ((ft_stksize_dlink(*stack_a) / 2) < num_position)
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
		push_to_b(stack_a, &stack_b);
		value_to_find++;
	}
	return (stack_b);
}

node_dlink	*mini_sort(node_dlink *stack_a)
{
	node_dlink *stack_b;

	stack_b = NULL;

	stack_b = mini_push_to_b_smaller_value(&stack_a);
	ft_putstr("\nstack_a\n");
	ft_print_stack_dlink(stack_a);
	ft_putstr("\nstack_b\n");
	ft_print_stack_dlink(stack_b);
	ft_putstr("\n\n");
	stack_a = indexing_stack_to_stack(stack_a);
	ft_putstr("\nstack_a after indexing\n");
	ft_print_stack_dlink(stack_a);
	ft_putstr("\n\n");
	stack_a = micro_sort(stack_a);
	ft_putstr("\nstack_a after sort\n");
	ft_print_stack_dlink(stack_a);
	ft_putstr("\n\n");
	if (stack_b)



	return (stack_a);

}
