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
 */

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
 * tableau de « n » taille d'élément.
 */

// radix sort si j arrive pas a faire moi meme un algo, il est performant et facile a implementer

int	main (int argc, char **argv)
{
	node_dlink	*stk_a;
	int		i;

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
	stk_a = push_argv_to_stk(argc, argv);
	stk_a = indexing_stack_to_stack(stk_a);
	ft_putstr("\nPrint stack a after indexing: ");
	ft_print_stack_dlink(stk_a);
	ft_putstr("\n\n");
	stk_a = mini_sort(stk_a);
	ft_print_stack_dlink(stk_a);
	ft_putstr("\n\nEND OF PROGRAM\n");
	return (1);
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
