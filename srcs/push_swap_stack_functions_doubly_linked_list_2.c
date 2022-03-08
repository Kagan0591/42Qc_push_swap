/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_functions_doubly_linked_lis        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:35:29 by tchalifo          #+#    #+#             */
/*   Updated: 2022/02/28 13:35:29 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	secure_del(node_dlink *p_stk)
{
	p_stk->arg = 0;
	p_stk->bit_1 = 0;
	p_stk->bit_2 = 0;
	p_stk->bit_3 = 0;
	p_stk->bit_4 = 0;
	p_stk->bit_5 = 0;
	p_stk->bit_6 = 0;
	p_stk->bit_7 = 0;
	p_stk->bit_8 = 0;
	p_stk->bit_9_most_significant = 0;
}

ft_bool	ft_stk_isempty_dlink(node_dlink *p_stk)
{
	if (p_stk == NULL)
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
	{
		ft_putstr("\nArgument en valeur décimal = ");
		ft_putnbr(p_stk->arg);
		ft_putstr("\nArgument en valeur binaire (bit 1) = ");
		ft_putnbr(p_stk->bit_1);
		ft_putstr("\nArgument en valeur binaire (bit 2) = ");
		ft_putnbr(p_stk->bit_2);
		ft_putstr("\nArgument en valeur binaire (bit 3) = ");
		ft_putnbr(p_stk->bit_3);
		ft_putstr("\nArgument en valeur binaire (bit 4) = ");
		ft_putnbr(p_stk->bit_4);
		ft_putstr("\nArgument en valeur binaire (bit 5) = ");
		ft_putnbr(p_stk->bit_5);
		ft_putstr("\nArgument en valeur binaire (bit 6) = ");
		ft_putnbr(p_stk->bit_6);
		ft_putstr("\nArgument en valeur binaire (bit 7) = ");
		ft_putnbr(p_stk->bit_7);
		ft_putstr("\nArgument en valeur binaire (bit 8) = ");
		ft_putnbr(p_stk->bit_8);
		ft_putstr("\nArgument en valeur binaire (bit 9) = ");
		ft_putnbr(p_stk->bit_9_most_significant);
		ft_putstr("\n");
	}
}

void	ft_print_stack_dlink(node_dlink *p_stk)
{
	while (p_stk != NULL)
	{
		ft_print_node_dlink(p_stk);
		p_stk = p_stk->next;
	}
}
