#include "push_swap.h"

node_dlink	*swap_a(node_dlink *p_stk)
{
	node_dlink	*tmp;

	ft_putstr("sa\n");
	if (ft_stksize_dlink(p_stk) >= 2)
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
	if (ft_stksize_dlink(p_stk) >= 2)
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
	ft_stkdelone_dlink((*origin));
}

void	push_to_b(node_dlink **origin, node_dlink **dest)
{
	ft_putstr("pb\n");
	if ((*origin) == NULL)
	{
		exit(0);
	}
	if ((*dest) != NULL)
	{
		(*dest) = ft_stkadd_dlink((*dest), (*origin)->arg);
	}
	else
		(*dest) = ft_stknew_dlink((*origin)->arg);
	(*origin) = ft_stkdelone_dlink((*origin));
}

node_dlink	*rotate_a(node_dlink *p_stk) // Put the last node to the top
{
	node_dlink	*tmp;
	node_dlink	*tmp_top;

	ft_putstr("ra\n");
	if (ft_stksize_dlink(p_stk) >= 2)
	{
		tmp_top = p_stk->next;
		tmp = p_stk;
		while (p_stk->next != NULL)
			p_stk = p_stk->next;
		tmp->next = NULL;
		p_stk->next = tmp;
		return (tmp_top);
	}
	else
		return (p_stk);
}

node_dlink	*rotate_b(node_dlink *p_stk) // Put the last node to the top
{
	node_dlink	*tmp;
	node_dlink	*tmp_top;

	ft_putstr("rb\n");
	if (ft_stksize_dlink(p_stk) >= 2)
	{
		tmp_top = p_stk->next;
		tmp = p_stk;
		while (p_stk->next != NULL)
			p_stk = p_stk->next;
		tmp->next = NULL;
		p_stk->next = tmp;
		return (tmp_top);
	}
	else
		return (p_stk);
}

node_dlink	*reverse_rotate_a(node_dlink *p_stk) // Put the first node to the buttom
{
	node_dlink		*tmp;
	node_dlink		*top_tmp;
	size_t			pos;

	ft_putstr("rra\n");
	if (ft_stksize_dlink(p_stk) >= 2)
	{
		pos = ft_stksize_dlink(p_stk);
		tmp = p_stk;
		while (pos > 2)
		{
			p_stk = p_stk->next;
			pos--;
		}
		top_tmp = p_stk->next;
		p_stk->next = NULL;
		top_tmp->next = tmp;
		return (top_tmp);
	}
	else
		return (p_stk);
}

node_dlink	*reverse_rotate_b(node_dlink *p_stk) // Put the first node to the buttom
{
	node_dlink		*tmp;
	node_dlink		*top_tmp;
	size_t			pos;

	ft_putstr("rrb\n");
	if (ft_stksize_dlink(p_stk) >= 2)
	{
		pos = ft_stksize_dlink(p_stk);
		tmp = p_stk;
		while (pos > 2)
		{
			p_stk = p_stk->next;
			pos--;
		}
		top_tmp = p_stk->next;
		p_stk->next = NULL;
		top_tmp->next = tmp;
		return (top_tmp);
	}
	else
		return (p_stk);
}
