/* Maybe much not so junk, it is !
*/
/* Function available in the repo
*/
// Numbers
boolean			checkif_repeated_number(char **argv);
int				*indexing_stack_to_tab(slinklst *stack_a);
int				decimal_to_base(int nb, int base);
long long int	average(node_dlink *stack);


//Stack in singly linked list
slinklst		*ft_stknew(int nbr);
slinklst		*ft_stkadd(slinklst *p_stack, int nbr);
boolean 		ft_stk_isempty(slinklst *p_stack);
int				ft_stksize(slinklst *p_stack);
void			ft_print_node(slinklst *p_stack);
void			ft_print_stack(slinklst *p_stack);
void			secure_del(slinklst *p_stack);
slinklst		*ft_stkdelone(slinklst *p_stack);
slinklst		*ft_stkclear(slinklst *p_stack);

//Stack in doubly linked list
dlinklst	*clone_a_node(dlinklst *src_stack, dlinklst *dest_stack);
dlinklst	*clone_a_stack(dlinklst *src_stack, dlinklst *dest_stack);

/* From my project push_swap at 42
*/
boolean	checkif_repeated_number(char **tab_of_tab)
{// verify if a number is repeated into the entire tab of int tab.
	int	i;
	int	j;

	i = 1;
	j = 2;

	while (argv[i])
	{
		while (argv[j])
		{
			if (ft_atoi(argv [i]) == ft_atoi(argv[j]))
				return (true);
			j++;
		}
		i++;
		j = (i + 1);
	}
	return (false);
}

int	*indexing_stack_to_tab(slinklst *stack_a)
{// Indexing a stack in singly linked list into an int tab. indexing zero to ...
	int			count;
	slinklst	*start_of_stack_a;
	slinklst	*stack_a_tmp;
	int			*indexed_tab;
	int			i;

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

int	decimal_to_base(int nb, int base)
{// An old decimal to multiples bases, using <math.h>
	int	num;
	int	quotient;
	int	remainder;
	int	i;

	num = 0;
	quotient = nb;
	remainder = 0;
	i = 0;

	while (quotient != 0)
	{
		remainder = (quotient % base);
		quotient = (quotient / base);
		num = ((remainder * pow(10, i)) + num);
		i++;
	}
	return (num);
}

int	str_isnbr(char *str)
{//Verify if the strings have only numeric character into it. 1yes 0no
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] == ' ') // Pour gere une string de nombres
			i++;
		if (ft_atoll(str[i]) >= 0 && ft_atoll(str[i]) <= 9)
			return (0);
		i++;
	}
	return (1);
}

long long int	average(node_dlink *stack)
{//Find the average of an argument from a doubly linked list
	int		sum_of_args;
	int		size_of_stack;

	sum_of_args = 0;
	size_of_stack = ft_stksize_dlink(stack);
	while (stack != NULL)
	{
		sum_of_args = sum_of_args + stack->arg;
		stack = stack->next;
	}
	return ((float)sum_of_args / size_of_stack + 0.5f); //j aurais besoin d utiliser des float pour considerer les virgules
}

/* Singly linked list functions
*/
typedef struct		slinklst
{
	int				int_nbr;
	int				*int_nbrs_tab
	struct slinklst	*next;
}slinklst;

slinklst	*ft_lstnew(int nbr, int *nbr_tab)
{
	slinklst	*new_node;
	int			i;

	new_node = malloc(sizeof(slinklst));
	if (new_node)
	{
		//////--Variable assignement---------->>>>
		new_node->int_nbr = nbr;
		new_node->int_nbrs_tab = malloc(sizeof(int) * 10);
		if (new_node->int_nbrs_tab)
		{
			i = 0;
			while (i > 0)
			{
				new_node->int_nbrs_tab[i] = nbr_tab[i];
				i--;
			}
		}
		//////--End of virable assignement---->>>>
		new_node->next = NULL;
		return (new_node);
	}
	return (NULL);
}

