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

void	push_to_a(node_dlink **origin, node_dlink **dest)
{
	ft_putstr("pa\n");
	if ((*origin) == NULL)
		exit(0);
	if ((*dest) != NULL)
		(*dest) = ft_stkadd_dlink((*dest), (*origin)->arg);
	else
		(*dest) = ft_stknew_dlink((*origin)->arg);
	(*origin) = (*origin)->next;
	if ((*origin) != NULL)
	{
		ft_stkdelone_dlink((*origin)->previous);
		(*origin)->previous = NULL;
	}
}

void	push_to_b(node_dlink **origin, node_dlink **dest)
{
	ft_putstr("pb\n");
	if ((*origin) == NULL)
		exit(0);
	if ((*dest) != NULL)
		(*dest) = ft_stkadd_dlink((*dest), (*origin)->arg);
	else
		(*dest) = ft_stknew_dlink((*origin)->arg);
	(*origin) = (*origin)->next;
	ft_stkdelone_dlink((*origin)->previous);
	(*origin)->previous = NULL;
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
