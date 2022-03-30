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

static int	push_args_to_dlist(char *str, t_container *p_data)
{
	char	**split_args;
	int		i;

	split_args = ft_split(str, ' ');
	if (*split_args == NULL || ft_strlen_doubletab(split_args) > 11)
	{
		clear_char_tab(split_args, ft_strlen_doubletab(split_args));
		return (0);
	}
	i = 0;
	while (split_args[i])
	{
		if (str_isnumber(split_args[i]) == 0 \
			|| nbr_isint(ft_atoll(split_args[i])) == 0)
		{
			clear_char_tab(split_args, ft_strlen_doubletab(split_args));
			return (0);
		}
		p_data->stack_a = stkadd_b(p_data->stack_a, \
			ft_atoll(split_args[i]), NULL);
		i++;
	}
	clear_char_tab(split_args, i);
	return (1);
}

static int	bbl_sort_index(t_dlinklst *p_dlinklist, t_dlinklst *p_top_of_stack)
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

static t_dlinklst	*indexing_stack_to_stack(t_dlinklst *p_stack)
{
	t_dlinklst	*top_of_stack;
	t_dlinklst	*index;

	index = NULL;
	top_of_stack = p_stack;
	while (p_stack != NULL)
	{
		index = stkadd_b(index, \
			bbl_sort_index(p_stack, top_of_stack), NULL);
		p_stack = p_stack->next;
	}
	ft_stkclear_dlink(top_of_stack);
	return (index);
}

static int	initstack(t_container *p_data, int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (push_args_to_dlist(argv[i], p_data) == 0 \
				|| lst_nodevalues_isunique(p_data->stack_a) == 0)
		{
			p_data = clearmem(p_data);
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_container	*data;

	if (argc > 1)
	{
		data = initmem();
		if (initstack(data, argc, argv) == 0)
			return (write(2, "Error\n", 6));
		data->stack_a = indexing_stack_to_stack(data->stack_a);
		if (ft_stksize_dlink(data->stack_a) == 1 || \
			if_is_sort(data->stack_a) == true)
		{
			data = clearmem(data);
			return (0);
		}
		else if (ft_stksize_dlink(data->stack_a) == 3)
			data->stack_a = micro_sort(data->stack_a);
		else if (ft_stksize_dlink(data->stack_a) <= 5)
			data->stack_a = mini_sort(data);
		else if (ft_stksize_dlink(data->stack_a) > 5)
			data->stack_a = big_sort(data);
	data = clearmem(data);
	}
	return (0);
}
