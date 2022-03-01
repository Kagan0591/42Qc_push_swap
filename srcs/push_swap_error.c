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

int	isnumber_spaced(char *str) // return 1 si il y a un char qui n est pas un nombre. 0 si tous sont des nombres ou espaces.
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit((str[i] != '-' || str[i] != ' ') && str[i] == 0)) // Si le char n est pas un nombre ou un espace.
			return (1);
		i++;
	}
	return (0);
}

int	ft_isint(long long int nb)
{
	if (nb >= -2147483648 && nb <= 2147483647) // Si le nombre est un int
		return (1);
	return (0);
}
