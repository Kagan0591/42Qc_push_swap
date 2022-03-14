/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_functions_doubly_linked_lis        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:35:55 by tchalifo          #+#    #+#             */
/*   Updated: 2022/02/28 13:35:55 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

node_dlink	*return_to_top(node_dlink *p_stk)
{
	while (p_stk->previous != NULL)
		p_stk = p_stk->previous;
	return (p_stk);
}

node_dlink	*clone_a_node(node_dlink *src_stack, node_dlink *dest_stack)
{
	if (!src_stack)
		return (NULL);
	else if (!dest_stack)
		return (ft_stknew_dlink(src_stack->arg, src_stack->arg_binary));
	else if ((dest_stack->next == NULL) && (dest_stack->previous != NULL))
		dest_stack = ft_dllst_addback(dest_stack, src_stack->arg, src_stack->arg_binary);
	else
		dest_stack = ft_stkadd_dlink(dest_stack, src_stack->arg, src_stack->arg_binary);
	return (dest_stack);
}

node_dlink	*clone_a_stack(node_dlink *src_stack, node_dlink *dest_stack)
{
	while (src_stack->next != NULL)
	{
		src_stack = src_stack->next;
	}
	dest_stack = clone_a_node(src_stack, dest_stack);
	while (src_stack->previous != NULL)
	{
		src_stack = src_stack->previous;
		dest_stack = clone_a_node(src_stack, dest_stack);
	}
	return (dest_stack);
}
