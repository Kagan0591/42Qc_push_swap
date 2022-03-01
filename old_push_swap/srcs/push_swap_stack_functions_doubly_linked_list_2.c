#include "push_swap.h"

boolean 	ft_stk_isempty_dlink(node_dlink *p_stk)
{
	if(p_stk == NULL)
		return (true);
	return (false);
}

int	ft_stksize_dlink(node_dlink *p_stk)
{
	int	count;

	count = 0;
	while (p_stk != NULL)
	{
		count++;
		p_stk = p_stk->next;
	}
	return (count);
}

void	ft_print_node_dlink(node_dlink *p_stk)
{
	if (p_stk != NULL)
		ft_putnbr(p_stk->arg);
}

void	ft_print_stack_dlink(node_dlink *p_stk)
{
	while (p_stk != NULL)
	{
		ft_print_node_dlink(p_stk);
		p_stk = p_stk->next;
	}
}

node_dlink	*return_to_top(node_dlink *stack)
{
	while (stack->previous != NULL)
		stack = stack->previous;
	return (stack);
}
