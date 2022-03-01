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

typedef struct	node_dlink
{
	int					arg;
	struct node_dlink	*next;
	struct node_dlink	*previous;
}						node_dlink;

typedef struct	d_container
{
	// Some data
	node_dlink	*stack_a;
	node_dlink	*stack_b;
	int			errors_status;
}d_container;

int				check_for_error(int argc, char **argv);
node_dlink		*push_argv_to_stk(int argc, char **argv);
void			*push_str_to_dlist(char *str, d_container *p_data);
void			choosing_the_algo(d_container *p_data);
boolean			ft_isint(char *str);
boolean			ft_isnumbers(char *str);
char			ft_findchar_dlist(node_dlink *d_list, char c);


// Doubly linked list stack functions
node_dlink		*ft_stknew_dlink(int nbr);
node_dlink		*ft_stkadd_dlink(node_dlink *p_stk, int nbr);
node_dlink		*ft_dllst_addback(node_dlink *p_stk, int nbr);
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

// Utils functions
long long int	ft_atoll(const char *str);
int				decimal_to_base(int base, int nb);

// Sort moves functions
node_dlink		*swap_a(node_dlink *p_stk);
node_dlink		*swap_b(node_dlink*p_stk);
void			push_to_a(d_container *p_data);
void			push_to_b(d_container *p_data);
node_dlink		*rotate_a(node_dlink *p_stk);
node_dlink		*rotate_b(node_dlink *p_stk);
node_dlink		*reverse_rotate_a(node_dlink *p_stk);
node_dlink		*reverse_rotate_b(node_dlink *p_stk);

// Sort algo functions
node_dlink		*micro_sort(node_dlink *stack);
node_dlink		*mini_sort(d_container *p_data);

#endif
