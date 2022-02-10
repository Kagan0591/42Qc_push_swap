#include "push_swap.h"

// Algo pour 4 à 6 arguments

// node_dlink	*mini_sort_old(node_dlink *stack_a)
// {
// 	node_dlink	*stack_b;
// 	//node_dlink	*previous_pt_stack_b;
// 	int			i;

// 	stack_b = NULL;
// 	if (ft_stksize_dlink(stack_a) < 4)
// 	{
// 		stack_a = micro_sort(stack_a);
// 		return (stack_a);
// 	}
// 	ft_putstr("\nOriginal_stack a = ");
// 	ft_print_stack_dlink(stack_a);
// 	ft_putstr("\n");
// 	ft_putstr("\nOriginal_stack b = ");
// 	ft_print_stack_dlink(stack_b);
// 	ft_putstr("\n");
// 	i = (ft_stksize_dlink(stack_a) / 2);
// 	ft_putstr("The i number\n");
// 	ft_putnbr(i);
// 	while (i > 0)
// 	{
// 		push_to_b(&stack_a, &stack_b);
// 		i--;
// 	}
// 	ft_putstr("\nAfter push_to_b stack a = ");
// 	ft_print_stack_dlink(stack_a);
// 	ft_putstr("\n");
// 	ft_putstr("\nAfter push_to_b stack b = ");
// 	ft_print_stack_dlink(stack_b);
// 	ft_putstr("\n");
// //-- OK
// 	stack_a = indexing_stack_to_stack(stack_a);
// 	ft_putstr("\nAfter indexing stack a = ");
// 	ft_print_stack_dlink(stack_a);
// 	ft_putstr("\n");
// 	stack_a = micro_sort(stack_a);
// 	stack_b = indexing_stack_to_stack(stack_b);
// 	stack_b = micro_sort(stack_b);
// 	ft_putstr("\nAfter sort stack a = ");
// 	ft_print_stack_dlink(stack_a);
// 	ft_putstr("\n");
// 	ft_putstr("\nAfter sort stack b = ");
// 	ft_print_stack_dlink(stack_b);
// 	ft_putstr("\n");
// 	while (i < 3)
// 	{
// 		stack_b = stack_b->next;
// 		i++;
// 	}
// 	//previous_pt_stack_b = stack_b->previous;
// 	while (i < 3)
// 	{
// 		push_to_a(&stack_b, &stack_a);
// 		i++;
// 	}
// 	ft_putstr("\nAAfter push_to_a stack a = ");
// 	ft_print_stack_dlink(stack_a);
// 	ft_putstr("\n");
// 	ft_putstr("\nAfter push_to_a stack b = ");
// 	ft_print_stack_dlink(stack_b);
// 	ft_putstr("\n");
// 	return (stack_a);
// }


node_dlink	*mini_sort(node_dlink *stack_a)
{
	node_dlink	*stack_b;
	int	num;
	int	node_pos;
	int	stacksize_minus_node_pos;

	stack_b = NULL;
	if (ft_stksize_dlink(stack_a) < 4)
	{
		stack_a = micro_sort(stack_a);
		return (stack_a);
	}
	num = 0;
	while (num < 3)
	{
		node_pos = (find_pos_value(stack_a, num));
		stacksize_minus_node_pos = ((ft_stksize_dlink(stack_a)) - node_pos);

		if(node_pos >= (ft_stksize_dlink(stack_a) / 2))
		{
			while (stacksize_minus_node_pos >= 0)
			{
				stack_a = reverse_rotate_a(stack_a);
				stacksize_minus_node_pos--;
			}
		}
		else
		{
			while (stacksize_minus_node_pos > 0)
			{
				stack_a = rotate_a(stack_a);
				stacksize_minus_node_pos--;
			}
		}
			ft_print_stack_dlink(stack_a);
			push_to_b(&stack_a, &stack_b);
		num++;
	}
	return (stack_a);
}

int	find_pos_value(node_dlink *stack, int nb)
{
	static int	stack_pos;

	if (stack_pos != 0)
		stack_pos = 1;
	while (stack->arg != nb)
	{
		stack = stack->next;
		stack_pos++;
	}
	return (stack_pos);
}