/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:10:03 by tchalifo          #+#    #+#             */
/*   Updated: 2022/03/18 12:10:03 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlinklst	*swap_a(t_dlinklst *p_stk)
{
	t_dlinklst	*tmp;

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

t_dlinklst	*swap_b(t_dlinklst *p_stk)
{
	t_dlinklst	*tmp;

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

void	push_to_a(t_container *p_data)
{
	t_dlinklst	*isolated_top_b;

	ft_putstr("pa\n");
	if (p_data->stack_b == NULL)
		exit(0);
	else
	{
		isolated_top_b = p_data->stack_b;
		p_data->stack_b = p_data->stack_b->next;
		if (p_data->stack_b != NULL)
			p_data->stack_b->previous = NULL;
		if (p_data->stack_a != NULL)
		{
			p_data->stack_a->previous = isolated_top_b;
			isolated_top_b->next = p_data->stack_a;
			while (p_data->stack_a->previous != NULL)
				p_data->stack_a = p_data->stack_a->previous;
		}
		else
		{
			isolated_top_b->next = NULL;
			p_data->stack_a = isolated_top_b;
		}
	}
}

void	push_to_b(t_container *p_data)
{
	t_dlinklst	*isolated_top_a;

	ft_putstr("pb\n");
	if (p_data->stack_a == NULL)
		exit(0);
	else
	{
		isolated_top_a = p_data->stack_a;
		p_data->stack_a = p_data->stack_a->next;
		if (p_data->stack_a != NULL)
			p_data->stack_a->previous = NULL;
		if (p_data->stack_b != NULL)
		{
			p_data->stack_b->previous = isolated_top_a;
			isolated_top_a->next = p_data->stack_b;
			while (p_data->stack_b->previous != NULL)
				p_data->stack_b = p_data->stack_b->previous;
		}
		else
		{
			isolated_top_a->next = NULL;
			p_data->stack_b = isolated_top_a;
		}
	}
}

t_dlinklst	*rotate_a(t_dlinklst *p_stk, int flag)
{
	t_dlinklst	*isolated_top;

	if (flag == 0)
		ft_putstr("ra\n");
	if (ft_stksize_dlink(p_stk) > 1)
	{
		isolated_top = p_stk;
		p_stk = p_stk->next;
		p_stk->previous = NULL;
		while (p_stk->next != NULL)
			p_stk = p_stk->next;
		p_stk->next = isolated_top;
		isolated_top->previous = p_stk;
		isolated_top->next = NULL;
		return (return_to_top(p_stk));
	}
	return (p_stk);
}
