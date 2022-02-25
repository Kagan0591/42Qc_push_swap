#include "push_swap.h"

int	main (int argc, char **argv)
{
	d_container	*data;
	int		i;

	data = malloc(sizeof(d_container));
	data->stack_a = malloc(sizeof(data->stack_a));
	data->stack_b = malloc(sizeof(data->stack_b));
	i = 1;
	if (check_for_error(argc - 1, argv) > 0)
		return (0);
	if (checkif_is_sort(argv) == true)
	{
		while (argv[i])
		{
			ft_putstr(argv[i]);
			i++;
		}
		ft_putstr("\n");
		return (1);
	}
	data->stack_a = push_argv_to_stk(argc, argv);
	data->stack_a = indexing_stack_to_stack(data->stack_a);
	ft_putstr("\nPrint stack a after indexing: ");
	ft_print_stack_dlink(data->stack_a);
	ft_putstr("\n\n");
	choosing_the_algo(data);
	ft_print_stack_dlink(data->stack_a);
	ft_putstr("\n\nEND OF PROGRAM\n");
	return (1);
}

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

node_dlink	*indexing_stack_to_stack(node_dlink *stack)
{
	int			index;
	node_dlink	*start_of_stack;
	node_dlink	*original_stack;
	node_dlink	*stack_tmp;

	start_of_stack = NULL;
	original_stack = NULL;
	start_of_stack = clone_a_stack(stack, start_of_stack);
	original_stack = clone_a_stack(stack, original_stack);
	while (original_stack != NULL)
	{
		index = 0;
		stack_tmp = start_of_stack;
		while (stack_tmp != NULL)
		{
			if (original_stack->arg > stack_tmp->arg)
				index++;
			stack_tmp = stack_tmp->next;
		}
		stack->arg = index;
		if (original_stack->next != NULL)
			stack = stack->next;
		original_stack = original_stack->next;
	}
	ft_stkclear_dlink(start_of_stack);
	ft_stkclear_dlink(original_stack);
	while (stack->previous != NULL)
		stack = stack->previous;
	return (stack);
}
