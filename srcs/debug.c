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
