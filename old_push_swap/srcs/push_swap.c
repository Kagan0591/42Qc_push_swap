#include "push_swap.h"

int	main (int argc, char **argv)
{
	d_container	*data;
	int		i;

	data = malloc(sizeof(d_container));
	data->stack_a = malloc(sizeof(data->stack_a));
	data->stack_b = malloc(sizeof(data->stack_b));
	data->stack_b = NULL;
	i = 1;
	while (argv[i])
	{
		push_str_to_dlist(&argv[i], &data);
		i++;
	}
	data->stack_a = indexing_stack_to_stack(data->stack_a);
	ft_putstr("\nPrint stack a after indexing: ");
	ft_print_stack_dlink(data->stack_a);
	ft_putstr("\n\n");
	choosing_the_algo(data);
	ft_print_stack_dlink(data->stack_a);
	ft_putstr("\n\nEND OF PROGRAM\n");
	return (1);
}

int	*push_str_to_dlist(char *str, d_container *p_data)
{
	int		i;
	int		j;
	char	**nested_char;

	p_data->stack_a = NULL;
	i = 0;
	j = 0;
	while (str[i])
	{
		if (ft_isint(str) == false || ft_isnumber(str) == true || str[i] != ft_findchar_dlist(p_data->stack_a, str[i]))
		{
			if (ft_strchr(str, ' ') == ' ');
			{
				nested_char = ft_split(str, ' ');
				while (nested_char[j])
				{
					p_data->stack_a = ft_stkadd_dlink(p_data->stack_a, atoi(&str[i]));
					j++;
				}
			}
			p_data->stack_a = ft_stkadd_dlink(p_data->stack_a, atoi(&str[i]));
			i++;
		}
		else
			return (-1); // donc une des conditons n est pas rempli
	}
	return (0);
}

boolean	ft_isint_str(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] == ' ') // Pour gere une string de nombres
			i++;
		if (ft_atoll(str[i]) >= 0 && ft_atoll(str[i]) <= 9)
			return (false);
		i++;
	}
	return (true);
}

boolean	ft_isnumbers(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i]) < '0' || ft_atoll(str[i]) > '9' || str[i] != ' ')
			return (false);
		i++;
	}
	return (true);
}

char	ft_findchar_dlist(node_dlink *d_list, char c)
{
	int		i;

	i = ft_stksize_dlink(&d_list);
	while (i > 0)
	{
		if (d_list->arg == c)
			return (c);
		else
			i--;
			d_list = d_list->next;
	}
	return (NULL)
}

//IL FAUT GERER LES ERREUR IF IS INT OU REPEATED NUM
void	choosing_the_algo(d_container *p_data)
{
	if (ft_stksize_dlink(p_data->stack_a) > 5)
		ft_putstr("BIG SORT\n");
	else
		p_data->stack_a = mini_sort(p_data);
}

/* Une fonction pour placer chaques arguments dans un node d'une structure
 * en pile.
 */
node_dlink	*push_argv_to_stk(int argc, char **argv)
{
	node_dlink	*stack_a;
	argc = (argc - 1);
	stack_a = ft_stknew_dlink(atoi(argv[argc]));
	argc--;
	while (argc > 0)
	{
		stack_a = ft_stkadd_dlink(stack_a, atoi(argv[argc]));
		argc--;
	}
	return (stack_a);
}

boolean	checkif_is_sort(char **argv)
{
	int	i;
	i = 1;
	while (argv[i + 1])
	{
		if (atoll(argv[i]) > atoll(argv[i + 1]))
		{
			return (false);
		}
		i++;
	}
	return (true);
}

// node_dlink	*indexing_stack_to_stack(node_dlink *stack)
// {
// 	int			index;
// 	node_dlink	*start_of_stack;
// 	node_dlink	*original_stack;
// 	node_dlink	*stack_tmp;

// 	start_of_stack = NULL;
// 	original_stack = NULL;
// 	start_of_stack = clone_a_stack(stack, start_of_stack);
// 	original_stack = clone_a_stack(stack, original_stack);
// 	while (original_stack != NULL)
// 	{
// 		index = 0;
// 		stack_tmp = start_of_stack;
// 		while (stack_tmp != NULL)
// 		{
// 			if (original_stack->arg > stack_tmp->arg)
// 				index++;
// 			stack_tmp = stack_tmp->next;
// 		}
// 		stack->arg = index;
// 		if (original_stack->next != NULL)
// 			stack = stack->next;
// 		original_stack = original_stack->next;
// 	}
// 	ft_stkclear_dlink(start_of_stack);
// 	ft_stkclear_dlink(original_stack);
// 	while (stack->previous != NULL)
// 		stack = stack->previous;
// 	return (stack);
// }
