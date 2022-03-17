/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:31:09 by tchalifo          #+#    #+#             */
/*   Updated: 2022/02/28 13:31:09 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include "libft.h"

typedef enum
{
	false,
	true
}				ft_bool;

typedef struct	node_dlink
{
	long long int		arg;
	int					*arg_binary;
	struct node_dlink	*next;
	struct node_dlink	*previous;
}				node_dlink;

typedef struct	d_container
{
	// Some data
	node_dlink	*stack_a;
	node_dlink	*stack_b;
}				d_container;

//mem.c functions
d_container		*initmem					(void);
d_container		*clearmem					(d_container *p_data);

//push_swap_utils.c functions
long long int	ft_atoll					(const char *str);
//push_swap_error.c functions
int				str_isnumber				(char *str);
int				nbr_isint					(long long int nb);
int				nbr_isequal					(long long int nb1, long long int nb2);
int				lst_nodevalues_isunique		(node_dlink *lst);
int				arg_isunique_doublyll		(char *argument, node_dlink *stack);
//push_swap_stack_functions_doubly_linked_list_1 functions
node_dlink		*ft_stknew_dlink			(long long int nbr, int *arg_binary);
node_dlink		*ft_stkadd_dlink			(node_dlink *p_stk, long long int nbr, int *arg_binary);
node_dlink		*ft_dllst_addback			(node_dlink *p_stk, long long int nbr, int *arg_binary);
void			ft_stkdelone_dlink			(node_dlink *p_stk);
void			ft_stkclear_dlink			(node_dlink *p_stk);
//push_swap_stack_functions_doubly_linked_list_2 functions
void			secure_del					(node_dlink *p_stk);
ft_bool 		ft_stk_isempty_dlink		(node_dlink *p_stk);
int				ft_stksize_dlink			(node_dlink *p_stk);
void			ft_print_node_dlink			(node_dlink *p_stk);
void			ft_print_stack_dlink		(node_dlink *p_stk);
//push_swap_stack_functions_doubly_linked_list_3 functions
node_dlink		*return_to_top				(node_dlink *p_stk);
node_dlink		*clone_a_node				(node_dlink *src_stack, node_dlink *dest_stack);
node_dlink		*clone_a_stack				(node_dlink *src_stack, node_dlink *dest_stack);
//push_swap_sort_function.c functions
node_dlink		*swap_a						(node_dlink *p_stk);
node_dlink		*swap_b						(node_dlink*p_stk);
void			push_to_a					(d_container *p_data);
void			push_to_b					(d_container *p_data);
node_dlink		*rotate_a					(node_dlink *p_stk);
node_dlink		*rotate_b					(node_dlink *p_stk);
node_dlink		*reverse_rotate_a			(node_dlink *p_stk);
node_dlink		*reverse_rotate_b			(node_dlink *p_stk);
void			reverse_rotate_ab			(d_container *p_data);
void			rotate_ab					(d_container *p_data);
//micro_sort.c functions
node_dlink		*micro_sort					(node_dlink *stack);
//mini_sort.c functions
node_dlink		*mini_sort					(d_container *p_data);
//big_sort.c functions
node_dlink		*big_sort					(d_container *p_data);
#endif
