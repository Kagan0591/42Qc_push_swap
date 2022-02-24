#include "push_swap.h"

node_dlink	*clone_a_node(node_dlink *src_stack, node_dlink *dest_stack)
{
	if (!src_stack)
		return (NULL);
	else if (!dest_stack)
		return (ft_stknew_dlink(src_stack->arg));
	else if ((dest_stack->next == NULL) && (dest_stack->previous != NULL)) // Pour une raison que j ignore, sa passe pas
		dest_stack = ft_dllst_addback(src_stack, src_stack->arg);
	else
		dest_stack = ft_stkadd_dlink(dest_stack, src_stack->arg);
	return (dest_stack);
}

node_dlink	*clone_a_stack(node_dlink *src_stack, node_dlink *dest_stack)
{
	while (src_stack->next != NULL)
	{
		src_stack = src_stack->next;
	}
	dest_stack = clone_a_node(src_stack, dest_stack);
	while (src_stack->previous != NULL)
	{
		src_stack = src_stack->previous;
		dest_stack = clone_a_node(src_stack, dest_stack);
	}
	return (dest_stack);
}

// node_dlink	reverse_data_links(node_dlink stack)
// {
// 	node_dlink	top_node_next_pt;
// 	node_dlink	top_node_previous_pt;
// 	node_dlink	top_node_pt;
// 	node_dlink	bottom_node_previous_pt;
// 	node_dlink	bottom_node_next_pt;


// 	top_node_next_pt = stack->next;
// 	top_node_pt = stack;
// 	while (stack->next != NULL)
// 		stack = stack->next;
// 	bottom_node_previous_pt = stack->previous;
// 	stack->previous = NULL;
// 	stack->next = top_node_next_pt;
// 	top_node_pt->next = NULL;
// 	top_node_pt->previous = bottom_node_previous_pt;
// 	while (bottom_node_previous_pt->previous)


// }
