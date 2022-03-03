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

int	main(int argc, char **argv)
{
	d_container	*data;
	int			i;

	data = malloc(sizeof(data));
	data->stack_a = NULL;
	data->stack_b = NULL;
	i = 1;
	while (i < argc)
	{
		if (push_args_to_dlist(argv[i], data) == 0)
		{
			free(data->stack_a);
			free(data);
			return (write(2, "Error\n", 6));
		}
		i++;
	}
	if (nbr_isunique(data->stack_a) == 0)
		return (write(2, "Error\n", 6));
	ft_putstr("\nNon Indexed Numbers: ");
	ft_print_stack_dlink(data->stack_a);
	data->stack_a = indexing_stack_to_stack(data->stack_a);
	ft_putstr("\nIndexed numbers: ");
	ft_print_stack_dlink(data->stack_a);
	//FREE
	ft_stkclear_dlink(data->stack_a);
	ft_stkclear_dlink(data->stack_b);
	free(data);
	data = NULL;
	ft_putstr("\nEND OF PROGRAM\n");
	return (0);
}

int	push_args_to_dlist(char *str, d_container *p_data)
{
	char	**number_s;
	int		i;
	int		j;

	number_s = ft_split(str, ' ');
	i = 0;
	j = 1;
	while (number_s[i])
	{
		if (str_isnumber(number_s[i]) == 0)
			return (0);
		if (nbr_isint(ft_atoll(number_s[i])) == 0)
			return (0);
		p_data->stack_a = ft_dllst_addback(p_data->stack_a, ft_atoll(number_s[i]));
		i++;
	}
	return (1);
}

node_dlink	*indexing_stack_to_stack(node_dlink *p_dlinklist)
{
	int			index;
	node_dlink	*start_of_stack;
	node_dlink	*original_stack;

	original_stack = NULL;
	start_of_stack = NULL;
	start_of_stack = clone_a_stack(p_dlinklist, start_of_stack);
	original_stack = clone_a_stack(p_dlinklist, original_stack);
	while (original_stack != NULL)
	{
		// while (stack_tmp != NULL)
		// {
		// 	if (original_stack->arg > stack_tmp->arg)
		// 		index++;
		// 	stack_tmp = stack_tmp->next;
		// }
		index = bubble_sort_list_indexation(p_dlinklist, start_of_stack);
		p_dlinklist->arg = index;
		original_stack = original_stack->next;
		if (p_dlinklist->next != NULL)
			p_dlinklist = p_dlinklist->next;
	}
	while (p_dlinklist->previous != NULL)
		p_dlinklist = p_dlinklist->previous;
	ft_stkclear_dlink(start_of_stack);
	ft_stkclear_dlink(original_stack);
	return (p_dlinklist);
}

int	bubble_sort_list_indexation(node_dlink *p_dlinklist, node_dlink *p_dlinklist_top)
{
	// node_dlink	*stack_tmp;
	int			index;

	// stack_tmp = NULL;
	index = 0;
	// stack_tmp = clone_a_stack(p_dlinklist, stack_tmp);
	// stack_tmp = p_dlinklist_top;
	while (p_dlinklist_top != NULL)
	{
		if (p_dlinklist->arg > p_dlinklist_top->arg)
			index++;
		p_dlinklist_top = p_dlinklist_top->next;
	}
	return (index);
}