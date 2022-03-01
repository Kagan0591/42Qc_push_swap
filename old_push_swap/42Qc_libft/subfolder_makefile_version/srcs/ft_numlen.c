/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifour91@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 14:24:42 by tchalifo          #+#    #+#             */
/*   Updated: 2022/01/28 14:24:52 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	numlen(int n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		count++;
		n = n * -1;
	}
	while (n > 9)
	{
		n = n / 10;
		count++;
	}
	return (count);
}
