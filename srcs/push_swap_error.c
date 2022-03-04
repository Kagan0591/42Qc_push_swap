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
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0) // Si le char n est pas un nombre.
			return (0);
		i++;
	}
	return (1);
}

int	nbr_isint(long long int nb)
{
	if (nb >= -2147483648 && nb <= 2147483647) // Si le nombre est un int
		return (1);
	return (0);
}

int	nbr_isequal(long long int nb1, long long int nb2)
{
	if (nb1 == nb2)
		return (1);
	return (0);
}

int	lst_nodevalues_isunique(node_dlink *lst)
{
	node_dlink	*lst_cpy;

	lst_cpy = lst;
	while (lst->next != NULL)
	{
		while (lst_cpy->next != NULL)
		{
			if (lst->arg == lst_cpy->next->arg)
				return (0);
			lst_cpy = lst_cpy->next;
		}
		lst = lst->next;
		lst_cpy = lst;
	}
	return (1);
}