slinklst	*ft_lstadd(slinklst *p_slist, int nbr, int *nbr_tab)
{
	slinklst	*new_node;
	int			i;

	if (!p_slist)
		return (ft_lstnew(nbr, nbr_tab));
	new_node = malloc(sizeof(slinklst));
	if (new_node)
	{
		//////--Variable assignement---------->>>>
		new_node->int_nbr = nbr;
		new_node->int_nbrs_tab = malloc(sizeof(int) * 10);
		if (new_node->int_nbrs_tab)
		{
			i = 0;
			while (i > 0)
			{
				new_node->int_nbrs_tab[i] = nbr_tab[i];
				i--;
			}
		}
		//////--End of virable assignement---->>>>
		new_node->next = p_slist;
		return (new_node);
	}
	return (NULL);
}

boolean 	ft_lstisempty(slinklst *p_slist)
{
	if(p_slist == NULL)
		return (true);
	return (false);
}

int	ft_lstsize(slinklst *p_slist)
{
	int	count;

	count = 0;
	while (p_slist)
	{
		count++;
		p_slist = p_slist->next;
	}
	return (count);
}

void	ft_print_node(slinklst *p_slist)
{
	if (p_slist != NULL)
	{
		ft_putstr("\nArgument en valeur décimal = ");
		ft_putnbr(p_slist->nbr);
		ft_putstr("\nArgument en valeur binaire = ");
		i = 9
		while (i > 0)
		{
			ft_putnbr(p_slist->int_nbrs_tab[i]);
			ft_putstr("\n");
			i--;
		}
	}
}

void	ft_printlst(slinklst *p_slist)
{
	while (p_slist->next != NULL)
	{
		ft_print_node(p_slist);
		p_slist = p_slist->next;
	}
}

void	secure_del(slinklst *p_slist)
{
	//////--Variables to reset to zero---------->>>>
	// int		i;

	// p_stk->arg = 0;
	// i = 9;
	// while (i >= 0)
	// {
	// p_stk->int_nbrs_tab[i] = 0;
	// i--;
	// }
	//////--End of Variables reset-------------->>>>
}

slinklst	*ft_lstdelone(slinklst *p_slist)
{
	slinklst	*new_top;

	if (p_slist)
	{
		new_top = p_slist->next;
		secure_del(p_slist);
		free(p_slist);
		return (new_top);
	}
	return (NULL);
}

slinklst	*ft_lstclear(slinklst *p_slist)
{
	if(p_slist)
	{
		while(p_slist)
			p_slist = ft_lstdelone(p_slist);
		return (p_slist);
	}
	return (p_slist);
}

/* Stack functions doubly linked list
*/
typedef struct		dlinklst
{
	int				int_nbr;
	int				*int_nbrs_tab;
	struct dlinklst	*next;
	struct dlinklst *previous;
}dlinklst;

dlinklst	*ft_dlst_new(long long int nbr, int *nbr_tab)
{
	dlinklst	*new_node;
	int			i;

	new_node = malloc(sizeof(dlinklst));
	if (new_node)
	{
		//////--Variable assignement---------->>>>
		new_node->int_nbr = nbr;
		new_node->int_nbrs_tab = malloc(sizeof(int) * 10);
		if (new_node->int_nbrs_tab)
		{
			i = 0;
			while (i > 0)
			{
				new_node->int_nbrs_tab[i] = nbr_tab[i];
				i--;
			}
		}
		//////--End of virable assignement---->>>>
		new_node->next = NULL;
		new_node->previous = NULL;
	}
	return (new_node);
}

dlinklst	*ft_dlst_addfront(dlinklst *p_dlist, long long int nbr, int *nbr_tab)
{
	dlinklst	*new_node;
	int			i;

	if (!p_dlist)
		return (ft_dlst_new(nbr, nbr_tab));
	new_node = malloc(sizeof(dlinklst));
	if (new_node)
	{
		//////--Variable assignement---------->>>>
		new_node->int_nbr = nbr;
		new_node->int_nbrs_tab = malloc(sizeof(int) * 10);
		if (new_node->int_nbrs_tab)
		{
			i = 0;
			while (i > 0)
			{
				new_node->int_nbrs_tab[i] = nbr_tab[i];
				i--;
			}
		}
		//////--End of virable assignement---->>>>
		new_node->next = p_dlist;
		new_node->previous = NULL;
		p_dlist->previous = new_node;
		return (new_node);
	}
	return (NULL);
}

