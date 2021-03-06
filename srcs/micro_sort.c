/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 12:52:33 by tchalifo          #+#    #+#             */
/*   Updated: 2022/03/23 09:56:47 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Algo pour 3 arguments
 * Le micro sort recherche le plus grand nombre et
 */

#include "push_swap.h"

// static t_bool	if_is_sort(t_dlinklst *stack)
// {
// 	while (stack->next != NULL)
// 	{
// 		if (stack->arg > stack->next->arg)
// 			return (false);
// 		stack = stack->next;
// 	}
// 	return (true);
// }

static int	find_max(t_dlinklst *stack)
{
	int	max_value;

	max_value = 0;
	while (stack != NULL)
	{
		if (stack->previous != NULL)
		{
			if (stack->arg > max_value)
				max_value = stack->arg;
		}
		else
			max_value = stack->arg;
		stack = stack->next;
	}
	return (max_value);
}

t_dlinklst	*micro_sort(t_dlinklst *stack)
{
	int	max;

	max = find_max(stack);
	if (if_is_sort(stack) == false)
	{
		if (max == stack->arg)
			stack = rotate_a(stack, 0);
		else if (max == stack->next->arg)
			stack = reverse_rotate_a(stack, 0);
		if (if_is_sort(stack) == false)
			stack = swap_a(stack);
	}
	return (stack);
}
