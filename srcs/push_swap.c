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
		if (isnumber_spaced(argv[i]) == 1)
			return (write(2, "Error\n", 6));
		push_args_to_dlist(argv[i], data);
		i++;
	}
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

	number_s = ft_split(str, ' ');
	i = 0;
	while (number_s[i])
	{
		if (ft_isint(ft_atoll(number_s[i])) == 0)
			return (write(2, "Error\n", 6));
		p_data->stack_a = ft_dllst_addback(p_data->stack_a, ft_atoll(number_s[i]));
		i++;
	}
	return (0);
}


