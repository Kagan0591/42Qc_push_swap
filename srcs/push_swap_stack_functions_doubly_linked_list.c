#include "push_swap.h"

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
		p_stk->previous = new_element;
		return (new_element);
	}
	return (NULL);
}

node_dlink	*ft_dllst_addback(node_dlink *p_stk, int nbr)
{
	node_dlink	*new_node;

	if (!p_stk)
		return (ft_stknew_dlink(nbr));
	new_node = malloc(sizeof(node_dlink));
	if (new_node)
	{
		while (p_stk->next != NULL)
			p_stk = p_stk->next;
		new_node->arg = nbr;
		new_node->next = NULL;
		new_node->previous = p_stk;
		p_stk->next = new_node;
		while (p_stk->previous != NULL)
			p_stk = p_stk->previous;
		return (p_stk);
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
	while (p_stk != NULL)
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

void	ft_stkdelone_dlink(node_dlink *p_stk) // --NEW--
{
	if (p_stk)
	{
		p_stk->arg = 0;
		free(p_stk);
	}
}

void	ft_stkclear_dlink(node_dlink *p_stk)
{
	if(p_stk)
	{
		while(p_stk->next)
		{
			p_stk = p_stk->next;
			ft_stkdelone_dlink(p_stk->previous);
		}
		ft_stkdelone_dlink(p_stk);
	}
}

node_dlink	*return_to_top(node_dlink *stack)
{
	while (stack->previous != NULL)
		stack = stack->previous;
	return (stack);
}

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
	ft_stkclear_dlink(start_of_stack);
	ft_stkclear_dlink(original_stack);
	while (stack->previous != NULL)
		stack = stack->previous;
	return (stack);
}
