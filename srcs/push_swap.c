/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:29:02 by tchalifo          #+#    #+#             */
/*   Updated: 2022/02/28 13:29:02 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static int	push_args_to_dlist(char *str, d_container *p_data)
{
	char	**number_s;
	int		i;

	number_s = ft_split(str, ' ');
	i = 0;
	while (number_s[i])
	{
		if (str_isnumber(number_s[i]) == 0 || nbr_isint(ft_atoll(number_s[i])) == 0)
		{
			while (i >= 0)
			{
				free (number_s[i]);
				i--;
			}
			free (number_s);
			return (0);
		}
		p_data->stack_a = ft_dllst_addback(p_data->stack_a, \
			ft_atoll(number_s[i]), NULL);
		i++;
	}
	while (i >= 0)
	{
		free (number_s[i]);
		i--;
	}
	free (number_s);
	return (1);
}

static int	bubble_sort_lst_index(node_dlink *p_dlinklist, node_dlink *p_top_of_stack)
{
	int			index;

	index = 0;
	while (p_top_of_stack != NULL)
	{
		if (p_dlinklist->arg > p_top_of_stack->arg)
			index++;
		p_top_of_stack = p_top_of_stack->next;
	}
	return (index);
}

static node_dlink	*indexing_stack_to_stack(node_dlink *p_stack)
{
	node_dlink	*top_of_stack;
	node_dlink	*index;

	index = NULL;
	top_of_stack = p_stack;
	while (p_stack != NULL)
	{
		index = ft_dllst_addback(index, \
			bubble_sort_lst_index(p_stack, top_of_stack), NULL);
		p_stack = p_stack->next;
	}
	ft_stkclear_dlink(top_of_stack);
	return (index);
}

int	main(int argc, char **argv)
{
	d_container	*data;
	int			i;

	if (argc > 1)
	{
		data = initmem();
		i = 1;
		//pushing args to d-list
		while (i < argc)
		{
			if (arg_isunique_doublyll(argv[i], data->stack_a) == 0 \
				|| push_args_to_dlist(argv[i], data) == 0)
			{
				data = clearmem(data);
				return (write(2, "Error\n", 13));
			}
			i++;
		}
		//indexing number 0 to ...
		data->stack_a = indexing_stack_to_stack(data->stack_a);
		//micro_sort
		if (ft_stksize_dlink(data->stack_a) == 3)
			data->stack_a = micro_sort(data->stack_a);
		//mini_sort
		else if (ft_stksize_dlink(data->stack_a) <= 5)
			data->stack_a = mini_sort(data);
		//big_sort
		else if (ft_stksize_dlink(data->stack_a) > 5)
			data->stack_a = big_sort(data);
		//Print the proof of sort
		// ft_putstr("\n");
		// ft_print_stack_dlink(data->stack_a);
		// ft_putstr("\n");
		//Free
	data = clearmem(data);
	}
	return (0);
}
