#include "push_swap.h"

d_container	*initmem(void)
{
	d_container *data;

	data = malloc(sizeof(d_container));
	data->stack_a = NULL;
	data->stack_b = NULL;
	return (data);
}

d_container	*clearmem(d_container *p_data)
{
	if (p_data)
	{
		if (p_data->stack_a != NULL)
			ft_stkclear_dlink(p_data->stack_a);
		if (p_data->stack_b != NULL)
			ft_stkclear_dlink(p_data->stack_b);
	}
	free(p_data);
	p_data = NULL;
	return (p_data);
}
