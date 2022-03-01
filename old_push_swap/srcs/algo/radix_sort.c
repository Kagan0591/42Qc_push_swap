#include "algo.h"

/* Rotationne la pile pour que la valeur voulu ce retrouve au sommet de la pile
 * selon le moins de coup possible. La fonctions prend le stack 'a' et le nombre
 * à trouver en paramètre.
 */
int unites_to_top_rotate_a(node **lst, int nbr_to_find)
{
	int	lst_lenght;
	int count;

	lst_lenght = ft_stksize(lst);
	count = 0;
	while ((*lst)->arg_unites != nbr_to_find || lst != NULL)
	{
		if ((*lst)->arg_unites == nbr_to_find)
		{
			if (count > (lst_lenght / 2))
				ra(lst); // Envoie l'élément du bas au sommet de la pile
			else
				rra(lst); // Envoie l'élément du haut au bas de la pile
			return (1);
		}
		count++;
		lst = (*lst)->next;
	}
	return (0); // n'a pas trouvé de chiffre correspondant
}

/* Rotationne la pile pour que la valeur voulu ce retrouve au sommet de la pile
 * selon le moins de coup possible. La fonctions prend le stack 'b' et le nombre
 * à trouver en paramètre.
 */
int unites_to_top_rotate_b(node **lst, int nbr_to_find)
{
	int	lst_lenght;
	int count;

	lst_lenght = ft_stksize(lst);
	count = 0;
	while ((*lst)->arg_unites != nbr_to_find || lst != NULL)
	{
		if ((*lst)->arg_unites == nbr_to_find)
		{
			if (count > (lst_lenght / 2))
				rb(lst); // Envoie l'élément du bas au sommet de la pile
			else
				rrb(lst); // Envoie l'élément du haut au bas de la pile
			return (1);
		}
		count++;
		lst = (*lst)->next;
	}
	return (0); // n'a pas trouvé de chiffre correspondant
}

