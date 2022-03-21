/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_functions_2.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 13:04:12 by tchalifo          #+#    #+#             */
/*   Updated: 2022/03/20 18:00:22 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlinklst	*rotate_b(t_dlinklst *p_stk, int flag)

{
	t_dlinklst	*isolated_top;

	if (flag == 0)
		ft_putstr("rb\n");
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

t_dlinklst	*reverse_rotate_a(t_dlinklst *p_stk, int flag)
{
	t_dlinklst		*new_top;

	if (flag == 0)
		ft_putstr("rra\n");
	if (ft_stksize_dlink(p_stk) > 1)
	{
		while (p_stk->next->next != NULL)
			p_stk = p_stk->next;
		new_top = p_stk->next;
		p_stk->next = NULL;
		while (p_stk->previous != NULL)
			p_stk = p_stk->previous;
		p_stk ->previous = new_top;
		p_stk->previous->next = p_stk;
		p_stk->previous->previous = NULL;
		return (new_top);
	}
	return (p_stk);
}

t_dlinklst	*reverse_rotate_b(t_dlinklst *p_stk, int flag)
{
	t_dlinklst		*new_top;

	if (flag == 0)
		ft_putstr("rrb\n");
	if (ft_stksize_dlink(p_stk) > 1)
	{
		while (p_stk->next->next != NULL)
			p_stk = p_stk->next;
		new_top = p_stk->next;
		p_stk->next = NULL;
		while (p_stk->previous != NULL)
			p_stk = p_stk->previous;
		p_stk ->previous = new_top;
		p_stk->previous->next = p_stk;
		p_stk->previous->previous = NULL;
		return (new_top);
	}
	return (p_stk);
}

void	rotate_ab(t_container *p_data)
{
	p_data->dualmouv_flag = 1;
	if (ft_stksize_dlink(p_data->stack_a) > 1 \
		&& ft_stksize_dlink(p_data->stack_b) > 1)
	{
		ft_putstr("rr");
		p_data->stack_a = rotate_a(p_data->stack_a, p_data->dualmouv_flag);
		p_data->stack_b = rotate_b(p_data->stack_b, p_data->dualmouv_flag);
		p_data->dualmouv_flag = 0;
	}
}

void	reverse_rotate_ab(t_container *p_data)
{
	p_data->dualmouv_flag = 1;
	if (ft_stksize_dlink(p_data->stack_a) > 1 \
		&& ft_stksize_dlink(p_data->stack_b) > 1)
	{
		ft_putstr("rrr");
		p_data->stack_a = reverse_rotate_a \
			(p_data->stack_a, p_data->dualmouv_flag);
		p_data->stack_b = reverse_rotate_b \
			(p_data->stack_b, p_data->dualmouv_flag);
		p_data->dualmouv_flag = 0;
	}
}
