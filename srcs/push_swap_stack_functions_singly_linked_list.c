#include "push_swap.h"

node	*ft_stknew(int nbr)
{
	node	*new_element;

	new_element = malloc(sizeof(node));
	if (new_element)
	{
		new_element->arg = nbr;
		new_element->next = NULL;
	}
	return (new_element);
}

node	*ft_stkadd(node *p_stk, int nbr)
{
	node	*new_element;
	if (!p_stk)
		return (ft_stknew(nbr));
	new_element = malloc(sizeof(node));
	if (new_element)
	{
		new_element->arg = nbr;
		new_element->next = p_stk;
		return (new_element);
	}
	return (NULL);
}

boolean 	ft_stk_isempty(node *p_stk)
{
	if(p_stk == NULL)
		return (true);
	return (false);
}

int	ft_stksize(node *p_stk)
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

void	ft_print_node(node *p_stk)
{
	if (p_stk != NULL)
	{
		ft_putnbr(p_stk->arg);
		ft_print_stack(p_stk->next);
	}
}

void	ft_print_stack(node *p_stk)
{
	while (p_stk->next != NULL)
	{
		ft_print_node(p_stk);
		p_stk = p_stk->next;
	}
}

node	*ft_stkdelone(node *p_stk)
{
	node	*tmp;
	if (p_stk)
	{
		tmp = p_stk->next;
		free(p_stk);
		return (tmp);
	}
	return (NULL);
}

node	*ft_stkclear(node *p_stk)
{
	node	*tmp;

	if(p_stk)
	{
		tmp = p_stk;
		while(tmp)
			tmp = ft_stkdelone(tmp);
		return (tmp);
	}
	return (p_stk);
}

int	*indexing_stack_to_tab(node *stack_a)
{
	int		count;
	node	*start_of_stack_a;
	node	*stack_a_tmp;
	int		*indexed_tab;
	int		i;

	indexed_tab = malloc(sizeof(int) * ft_stksize(stack_a));
	i = 0;
	start_of_stack_a = stack_a;
	while (stack_a != NULL)
	{
		count = 0;
		stack_a_tmp = start_of_stack_a;
		while (stack_a_tmp != NULL)
		{
			if (stack_a->arg > stack_a_tmp->arg)
				count++;
			stack_a_tmp = stack_a_tmp->next;
		}
		stack_a = stack_a->next;
		indexed_tab[i] = count;
		i++;
	}
	return (indexed_tab);
}
