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
	int					arg;
	struct node			*next;
}node;

typedef struct node_dlink
{
	int					arg;
	struct node_dlink	*next;
	struct node_dlink	*previous;
}node_dlink;

int				check_for_error(int argc, char **argv);
node_dlink		*push_argv_to_stk(int argc, char **argv);
boolean			checkif_isdigit(char **argv);
boolean			checkif_isint(char **argv);
boolean			checkif_repeated_number(char **argv);
boolean			checkif_is_sort(char **argv);

// Algo functions
node_dlink		*swap_a(node_dlink *p_stk);
node_dlink		*swap_b(node_dlink*p_stk);
void			push_to_a(node_dlink **origin, node_dlink **dest);
void			push_to_b(node_dlink **origin, node_dlink **dest);
node_dlink		*rotate_a(node_dlink *p_stk);
node_dlink		*rotate_b(node_dlink *p_stk);
node_dlink		*reverse_rotate_a(node_dlink *p_stk);
node_dlink		*reverse_rotate_b(node_dlink *p_stk);

// Algo
node_dlink		*micro_sort(node_dlink *stack);
node_dlink		*mini_sort(node_dlink *stack_a);




// Algo radix sort
int				*counting_sort_0to9(node *unsort_nbr);

// Algo quicksort
void			quicksort(node *stack_a);
node			*finding_pivot(node *pt_to_stack_a);
void			swap_the_smaller_and_bigger(node *stack_a, node *pivot);
node			*finding_bigger_than_pivot(node *pt_to_stack_a, node *pivot);
node			*finding_smaller_than_pivot(node *pt_to_stack_a, node *pivot);

// Algo devide and conquer 1
void			sort_algo(node **ptr_stack_a, node **ptr_stk_b);
void			split_recursive(node **stack_a, node **stack_b);
void			split_stack(node **ptr_stack_a, node **ptr_stack_b);
int				search_and_return_the_smaller_nb_into_a(node *stack_a);

// Stack functions
node			*ft_stknew(int nbr);
node			*ft_stkadd(node *p_stk, int nbr);
boolean			ft_stk_isempty(node *p_stk);
int				ft_stksize(node *p_stk);
void			ft_print_node(node *p_stk);
void			ft_print_stack(node *p_stk);
node			*ft_stkdelone(node *p_stk);
node			*ft_stkclear(node *p_stk);
int				*indexing_stack_to_tab(node *stack_a);

// Doubly linked list stack functions
node_dlink		*ft_stknew_dlink(int nbr);
node_dlink		*ft_stkadd_dlink(node_dlink *p_stk, int nbr);
boolean 		ft_stk_isempty_dlink(node_dlink *p_stk);
int				ft_stksize_dlink(node_dlink *p_stk);
void			ft_print_node_dlink(node_dlink *p_stk);
void			ft_print_stack_dlink(node_dlink *p_stk);
void			ft_stkdelone_dlink(node_dlink *p_stk);
void			ft_stkclear_dlink(node_dlink *p_stk);
node_dlink		*return_to_top(node_dlink *stack);
node_dlink		*clone_a_node(node_dlink *src_stack, node_dlink *dest_stack);
node_dlink		*clone_a_stack(node_dlink *src_stack, node_dlink *dest_stack);
node_dlink		*indexing_stack_to_stack(node_dlink *stack_a);


// Utils
long long int	ft_atoll(const char *str);
int				decimal_to_base(int base, int nb);

#endif
