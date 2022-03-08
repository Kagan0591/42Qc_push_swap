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
	int		i;

	i = 0;
	p_stk->arg = 0;
	while ((p_stk->arg_binary != NULL) && (i < 32))
	{
		p_stk->arg_binary[i] = 0;
		i++;
	}
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
	int		i;

	i = 23; // Pour commencer a la position du 9 ieme bit
	if (p_stk != NULL)
	{
		ft_putstr("\nArgument en valeur décimal = ");
		ft_putnbr(p_stk->arg);
		ft_putstr("\nArgument en valeur binaire = ");

		while ((p_stk ->arg_binary != NULL) && (i < 32))
		{
			ft_putnbr(p_stk->arg_binary[i]);
			i++;
		}
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
