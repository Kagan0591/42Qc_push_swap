#include "push_swap.h"

node	*swap_stkvalue_a(node *p_stk)
{
	node	*tmp;

	ft_putstr("sa\n");
	if (ft_stksize(p_stk) >= 2)
	{
		tmp = p_stk;
		p_stk = p_stk->next;
		tmp->next = p_stk->next;
		p_stk->next = tmp;
	}
	return (p_stk);
}

node	*swap_stkvalue_b(node *p_stk)
{
	node	*tmp;

	ft_putstr("sb\n");
	if (ft_stksize(p_stk) >= 2)
	{
		tmp = p_stk;
		p_stk = p_stk->next;
		tmp->next = p_stk->next;
		p_stk->next = tmp;
	}
	return (p_stk);
}

void	push_to_a(node **origin, node **dest)
{
	node	*tmp_orig;
	node	*tmp_dest;

	ft_putstr("pa\n");
	if (origin && dest)
	{
		tmp_orig = (*origin)->next;
		tmp_dest = (*dest);
		*dest = *origin;
		(*dest)->next = tmp_dest;
		(*origin) = tmp_orig;
	}
}

void	push_to_b(node **origin, node **dest)
{
	node	*tmp_orig;
	node	*tmp_dest;

	ft_putstr("pb\n");
	if (origin && dest)
	{
		tmp_orig = (*origin)->next;
		tmp_dest = (*dest);
		*dest = *origin;
		(*dest)->next = tmp_dest;
		(*origin) = tmp_orig;
	}
}

node	*rotate_a(node *p_stk) // Put the last node to the top
{
	node	*tmp;
	node	*tmp_top;

	ft_putstr("ra\n");
	if (ft_stksize(p_stk) >= 2)
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

node	*rotate_b(node *p_stk) // Put the last node to the top
{
	node	*tmp;
	node	*tmp_top;

	ft_putstr("rb\n");
	if (ft_stksize(p_stk) >= 2)
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

node	*reverse_rotate_a(node *p_stk) // Put the first node to the buttom
{
	node		*tmp;
	node		*top_tmp;
	size_t		pos;

	ft_putstr("rra\n");
	if (ft_stksize(p_stk) >= 2)
	{
		pos = ft_stksize(p_stk);
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

node	*reverse_rotate_b(node *p_stk) // Put the first node to the buttom
{
	node		*tmp;
	node		*top_tmp;
	size_t		pos;

	ft_putstr("rrb\n");
	if (ft_stksize(p_stk) >= 2)
	{
		pos = ft_stksize(p_stk);
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
