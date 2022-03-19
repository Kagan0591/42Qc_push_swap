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