dlinklst	*ft_dlst_addback(dlinklst *p_dlist, long long int nbr, int *nbr_tab)
{
	dlinklst	*new_node;
	int			i;

	if (!p_dlist)
		return (ft_dlst_new(nbr, nbr_tab));
	new_node = malloc(sizeof(dlinklst));
	if (new_node)
	{
		while (p_dlist->next != NULL)
			p_dlist = p_dlist->next;
		//////--Variable assignement---------->>>>
		new_node->int_nbr = nbr;
		new_node->int_nbrs_tab = malloc(sizeof(int) * 10);
		if (new_node->int_nbrs_tab)
		{
			i = 0;
			while (i > 0)
			{
				new_node->int_nbrs_tab[i] = nbr_tab[i];
				i--;
			}
		}
		//////--End of virable assignement---->>>>
		new_node->next = NULL;
		new_node->previous = p_dlist;
		p_dlist->next = new_node;
		while (p_dlist->previous != NULL)
			p_dlist = p_dlist->previous;
		return (p_dlist);
	}
	return (NULL);
}

void	ft_lstdelone(dlinklst *p_dlist)
{
	if (p_dlist)
	{
		secure_del(p_dlist);
		free (p_dlist->int_nbrs_tab);
		free(p_dlist);
	}
}

void	ft_stkclear_dlink(dlinklst *p_dlist)
{
	dlinklst	*tmp;

	tmp = NULL;
	while (p_dlist != NULL)
	{
		tmp = p_dlist->next;
		ft_lstdelone(p_dlist);
		p_dlist = tmp;
	}
}

void	secure_del(dlinklst *p_dlist)
{
	//////--Variables to reset to zero---------->>>>
	// int		i;

	// p_dlist->arg = 0;
	// i = 9;
	// while (i >= 0)
	// {
	// p_dlist->int_nbrs_tab[i] = 0;
	// i--;
	// }
	//////--End of Variables reset-------------->>>>

}

ft_bool	ft_dlstisempty(dlinklst *p_dlist)
{
	if (p_dlist == NULL)
		return (true);
	return (false);
}

int	ft_dlstsize(dlinklst *p_dlist)
{
	int	count;

	count = 0;
	while (p_dlist != NULL)
	{
		count++;
		p_dlist = p_dlist->next;
	}
	return (count);
}

void	ft_dlstprint_singlenode(dlinklst *p_dlist)
{
	int		i;

	if (p_dlist != NULL)
	{
		ft_putstr("\nArgument en valeur décimal = ");
		ft_putnbr(p_dlist->nbr);
		ft_putstr("\nArgument en valeur binaire = ");
		i = 9
		while (i > 0)
		{
			ft_putnbr(p_dlist->int_nbrs_tab[i]);
			ft_putstr("\n");
			i--;
		}
	}
}

void	ft_dlstprint(dlinklst *p_dlist)
{
	while (p_dlist != NULL)
	{
		ft_dlstprint_singlenode(p_dlist);
		p_dlist = p_dlist->next;
	}
}

dlinklst	*return_to_top(dlinklst *p_dlist)
{
	while (p_dlist->previous != NULL)
		p_dlist = p_dlist->previous;
	return (p_dlist);
}

dlinklst	*clone_a_dlst_node(dlinklst *p_src_dlist, dlinklst *p_dest_dlist)
{
	if (!p_src_dlist)
		return (NULL);
	else if (!p_dest_dlist)
		return (ft_stknew_dlink(p_src_dlist->int_nbr, p_src_dlist->int_nbr_tab));
	else if ((p_dest_dlist->next == NULL) && (p_dest_dlist->previous != NULL))
		p_dest_dlist = ft_dllst_addback(p_dest_dlist, p_src_dlist->int_nbr, p_src_dlist->int_nbr_tab);
	else
		p_dest_dlist = ft_stkadd_dlink(p_dest_dlist, p_src_dlist->int_nbr, p_src_dlist->int_nbr_tab);
	return (p_dest_dlist);
}

dlinklst	*clone_a_dlst(dlinklst *p_src_dlist, dlinklst *p_dest_dlist)
{
	while (p_src_dlist->next != NULL)
	{
		p_src_dlist = p_src_dlist->next;
	}
	p_dest_dlist = clone_a_dlst_node(p_src_dlist, p_dest_dlist);
	while (p_src_dlist->previous != NULL)
	{
		p_src_dlist = p_src_dlist->previous;
		p_dest_dlist = clone_a_dlst_node(p_src_dlist, p_dest_dlist);
	}
	return (p_dest_dlist);
}
