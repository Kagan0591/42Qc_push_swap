
node_dlink	*micro_sort(node_dlink *stack)
{
	if (if_is_sort(stack) != true)
	{
		if (stack->arg == 0)
		{
			stack = reverse_rotate_a(stack);
			if (stack->next->arg == 0)
			{
			stack = swap_a(stack);
			}
		}
		else if (stack->arg == 1)
		{
			if (stack->next->arg == 0)
				stack = swap_a(stack);
			if (stack->next->arg == 2)
				stack = reverse_rotate_a(stack);
		}
		else
		{
			stack = rotate_a(stack);
			if (stack->next->arg == 0)
				stack = swap_a(stack);
		}
	}
	return (stack);
}
