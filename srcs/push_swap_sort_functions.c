#include "push_swap.h"

node_dlink	*swap_a(node_dlink *p_stk)
{
	node_dlink	*tmp;

	ft_putstr("sa\n");
	if (ft_stksize_dlink(p_stk) > 1)
	{
		tmp = p_stk;
		p_stk = p_stk->next;
		tmp->next = p_stk->next;
		p_stk->next = tmp;
	}
	return (p_stk);
}

node_dlink	*swap_b(node_dlink *p_stk)
{
	node_dlink	*tmp;

	ft_putstr("sb\n");
	if (ft_stksize_dlink(p_stk) > 1)
	{
		tmp = p_stk;
		p_stk = p_stk->next;
		tmp->next = p_stk->next;
		p_stk->next = tmp;
	}
	return (p_stk);
}

void	push_to_a(d_container *p_data)
{
	ft_putstr("pa\n");
	if (p_data->stack_b == NULL)
		exit(0);
	if (p_data->stack_a != NULL)
		p_data->stack_a = ft_stkadd_dlink(p_data->stack_a, p_data->stack_b->arg);
	else
		p_data->stack_a = ft_stknew_dlink(p_data->stack_b->arg);
	p_data->stack_b = p_data->stack_b->next;
	if (p_data->stack_b != NULL)
	{
		ft_stkdelone_dlink(p_data->stack_b->previous);
		p_data->stack_b->previous = NULL;
	}
}

void	push_to_b(d_container *p_data)
{
	ft_putstr("pb\n");
	if (p_data->stack_a == NULL)
		exit(0);
	if (p_data->stack_b != NULL)
		(p_data->stack_b) = ft_stkadd_dlink(p_data->stack_b, p_data->stack_a->arg);
	else
		p_data->stack_b = ft_stknew_dlink(p_data->stack_a->arg);
	p_data->stack_a = p_data->stack_a->next;
	if (p_data->stack_a != NULL)
	{
		ft_stkdelone_dlink(p_data->stack_a->previous);
		p_data->stack_a->previous = NULL;
	}
}

node_dlink	*rotate_a(node_dlink *p_stk) // Put the top node to bottom
{
	node_dlink	*tmp;
	node_dlink	*new_top;

	ft_putstr("ra\n");
	if (ft_stksize_dlink(p_stk) > 1)
	{
		new_top = p_stk->next;
		tmp = p_stk;
		while (p_stk->next != NULL)
			p_stk = p_stk->next;
		tmp->next = NULL;
		tmp->previous = p_stk;
		p_stk->next = tmp;
		return (new_top);
	}
	else
		return (p_stk);
}

node_dlink	*rotate_b(node_dlink *p_stk) // Put the top node to bottom
{
	node_dlink	*tmp;
	node_dlink	*new_top;

	ft_putstr("rb\n");
	if (ft_stksize_dlink(p_stk) > 1)
	{
		new_top = p_stk->next;
		tmp = p_stk;
		while (p_stk->next != NULL)
			p_stk = p_stk->next;
		tmp->next = NULL;
		tmp->previous = p_stk;
		p_stk->next = tmp;

		return (new_top);
	}
	else
		return (p_stk);
}

node_dlink	*reverse_rotate_a(node_dlink *p_stk) // Put the last node to the top
{
	node_dlink		*new_top;

	new_top = NULL;

	ft_putstr("rra\n");
	if (ft_stksize_dlink(p_stk) > 1)
	{
		while (p_stk->next != NULL)
			p_stk = p_stk->next;
		new_top = clone_a_node(p_stk, new_top);
		p_stk = p_stk->previous;
		ft_stkdelone_dlink(p_stk->next);
		p_stk->next = NULL;
		while (p_stk->previous != NULL)
			p_stk = p_stk->previous;
		p_stk->previous = new_top;
		new_top->next = p_stk;
		return (new_top);
	}
	else
		return (p_stk);
}

node_dlink	*reverse_rotate_b(node_dlink *p_stk) // Put the last node to the top
{
	node_dlink		*new_top;

	new_top = NULL;
	ft_putstr("rrb\n");
	if (ft_stksize_dlink(p_stk) > 1)
	{
		while (p_stk->next != NULL)
			p_stk = p_stk->next;
		new_top = clone_a_node(p_stk, new_top);
		p_stk = p_stk->previous;
		ft_stkdelone_dlink(p_stk->next);
		p_stk->next = NULL;
		while (p_stk->previous != NULL)
			p_stk = p_stk->previous;
		p_stk->previous = new_top;
		new_top->previous = NULL;
		new_top->next = p_stk;
		return (new_top);
	}
	else
		return (p_stk);
}
