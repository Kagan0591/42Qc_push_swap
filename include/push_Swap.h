/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_Swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:31:09 by tchalifo          #+#    #+#             */
/*   Updated: 2022/02/28 13:31:09 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include "libft.h"

typedef enum
{
	false,
	true
}boolean;

typedef struct	node_dlink
{
	long long int		arg;
	struct node_dlink	*next;
	struct node_dlink	*previous;
}	node_dlink;

typedef struct	d_container
{
	// Some data
	node_dlink	*stack_a;
	node_dlink	*stack_b;
	int			errors_status;
}d_container;

// push_swap_stack_functions_doubly_linked_list_1 functions
node_dlink		*ft_stknew_dlink(long long int nbr);
node_dlink		*ft_stkadd_dlink(node_dlink *p_stk, long long int nbr);
node_dlink		*ft_dllst_addback(node_dlink *p_stk, long long int nbr);
void			ft_stkdelone_dlink(node_dlink *p_stk);
void			ft_stkclear_dlink(node_dlink *p_stk);
// push_swap_stack_functions_doubly_linked_list_2 functions
boolean 		ft_stk_isempty_dlink(node_dlink *p_stk);
int				ft_stksize_dlink(node_dlink *p_stk);
void			ft_print_node_dlink(node_dlink *p_stk);
void			ft_print_stack_dlink(node_dlink *p_stk);
node_dlink		*return_to_top(node_dlink *stack);
// push_swap_stack_functions_doubly_linked_list_3 functions
node_dlink		*clone_a_node(node_dlink *src_stack, node_dlink *dest_stack);
node_dlink		*clone_a_stack(node_dlink *src_stack, node_dlink *dest_stack);
//push_swap.c functions
int				push_args_to_dlist(char *str, d_container *p_data);
node_dlink		*indexing_stack_to_stack(node_dlink *stack_a);
int				bubble_sort_list_indexation(node_dlink *p_dlinklist, node_dlink *p_dlinklist_top);
// push_swap_utils.c functions
long long int	ft_atoll(const char *str);
//push_swap_error.c functions
int				isnumber_spaced(char *str);
int				ft_isint(long long int nb);
#endif
