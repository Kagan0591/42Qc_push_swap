#include "test.h"

int	main(void)
{
	node_dlink	*test_stack;
	int	i;

	i = 0;
	test_stack = NULL;
	while (i < 10)
	{
		test_stack = ft_stkadd_dlink(test_stack, i);
		i++;
	}
	ft_print_stack_dlink(test_stack);
	ft_putstr("Supprime un element de la list\n");
	test_stack = ft_stkdelone_dlink(test_stack);
	ft_print_stack_dlink(test_stack);
	ft_putstr("\nla longueur de la list\n");
	ft_putnbr(ft_stksize_dlink(test_stack));
	ft_putstr("\nSupprime la list\n");
	test_stack = ft_stkclear_dlink(test_stack);
	ft_print_stack_dlink(test_stack);
	return (0);
}