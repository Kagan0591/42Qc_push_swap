/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:30:23 by tchalifo          #+#    #+#             */
/*   Updated: 2022/02/28 13:30:23 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_isnumber(char *str)
{
	int		i;

	i = 0;
	if ((str[i] == '-') && (ft_isdigit(str[i + 1])))
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	nbr_isint(long long int nb)
{
	if (nb >= -2147483648 && nb <= 2147483647)
		return (1);
	return (0);
}

int	lst_nodevalues_isunique(t_dlinklst *lst)
{
	t_dlinklst	*lst_cpy;

	while (lst->next != NULL)
	{
		lst_cpy = lst->next;
		while (lst_cpy != NULL)
		{
			if (lst->arg == lst_cpy->arg)
				return (0);
			lst_cpy = lst_cpy->next;
		}
		lst = lst->next;
	}
	return (1);
}

t_bool	if_is_sort(t_dlinklst *stack)
{
	if (ft_stksize_dlink(stack) < 2)
	{
		return (false);
	}
	while (stack->next != NULL)
	{
		if (stack->arg > stack->next->arg)
			return (false);
		stack = stack->next;
	}
	return (true);
}
