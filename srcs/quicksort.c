/*

1. Choisir un pivot (pour ma part le dernier nombre de la liste)

	- positionner un pointeur sur le pivot sélectionné.


2. Comparer les nombres au pivot justqu'a trouver un plus grand.

	- Positionner un le pointeur (pt_high) sur le nombre trouvé.

3. Comparer les nombres au pivot, quand un plus petit est trouvé,

	- Interchanger ce nombre avec le plus grand trouvé plus tot (pt_high).

4.

*/
#include "push_swap.h"


void	quicksort(node *stack_a)
{
	node	*pt_to_pivot;
	// stack	*bigger_than_pivot;
	// stack	*smaller_than_pivot;

	pt_to_pivot = finding_pivot(stack_a);
	swap_the_smaller_and_bigger(stack_a, pt_to_pivot);
	printf("l addresse de pt_to_stack_a = %p", stack_a);
	// ft_putstr("Le pivot est : ");
	// ft_putnbr(pt_to_pivot->arg);
	// ft_putstr("\n\nle premier nombre est : ");
	// ft_putnbr(stack_a->arg);
	// bigger_than_pivot = finding_bigger_than_pivot(stack_a, pt_to_pivot);
	// ft_putstr("\n\nLe prochain nombre plus grand que le pivot est : ");
	// ft_putnbr(bigger_than_pivot->arg);
	// smaller_than_pivot = finding_smaller_than_pivot(stack_a, pt_to_pivot);
	// ft_putstr("\n\nLe prochain nombre plus petit que le pivot est : ");
	// ft_putnbr(smaller_than_pivot->arg);

}
void	swap_the_smaller_and_bigger(node *stack_a, node *pivot)
{
	node	*bigger_than_pivot;
	node	*smaller_than_pivot;

	bigger_than_pivot = finding_bigger_than_pivot(stack_a, pivot);
	smaller_than_pivot = finding_smaller_than_pivot(stack_a, pivot);


}
node	*finding_pivot(node *pt_to_stack_a)
{
	while (pt_to_stack_a->next != NULL)
	{
		pt_to_stack_a = pt_to_stack_a->next;
	}
	return (pt_to_stack_a);
}

node	*finding_bigger_than_pivot(node *pt_to_stack_a, node *pivot)
{
	node	*pt_to_a_bigger_nb;
	printf("l addresse de pt_to_stack_a = %p", pt_to_stack_a);
	while (pt_to_stack_a->next != NULL)
	{
		if (pt_to_stack_a->arg > pivot->arg)
		{
			pt_to_a_bigger_nb = pt_to_stack_a;
			return (pt_to_a_bigger_nb);
		}
		pt_to_stack_a = pt_to_stack_a->next;
	}
	return (pt_to_stack_a);
}

node	*finding_smaller_than_pivot(node *pt_to_stack_a, node *pivot)
{
	node	*pt_to_a_smaller_nb;

	while (pt_to_stack_a->next != NULL)
	{
		if (pt_to_stack_a->arg < pivot->arg)
		{
			pt_to_a_smaller_nb = pt_to_stack_a;
			return (pt_to_a_smaller_nb);
		}
		pt_to_stack_a = pt_to_stack_a->next;
	}
	return (pt_to_stack_a);
}