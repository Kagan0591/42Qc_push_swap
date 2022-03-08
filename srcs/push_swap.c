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
	//pushing args to d-list
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
	if (lst_nodevalues_isunique(data->stack_a) == 0)
		return (write(2, "Error\n", 6));
	ft_putstr("\nNon Indexed Numbers: ");
	ft_print_stack_dlink(data->stack_a);
	//indexing number 0 to ...
	data->stack_a = indexing_stack_to_stack(data->stack_a);
	ft_putstr("\nIndexed numbers: ");
	ft_print_stack_dlink(data->stack_a);
	ft_putstr("\n");
	printf("\nLa moyenne de la stack a est de : %lld \n", average(data->stack_a));
	//micro_sort
	if (ft_stksize_dlink(data->stack_a) == 3)
	{
		ft_putstr("\nmicro sort movement:\n");
		data->stack_a = micro_sort(data->stack_a);
		ft_putstr("\nMicro sorted number 3 nombres: ");
		ft_print_stack_dlink(data->stack_a);
	}
	//mini_sort
	else if (ft_stksize_dlink(data->stack_a) <= 5)
	{
		ft_putstr("\nmini sort movement:\n");
		data->stack_a = mini_sort(data);
		ft_putstr("\nMini sorted number 4 et 5 nombres: ");
		ft_print_stack_dlink(data->stack_a);
	}
	//big_sort
	// else if (ft_stksize_dlink(data->stack_a) > 5)
	// {

	// }

	//FREE
	ft_putstr("\n\n");
	ft_putnbr(convert_tobase(data->stack_a->arg, 2));
	ft_putstr("\n\n");
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

	number_s = ft_split(str, ' ');
	i = 0;
	while (number_s[i])
	{
		if (str_isnumber(number_s[i]) == 0)
			return (0);
		if (nbr_isint(ft_atoll(number_s[i])) == 0)
			return (0);
		p_data->stack_a = ft_dllst_addback(p_data->stack_a, \
			ft_atoll(number_s[i]));
		i++;
	}
	return (1);
}

node_dlink	*indexing_stack_to_stack(node_dlink *p_dlinklist)
{
	node_dlink	*top_of_stack;
	node_dlink	*index;

	index = NULL;
	top_of_stack = p_dlinklist;
	while (p_dlinklist != NULL)
	{
		index = ft_dllst_addback(index, \
			bubble_sort_lst_index(p_dlinklist, top_of_stack));
		p_dlinklist = p_dlinklist->next;
	}
	return (index);
}

int	bubble_sort_lst_index(node_dlink *p_dlinklist, node_dlink *p_top_of_stack)
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
