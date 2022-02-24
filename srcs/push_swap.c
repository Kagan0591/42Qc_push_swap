#include "push_swap.h"

int	main (int argc, char **argv)
{
	d_container	*data;
	int		i;

	data = malloc(sizeof(d_container));
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
		p_data->stack_a = mini_sort(p_data->stack_a);
}

int	check_for_error(int argc, char **argv)
{
	if (argc == 0)
		return (1);
	if (checkif_isint(argv) == false)
		return (write(2, "Error\n", 6));
	if (checkif_isdigit(argv) == false)
		return (write(2, "Error\n", 6));
	if (checkif_repeated_number(argv) == true)
		return (write(2, "Error\n", 6));
	return (0);
}


/* Une fonction pour placer chaques arguments dans une structure
 * en pile
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

/* Une fonction pour vérifier si il s'agit bien d'un chiffre pour
 * chaques arguments vector (argv)
 */
boolean	checkif_isdigit(char **argv)
{
	int	i;
	int j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (false);
			j++;
		}
		j = 0;
		i++;
	}
	return (true);
}

/* Une fonction pour vérifier si il s'agit bien d'un integrer pour
 * chaques arguments vector (argv)
 */
boolean	checkif_isint(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoll(argv[i]) < -2147483648 || ft_atoll(argv[i]) > 2147483647)
		{
			return (false);
		}
		i++;
	}
	return (true);
}

/* Une fonction pour vérifier si il n y a pas de doublon pour
 * chaques arguments vector (argv)
 */
boolean	checkif_repeated_number(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 2;

	while (argv[i])
	{
		while (argv[j])
		{
			if (ft_atoi(argv [i]) == ft_atoi(argv[j]))
				return (true);
			j++;
		}
		i++;
		j = (i + 1);
	}
	return (false);
}
