#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <math.h>
#include "libft.h"

typedef enum
{
	false,
	true
}boolean;

typedef struct node
{
	int				arg;
	struct node	*next;
}node;

// Prog functions
int		check_for_error(int argc, char **argv);
boolean	checkif_isdigit(char **argv);
boolean	checkif_isint(char **argv);
boolean	checkif_repeated_number(char **argv);
node	*push_argv_to_stk(int argc, char **argv);
int		*indexing_stack_to_tab(node *stack_a);
node	*indexing_stack_to_stack(node *stack_a);

// Algo functions
node	*swap_stkvalue_a(node *p_stk);
node	*swap_stkvalue_b(node *p_stk);
void	push_to_a(node **origin, node **dest);
void	push_to_b(node **origin, node **dest);
node	*rotate_a(node *p_stk);
node	*rotate_b(node *p_stk);
node	*reverse_rotate_a(node *p_stk);
node	*reverse_rotate_b(node *p_stk);

// Algo radix sort
int	*counting_sort_0to9(node *unsort_nbr);

// Algo quicksort
void	quicksort(node *stack_a);
node	*finding_pivot(node *pt_to_stack_a);
void	swap_the_smaller_and_bigger(node *stack_a, node *pivot);
node	*finding_bigger_than_pivot(node *pt_to_stack_a, node *pivot);
node	*finding_smaller_than_pivot(node *pt_to_stack_a, node *pivot);

// Algo devide and conquer 1
void	sort_algo(node **ptr_stack_a, node **ptr_stk_b);
void	split_recursive(node **stack_a, node **stack_b);
void	split_stack(node **ptr_stack_a, node **ptr_stack_b);
int		search_and_return_the_smaller_nb_into_a(node *stack_a);

// Stack functions
node			*ft_stknew(int nbr);
node			*ft_stkadd(node *p_stk, int nbr);
boolean			ft_stk_isempty(node *p_stk);
int			ft_stksize(node *p_stk);
void			ft_print_stack(node *p_stk);
node			*ft_stkdelone(node *p_stk);
node			*ft_stkclear(node *p_stk);

// Utils
long long int	ft_atoll(const char *str);
int	decimal_to_base(int base, int nb);

#endif
