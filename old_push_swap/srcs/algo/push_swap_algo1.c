#include "push_swap.h"

/* Pseudo code
 * Recursion utilise pour trier le stack avec des swap de nombre
 *
 *
 * Le parsing de la stack_a pour verifier si elle est en ordre croissant.
 *
void	sort_algo(**ptr_stack_a, **ptr_stk_b)
{
	stack	*stk_a_tmp;

	stk_a_tmp = ptr_stack_a->next;

	while (ptr_stack_a != NULL)
	{
		if (stk_a_tmp->arg > ptr_stack_a)
		{
			ptr_stack_a = ptr_stack_a->next;
			stk_a_tmp = stk_a_tmp->next;
		}
		else
			split_recursive(stack_a, stack_b);

	}
 * La fonction qui trie de maniere

void	split_recursive(stack **stack_a, stack **stack_b)
{
		split_stack(stack_a, stack_b);
		split_recursive(stack_a, stack_b);
		if ((stack_a->arg > 0 && stack_a->arg < 9) && (stack_b->arg > 0 && stack_b->arg < 9)
		{
			push_to_a(stack_b);
			if (stack_a->arg < stack_b->arg)
				rotate(stack_a);
		}
		else
		{
			while (stack_b->next != NULL)
			{
				if (search_and_return_the_smaller_nb_into_a(stack_a) < stack_b->arg)
				{
					push_to_a(stack_b);
					rotate_a(stack_a);
				}
				else if (search_and_return_the_smaller_nb_into_a(stack_a) > stack_b->arg)
					push_to_a(stack_b);

				stack_b = stack_b->next;
			}
		}
}

void	split_stack(stack **ptr_stack_a, stack **ptr_stack_b)
{
	size_t	count;

	count = (ft_stksize(ptr_stack_a) / 2);
	while (count > 0)
	{
		push_to_b(ptr_stack_a, ptr_stack_b);
		count--;
	}
}

int	search_and_return_the_smaller_nb_into_a(stack *stack_a)
{
	int smaller_nbr;

	smaller_nbr = INT_MAX;
	while (stack_a != NULL)
	{
		while (stack_a->arg < smaller_nbr)
		{
			smaller_nbr = stack_a->arg;
			stack_a = ptr_stack_a->next;
		}
	}
	return (smaller_nbr);
}
*/

void	sort_algo(node **ptr_stack_a, node **ptr_stk_b)
{
	node	*stk_a_tmp;
	node	*stk_a_cpy;

	stk_a_tmp = (*ptr_stack_a)->next;
	stk_a_cpy = *ptr_stack_a;

	while (stk_a_tmp != NULL) // Verifie si les nombres sont tries deja ou pas en comparant le premier avec le prochain
	{
		if (stk_a_tmp->arg > stk_a_cpy->arg)
		{
			stk_a_cpy = stk_a_tmp;
			stk_a_tmp = stk_a_tmp->next;
		}
		else
			split_recursive(ptr_stack_a, ptr_stk_b);
	}
}

// La fonction de deconstruction et la recursive


void	split_recursive(node **stack_a, node **stack_b)
{
	split_stack(stack_a, stack_b);
	ft_putstr("\nprint stack a apres split\n");
	ft_print_stack(*stack_a);
	ft_putstr("\nprint stack b apres split\n");
	ft_print_stack(*stack_b);
	ft_putstr("\n");
	while (ft_stksize(*stack_a) != 1)
		split_recursive(stack_a, stack_b);
	if (((*stack_b)->arg > 0) && ((*stack_b)->arg < 9)) // Verifie si il y a qu un nombre
	{
		if ((*stack_a)->arg < (*stack_b)->arg)
		{
			push_to_a(stack_b, stack_a);
			*stack_a = rotate_a(*stack_a);
		}
		else
			push_to_a(stack_b, stack_a);
	}
	while (stack_b != NULL) // si il y a pleusieurs nombre dans stack_b
	{
		if((*stack_b)->arg < (*stack_a)->arg)
			push_to_a(stack_b, stack_a);
		else
		{
			push_to_a(stack_b, stack_a);
			*stack_a = rotate_a(*stack_a);
		}
		*stack_b = (*stack_b)->next;
	}
}

void	split_stack(node **ptr_stack_a, node **ptr_stack_b)
{
	size_t	count;

	count = (ft_stksize(*ptr_stack_a) / 2);
	while (count > 0)
	{
		ft_putnbr((*ptr_stack_a)->arg);
		push_to_b(ptr_stack_a, ptr_stack_b);
		count--;
	}
}

		// else
		// {
		// 	while (stack_b->next != NULL)
		// 	{
		// 		if (search_and_return_the_smaller_nb_into_a(stack_a) < stack_b->arg)
		// 		{
		// 			push_to_a(stack_b);
		// 			rotate_a(stack_a);
		// 		}
		// 		else if (search_and_return_the_smaller_nb_into_a(stack_a) > stack_b->arg)
		// 			push_to_a(stack_b);

		// 		stack_b = stack_b->next;
		// 	}
		// }


// int	search_and_return_the_smaller_nb_into_a(stack *stack_a)
// {
// 	int smaller_nbr;

// 	smaller_nbr = INT_MAX;
// 	while (stack_a != NULL)
// 	{
// 		while (stack_a->arg < smaller_nbr)
// 		{
// 			smaller_nbr = stack_a->arg;
// 			stack_a = ptr_stack_a->next;
// 		}
// 	}
// 	return (smaller_nbr);
// }
