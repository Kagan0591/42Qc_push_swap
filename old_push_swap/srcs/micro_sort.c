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

static int	find_max(node_dlink *stack)
{
	int	max_value;

	max_value = 0;
	while (stack != NULL)
	{
		if (stack->previous != NULL)
		{
			if (stack->arg > max_value)
				max_value = stack->arg;
		}
		else
			max_value = stack->arg;
		stack = stack->next;
	}
	return (max_value);
}

node_dlink	*micro_sort(node_dlink *stack)
{
	int	max;

	max = find_max(stack);
	if (if_is_sort(stack) == false)
	{
		if (max == stack->arg)
			stack = rotate_a(stack);
		else if (max == stack->next->arg)
			stack = reverse_rotate_a(stack);
		if (if_is_sort(stack) == false)
			stack = swap_a(stack);
	}
	return (stack);
}
