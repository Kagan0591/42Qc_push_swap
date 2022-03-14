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

/* Stack functions singly linked list
*/
typedef struct		slinklst
{
	int				nbr;
	struct slinklst	*next;
}slinklst;

slinklst	*ft_stknew(int nbr)
{
	slinklst	*new;

	new = malloc(sizeof(slinklst));
	if (new)
	{
		//////--Variable assignement---------->>>>
		/* Exemple
		new_node->arg = nbr;
		*/
		//////--End of virable assignement---->>>>
		new->next = NULL;
		return (new);
	}
	return (NULL);
}

slinklst	*ft_stkadd(slinklst *p_stack, int nbr)
{
	slinklst	*new_node;

	if (!p_stack)
		return (ft_stknew(nbr));
	new_node = malloc(sizeof(slinklst));
	if (new_node)
	{
		//////--Variable assignement---------->>>>
		/* Exemple
		new_node->arg = nbr;
		*/
		//////--End of virable assignement---->>>>
		new_node->next = p_stack;
		return (new_node);
	}
	return (NULL);
}

boolean 	ft_stk_isempty(slinklst *p_stack)
{
	if(p_stack == NULL)
		return (true);
	return (false);
}

int	ft_stksize(slinklst *p_stack)
{
	int	count;

	count = 0;
	while (p_stack)
	{
		count++;
		p_stack = p_stack->next;
	}
	return (count);
}

void	ft_print_node(slinklst *p_stack)
{
	if (p_stack != NULL)
	{
		ft_putnbr(p_stack->arg);
		ft_print_stack(p_stack->next);
	}
}

void	ft_print_stack(slinklst *p_stack)
{
	while (p_stack->next != NULL)
	{
		ft_print_node(p_stack);
		p_stack = p_stack->next;
	}
}

void	secure_del(slinklst *p_stack)
{
	//////--Variables to reset to zero---------->>>>
	/* Exemple
	int		i;

	i = 0;
	p_stack->arg = 0;
	while ((p_stack->arg_binary != NULL) && (i < 32))
	{
		p_stack->arg_binary[i] = 0;
		i++;
	}
	*/
	//////--End of Variables reset-------------->>>>
}

slinklst	*ft_stkdelone(slinklst *p_stack)
{
	slinklst	*new_top;

	if (p_stack)
	{
		new_top = p_stack->next;
		secure_del(p_stack);
		free(p_stack);
		return (new_top);
	}
	return (NULL);
}

slinklst	*ft_stkclear(slinklst *p_stack)
{
	if(p_stack)
	{
		while(p_stack)
			p_stack = ft_stkdelone(p_stack);
		return (p_stack);
	}
	return (p_stack);
}
