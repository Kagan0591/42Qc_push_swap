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

void	ft_stkdelone_dlink(node_dlink *p_stk) // --NEW--
{
	if (p_stk != NULL)
	{
		p_stk->arg = 0;
		free(p_stk);
	}
}

void	ft_stkclear_dlink(node_dlink *p_stk)
{
	if(p_stk != NULL)
	{
		while(p_stk->next)
		{
			p_stk = p_stk->next;
			ft_stkdelone_dlink(p_stk->previous);
		}
		ft_stkdelone_dlink(p_stk);
	}
}
