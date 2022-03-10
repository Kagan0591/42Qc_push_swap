#include "push_swap.h"

node_dlink	*swap_a(node_dlink *p_stk)
{
	node_dlink	*tmp;

	ft_putstr("sa\n");
	if (ft_stksize_dlink(p_stk) > 1)
	{
		tmp = p_stk;
		p_stk = p_stk->next;
		tmp->next = p_stk->next;
		p_stk->next = tmp;
	}
	return (p_stk);
}

node_dlink	*swap_b(node_dlink *p_stk)
{
	node_dlink	*tmp;

	ft_putstr("sb\n");
	if (ft_stksize_dlink(p_stk) > 1)
	{
		tmp = p_stk;
		p_stk = p_stk->next;
		tmp->next = p_stk->next;
		p_stk->next = tmp;
	}
	return (p_stk);
}


// void	push_to_a(d_container *p_data) // NEED TO BE LIKE PUSH B
// {
// 	node_dlink	*tmp_b;

// 	ft_putstr("pa\n");
// 	if (p_data->stack_b == NULL)
// 		exit(0);
// 	if (p_data->stack_a != NULL)
// 	{
// 		tmp_b = p_data->stack_b->next;
// 		tmp_b->previous = NULL;
// 		p_data->stack_b->next = p_data->stack_a;
// 		p_data->stack_a->previous = p_data->stack_b;
// 	}
// }

void	push_to_a(d_container *p_data) //OKK!!
{
	node_dlink	*tmp_b; //node isolé

	ft_putstr("pa\n");
	if (p_data->stack_b == NULL)
		exit(0);
	else
	{
		tmp_b = p_data->stack_b; //pointe le node du sommet de la pile B
		p_data->stack_b = p_data->stack_b->next; //descend de 1 dans la pile B
		if (p_data->stack_b != NULL)
			p_data->stack_b->previous = NULL; //le pointeur de la pile B pointe vers NULL
		if (p_data->stack_a != NULL)
		{
			p_data->stack_a->previous = tmp_b; // place le node B sur la pile A si A n est pas vide
			tmp_b->next = p_data->stack_a;
			while (p_data->stack_a->previous != NULL)
				p_data->stack_a = p_data->stack_a->previous;
		}
		else
		{
			tmp_b->next = NULL;
			p_data->stack_a = tmp_b;
		}
	}
}

void	push_to_b(d_container *p_data) //OKK!!
{
	node_dlink	*tmp_a; //node isolé

	ft_putstr("pb\n");
	if (p_data->stack_a == NULL)
		exit(0);
	else
	{
		tmp_a = p_data->stack_a; //pointe le node du sommet de la pile A
		p_data->stack_a = p_data->stack_a->next; //descend de 1 dans la pile A
		if (p_data->stack_a != NULL)
			p_data->stack_a->previous = NULL; //le pointeur de la pile A pointe vers NULL
		if (p_data->stack_b != NULL)
		{
			p_data->stack_b->previous = tmp_a; // place le node A sur la pile B
			tmp_a->next = p_data->stack_b;
			while (p_data->stack_b->previous != NULL)
				p_data->stack_b = p_data->stack_b->previous;
		}
		else
		{
			tmp_a->next = NULL;
			p_data->stack_b = tmp_a;
		}
	}
}

// old push
// void	push_to_a(d_container *p_data)
// {
// 	ft_putstr("pa\n");
// 	if (p_data->stack_b == NULL)
// 		exit(0);
// 	if (p_data->stack_a != NULL)
// 		p_data->stack_a = ft_stkadd_dlink(p_data->stack_a, p_data->stack_b->arg, p_data->stack_b->arg_binary);
// 	else
// 		p_data->stack_a = ft_stknew_dlink(p_data->stack_b->arg, p_data->stack_b->arg_binary);
// 	p_data->stack_b = p_data->stack_b->next;
// 	if (p_data->stack_b != NULL)
// 	{
// 		ft_stkdelone_dlink(p_data->stack_b->previous);
// 		p_data->stack_b->previous = NULL;
// 	}
// }

