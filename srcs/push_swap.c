#include "push_swap.h"

/* L'algorithme Quick Sort est le plus éfficace pour le tri de petites
 * quantités de données. Il est préferé pour les tableaux.
 *
 * 1. Le tableau d'éléments est divisé en plusieurs parties jusqu'à ce
 * qu'il ne soit plus possible de le diviser davantage.
 *
 * 2. Il utilise un élément clé (un pivot) pour partitionner les éléments.
 * Ainsi, Une partition de gauche contient tous les éléments qui sont
 * plus petits que le pivot et une partition de droite contient tous
 * les éléments qui sont plus grands que l'élément clé.
 *
 * 3. Les éléments sont divisés en deux sous-tableaux (n/2) encore et encore
 * jusqu'à ce qu'il ne reste qu'un seul élément.
 * */




/* L'algorithme Merge Sort est très éfficace pour le tri de grandes
 * quantités de données. Il est préferé pour les listes chainées.
 *
 * 1. Les éléments sont divisés en deux sous-tableaux (n/2) encore et encore
 * jusqu'à ce qu'il ne reste qu'un seul élément.
 *
 * 2.Le tri par fusion utilise de l espace stockage supplémentaire
 * pour trier les tableaux auxiliaires.
 *
 * 3. Le tri par fusion utilise trois tableaux, où deux sont utilisés
 * pour stocker chaque moitié, et le troisième, externe, est utilisé
 * pour stocker la liste triée finale en fusionnant les deux autres
 * et chaque tableau est ensuite trié de manière récursive. Donc, tant
 * qu'il peut etre divisé, le tableau sera récursivement divisé.
 *
 * 4. Enfin, tous les sous-tableaux sont fusionnés pour ne faire qu'un
 * tableau de « n » taille d'élément.*/

// radix sort si j arrive pas a faire moi memm un algo, il est performant et facile a implementer


int	main (int argc, char **argv)
{
	// (void) argc;
	// (void) argv;
	node_dlink	*stk_a;
//	node_dlink	*indexed_stk_a;
//	node_dlink	*stk_b;
//	stk_b = NULL;
	int		i;
//	stk_b = NULL;
//	indexed_stk_a = NULL;
	i = 1;
//	Print the nbr of arg(s)
//	ft_printf("Le nombre d'argument passé est de %i incluant le nom du programme\n", argc);
	ft_putstr("Le nombre d'argument passé, incluant le nom du programme, est de: ");
	ft_putnbr(argc);
	ft_putstr("\n\n");
//	Add the data from argv to stk_a
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
	stk_a = push_argv_to_stk(argc, argv);
	stk_a = indexing_stack_to_stack(stk_a);
	ft_putstr("\n");
	ft_print_stack_dlink(stk_a);
	ft_putstr("\n");
	stk_a = mini_sort(stk_a);
	ft_print_stack_dlink(stk_a);
	ft_putstr("\n\nEND OF PROGRAM\n");

	return (1);
}

// CHECL FOR 5 NUMBER PROBLEME WHEN MICRO SORT



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
