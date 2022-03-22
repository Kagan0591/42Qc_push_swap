/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_mem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 16:41:12 by tchalifo          #+#    #+#             */
/*   Updated: 2022/03/22 14:54:21 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_container	*initmem(void)
{
	t_container	*data;

	data = malloc(sizeof(t_container));
	data->dualmouv_flag = 0;
	data->stack_a = NULL;
	data->stack_b = NULL;
	return (data);
}

t_container	*clearmem(t_container *p_data)
{
	if (p_data)
	{
		if (p_data->stack_a != NULL)
			ft_stkclear_dlink(p_data->stack_a);
		if (p_data->stack_b != NULL)
			ft_stkclear_dlink(p_data->stack_b);
	}
	free(p_data);
	p_data = NULL;
	return (p_data);
}

void	clear_int_tab(int **tab, int size)
{
	while (size >= 0)
	{
		free (tab[size]);
		size--;
	}
	free (tab);
}

void	clear_char_tab(char **tab, int size)
{
	while (size >= 0)
	{
		free (tab[size - 1]);
		size--;
	}
	free (tab);
}
