#include "push_swap.h"

/* Algo pour 3 arguments
 * Revoir le micro sort pour marcher avec chiffre de 0 a infini
 */
static boolean	if_is_sort(node_dlink *stack)
{
	while (stack->next != NULL)
	{
		if (stack->arg > stack->next->arg)
			return (false);
		stack = stack->next;
	}
	return (true);
}

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

int	find_max(stack)
{
	int	max_value;

	max_value = 0;
	while (stack != NULL)
	{
		if (stack->arg < stack->next->arg)
			max_value = stack->next->arg;
		stack = stack->next;
	}
	return (max_value);
}

node_dlink	*micro_sort(node_dlink *stack)
{
	int	max;

	max = find_max()
	if (if_is_sort(stack) == false)
	{

}
