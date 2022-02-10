#include "push_swap.h"
#include <stdio.h>

node_dlink	*ft_stknew_dlink(int nbr)
{
	node_dlink	*new_element;

	new_element = malloc(sizeof(node_dlink));
	if (new_element)
	{
		new_element->arg = nbr;
		new_element->next = NULL;
		new_element->previous = NULL;
	}
	return (new_element);
}

node_dlink	*ft_stkadd_dlink(node_dlink *p_stk, int nbr)
{
	node_dlink	*new_element;
	if (!p_stk)
		return (ft_stknew_dlink(nbr));
	new_element = malloc(sizeof(node_dlink));
	if (new_element)
	{
		new_element->arg = nbr;
		new_element->next = p_stk;
		new_element->previous = NULL;
		new_element->next->previous = new_element;
		return (new_element);
	}
	return (NULL);
}

node_dlink	*ft_dllst_addback(node_dlink *p_stk, int nbr)
{
	node_dlink	*new_element;
	if (!p_stk)
		return (ft_stknew_dlink(nbr));
	new_element = malloc(sizeof(node_dlink));
	if (new_element)
	{
		new_element->arg = nbr;
		new_element->next = NULL;
		new_element->previous = p_stk;
		return (new_element);
	}
	return (NULL);
}

boolean 	ft_stk_isempty_dlink(node_dlink *p_stk)
{
	if(p_stk == NULL)
		return (true);
	return (false);
}

int	ft_stksize_dlink(node_dlink *p_stk)
{
	int	count;

	count = 0;
	while (p_stk)
	{
		count++;
		p_stk = p_stk->next;
	}
	return (count);
}

void	ft_print_node_dlink(node_dlink *p_stk)
{
	if (p_stk != NULL)
		ft_putnbr(p_stk->arg);
}

void	ft_print_stack_dlink(node_dlink *p_stk)
{
	while (p_stk != NULL)
	{
		ft_print_node_dlink(p_stk);
		p_stk = p_stk->next;
	}
}

node_dlink	*ft_stkdelone_dlink(node_dlink *p_stk)
{
	node_dlink	*tmp;
	if (p_stk != NULL)
	{
		ft_putnbr(p_stk->arg);
		tmp = p_stk->next;
		tmp->previous = NULL;
		free(p_stk);
		return (tmp);
	}
	return (NULL);
}

node_dlink	*ft_stkclear_dlink(node_dlink *p_stk)
{
	node_dlink	*tmp;

	if(p_stk)
	{
		tmp = p_stk;
		while(tmp)
			tmp = ft_stkdelone_dlink(tmp);
		return (tmp);
	}
	return (p_stk);
}

node_dlink	*return_to_top(node_dlink *stack)
{
	while (stack->previous != NULL)
		stack = stack->previous;
	return (stack);
}

node_dlink	*clone_a_node(node_dlink *src_stack, node_dlink *dest_stack)
{
	if (!dest_stack)
		dest_stack = ft_stknew_dlink(src_stack->arg);
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
	while (src_stack != NULL)
	{
		dest_stack = clone_a_node(src_stack, dest_stack);
		src_stack = src_stack->previous;
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

// Indexing via list doublement chainé
node_dlink	*indexing_stack_to_stack(node_dlink *stack)
{
	int			index;
	node_dlink	*start_of_stack;
	node_dlink	*original_stack;
	node_dlink	*stack_tmp;

	start_of_stack = NULL;
	original_stack = NULL;
	start_of_stack = clone_a_stack(stack, start_of_stack);
	original_stack = clone_a_stack(stack, original_stack);
	while (original_stack != NULL)
	{
		index = 0;
		stack_tmp = start_of_stack;
		while (stack_tmp != NULL)
		{
			if (original_stack->arg > stack_tmp->arg)
				index++;
			stack_tmp = stack_tmp->next;
		}
		stack->arg = index;
		if (original_stack->next != NULL)
			stack = stack->next;
		original_stack = original_stack->next;
	}
	free (start_of_stack);
	free (original_stack);
	while (stack->previous != NULL)
		stack = stack->previous;
	return (stack);
}

