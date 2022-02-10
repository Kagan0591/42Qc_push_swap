#ifndef TEST_H
#define TEST_H

#include <stdlib.h>
#include "42Qc_libft/libft.h"

typedef enum
{
	false,
	true
}boolean;
typedef struct node_dlink
{
	int	arg;
	struct node_dlink *next;
	struct node_dlink *previous;
}node_dlink;


node_dlink		*ft_stkadd_dlink(node_dlink *p_stk, int nbr);
node_dlink		*ft_stknew_dlink(int nbr);
node_dlink		*ft_stkadd_dlink(node_dlink *p_stk, int nbr);
boolean 		ft_stk_isempty_dlink(node_dlink *p_stk);
int				ft_stksize_dlink(node_dlink *p_stk);
void			ft_print_node_dlink(node_dlink *p_stk);
void			ft_print_stack_dlink(node_dlink *p_stk);
node_dlink		*ft_stkdelone_dlink(node_dlink *p_stk);
node_dlink		*ft_stkclear_dlink(node_dlink *p_stk);
node_dlink		*return_to_top(node_dlink *stack);
node_dlink		*clone_a_node(node_dlink *src_stack, node_dlink *dest_stack);
node_dlink		*clone_a_stack(node_dlink *src_stack, node_dlink *dest_stack);
node_dlink		*indexing_stack_to_stack(node_dlink *stack_a);

#endif