// void	push_to_b(d_container *p_data)
// {
// 	ft_putstr("pb\n");
// 	if (p_data->stack_a == NULL)
// 		exit(0);
// 	if (p_data->stack_b != NULL)
// 		(p_data->stack_b) = ft_stkadd_dlink(p_data->stack_b, p_data->stack_a->arg, p_data->stack_a->arg_binary);
// 	else
// 		p_data->stack_b = ft_stknew_dlink(p_data->stack_a->arg, p_data->stack_a->arg_binary);
// 	p_data->stack_a = p_data->stack_a->next;
// 	if (p_data->stack_a != NULL)
// 	{
// 		ft_stkdelone_dlink(p_data->stack_a->previous);
// 		p_data->stack_a->previous = NULL;
// 	}
// }

//OKK !!
node_dlink	*rotate_a(node_dlink *p_stk) // Put the top node to bottom
{
	node_dlink	*node_tmp; //node isolé a placer en bas

	ft_putstr("ra\n");
	if (ft_stksize_dlink(p_stk) > 1)
	{
		node_tmp = p_stk; //Keep the addr of first node
		p_stk = p_stk->next; //Go to the next node
		p_stk->previous = NULL; //Modifie the pointeur of this node (new top)
		while (p_stk->next != NULL) //Go to the last node
			p_stk = p_stk->next;
		p_stk->next = node_tmp; //next pointeur of the last node point to the old first node
		node_tmp->previous = p_stk; //Previous pointeur of the old first node point to last node
		node_tmp->next = NULL; //Next pointer of old new node point to NULL
		return (return_to_top(p_stk));
	}
	return (p_stk);
}



// OLD
// node_dlink	*rotate_a(node_dlink *p_stk) // Put the top node to bottom
// {
// 	node_dlink	*new_top;

// 	ft_putstr("ra\n");
// 	if (ft_stksize_dlink(p_stk) > 1)
// 	{
// 		while (p_stk->next != NULL)
// 			p_stk = p_stk->next;
// 		new_top = p_stk;
// 		p_stk = p_stk->previous;
// 		p_stk->next = NULL;
// 		while (p_stk->previous != NULL)
// 			p_stk = p_stk->previous;
// 		new_top->next = p_stk;
// 		new_top->previous = NULL;
// 		new_top->next->previous = new_top;

// 		return (new_top);
// 	}
// 	else
// 		return (p_stk);
// }


// LIKE REVERSE ROTATE PONTER EDITION
node_dlink	*rotate_b(node_dlink *p_stk) // Put the top node to bottom
{
	node_dlink	*tmp;
	node_dlink	*new_top;

	ft_putstr("rb\n");
	if (ft_stksize_dlink(p_stk) > 1)
	{
		new_top = p_stk->next;
		tmp = p_stk;
		while (p_stk->next != NULL)
			p_stk = p_stk->next;
		tmp->next = NULL;
		tmp->previous = p_stk;
		p_stk->next = tmp;

		return (new_top);
	}
	else
		return (p_stk);
}

node_dlink	*reverse_rotate_a(node_dlink *p_stk) // Put the last node to the top
{
	node_dlink		*new_top;

	new_top = NULL;

	ft_putstr("rra\n");
	if (ft_stksize_dlink(p_stk) > 1)
	{
		while (p_stk->next != NULL)
			p_stk = p_stk->next;
		new_top = clone_a_node(p_stk, new_top);
		p_stk = p_stk->previous;
		ft_stkdelone_dlink(p_stk->next);
		p_stk->next = NULL;
		while (p_stk->previous != NULL)
			p_stk = p_stk->previous;
		p_stk->previous = new_top;
		new_top->next = p_stk;
		return (new_top);
	}
	else
		return (p_stk);
}

node_dlink	*reverse_rotate_b(node_dlink *p_stk) // Put the last node to the top
{
	node_dlink		*new_top;

	new_top = NULL;
	ft_putstr("rrb\n");
	if (ft_stksize_dlink(p_stk) > 1)
	{
		while (p_stk->next != NULL)
			p_stk = p_stk->next;
		new_top = clone_a_node(p_stk, new_top);
		p_stk = p_stk->previous;
		ft_stkdelone_dlink(p_stk->next);
		p_stk->next = NULL;
		while (p_stk->previous != NULL)
			p_stk = p_stk->previous;
		p_stk->previous = new_top;
		new_top->previous = NULL;
		new_top->next = p_stk;
		return (new_top);
	}
	else
		return (p_stk);
}
