/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_functions_doubly_linked_lis        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:34:48 by tchalifo          #+#    #+#             */
/*   Updated: 2022/02/28 13:34:48 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_dlinklst	*ft_stknew_dlink(long long int nbr, int *arg_binary)
{
	t_dlinklst	*new_node;

	(void) arg_binary;
	new_node = malloc(sizeof(t_dlinklst));
	if (new_node)
	{
		new_node->arg = nbr;
		new_node->arg_binary = calloc(sizeof(int), 32);
		new_node->next = NULL;
		new_node->previous = NULL;
	}
	return (new_node);
}

t_dlinklst	*stkadd(t_dlinklst *p_stk, long long int nbr, int *arg_bin)
{
	t_dlinklst	*new_node;

	if (!p_stk)
		return (ft_stknew_dlink(nbr, arg_bin));
	new_node = malloc(sizeof(t_dlinklst));
	if (new_node)
	{
		new_node->arg = nbr;
		new_node->arg_binary = calloc(sizeof(int), 32);
		new_node->next = p_stk;
		new_node->previous = NULL;
		p_stk->previous = new_node;
		return (new_node);
	}
	return (NULL);
}

t_dlinklst	*stkadd_b(t_dlinklst *p_stk, long long int nbr, int *arg_bin)
{
	t_dlinklst	*new_node;

	if (!p_stk)
		return (ft_stknew_dlink(nbr, arg_bin));
	new_node = malloc(sizeof(t_dlinklst));
	if (new_node)
	{
		while (p_stk->next != NULL)
			p_stk = p_stk->next;
		new_node->arg = nbr;
		new_node->arg_binary = calloc(sizeof(int), 32);
		new_node->next = NULL;
		new_node->previous = p_stk;
		p_stk->next = new_node;
		while (p_stk->previous != NULL)
			p_stk = p_stk->previous;
		return (p_stk);
	}
	return (NULL);
}

void	ft_stkdelone_dlink(t_dlinklst *p_stk)
{
	if (p_stk)
	{
		secure_del(p_stk);
		free (p_stk->arg_binary);
		free(p_stk);
	}
}

void	ft_stkclear_dlink(t_dlinklst *p_stk)
{
	t_dlinklst	*tmp;

	tmp = NULL;
	while (p_stk != NULL)
	{
		tmp = p_stk->next;
		ft_stkdelone_dlink(p_stk);
		p_stk = tmp;
	}
}
