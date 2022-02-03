#include "algo.h"

void	ft_putstr(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_putnbr(int n)
{
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if ((nbr / 10) != 0)
		ft_putnbr(nbr / 10);
	ft_putchar((nbr % 10) + 48);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

// Fonctions autorisées pour le sorting

/* Interchange les deux derniers éléments de la pile a
 */
node	*swap_stkvalue_a(node *p_stk)
{
	node	*tmp;

	ft_putstr("sa\n");
	if (ft_stksize(p_stk) >= 2)
	{
		tmp = p_stk;
		p_stk = p_stk->next;
		tmp->next = p_stk->next;
		p_stk->next = tmp;
	}
	return (p_stk);
}

/* Interchange les deux derniers éléments de la pile b
 */
node	*swap_stkvalue_b(node *p_stk)
{
	node	*tmp;

	ft_putstr("sb\n");
	if (ft_stksize(p_stk) >= 2)
	{
		tmp = p_stk;
		p_stk = p_stk->next;
		tmp->next = p_stk->next;
		p_stk->next = tmp;
	}
	return (p_stk);
}

/* Déplace un élément du sommet de la pile b vers celle ce la pile a
 */
void	push_to_a(node **origin, node **dest)
{
	node	*tmp_orig;
	node	*tmp_dest;

	ft_putstr("pa\n");
	if (origin && dest)
	{
		tmp_orig = (*origin)->next;
		tmp_dest = (*dest);
		*dest = *origin;
		(*dest)->next = tmp_dest;
		(*origin) = tmp_orig;
	}
}

/* Déplace un élément du sommet de la pile a vers celle ce la pile b
 */
void	push_to_b(node **origin, node **dest)
{
	node	*tmp_orig;
	node	*tmp_dest;

	ft_putstr("pb\n");
	if (origin && dest)
	{
		tmp_orig = (*origin)->next;
		tmp_dest = (*dest);
		*dest = *origin;
		(*dest)->next = tmp_dest;
		(*origin) = tmp_orig;
	}
}

/* Effectue un rotation de la pile 'a', envoyant le premier élément au fond de la pile sur le sommet de a pile.
 * Cela fera décendre vers le bas les valeurs de la pile.
 */
node	*rotate_a(node *p_stk) // Put the last node to the top
{
	node	*tmp;
	node	*tmp_top;

	ft_putstr("ra\n");
	if (ft_stksize(p_stk) >= 2)
	{
		tmp_top = p_stk->next;
		tmp = p_stk;
		while (p_stk->next != NULL)
			p_stk = p_stk->next;
		tmp->next = NULL;
		p_stk->next = tmp;
		return (tmp_top);
	}
	else
		return (p_stk);
}

/* Effectue un rotation de la pile 'b', envoyant le premier élément au fond de la pile sur le sommet de a pile.
 * Cela fera décendre vers le bas les valeurs de la pile.
 */
node	*rotate_b(node *p_stk) // Put the last node to the top
{
	node	*tmp;
	node	*tmp_top;

	ft_putstr("rb\n");
	if (ft_stksize(p_stk) >= 2)
	{
		tmp_top = p_stk->next;
		tmp = p_stk;
		while (p_stk->next != NULL)
			p_stk = p_stk->next;
		tmp->next = NULL;
		p_stk->next = tmp;
		return (tmp_top);
	}
	else
		return (p_stk);
}

/* Effectue un rotation de la pile 'a', envoyant le dernier élément au sommet de la pile vers le fond de la pile.
 * Cela fera monter vers le haut les valeurs de la pile.
 */
node	*reverse_rotate_a(node *p_stk) // Put the first node to the buttom
{
	node		*tmp;
	node		*top_tmp;
	size_t		pos;

	ft_putstr("rra\n");
	if (ft_stksize(p_stk) >= 2)
	{
		pos = ft_stksize(p_stk);
		tmp = p_stk;
		while (pos > 2)
		{
			p_stk = p_stk->next;
			pos--;
		}
		top_tmp = p_stk->next;
		p_stk->next = NULL;
		top_tmp->next = tmp;
		return (top_tmp);
	}
	else
		return (p_stk);
}

/* Effectue un rotation de la pile 'b', envoyant le dernier élément au sommet de la pile vers le fond de la pile.
 * Cela fera monter vers le haut les valeurs de la pile.
 */
node	*reverse_rotate_b(node *p_stk) // Put the first node to the buttom
{
	node		*tmp;
	node		*top_tmp;
	size_t		pos;

	ft_putstr("rrb\n");
	if (ft_stksize(p_stk) >= 2)
	{
		pos = ft_stksize(p_stk);
		tmp = p_stk;
		while (pos > 2)
		{
			p_stk = p_stk->next;
			pos--;
		}
		top_tmp = p_stk->next;
		p_stk->next = NULL;
		top_tmp->next = tmp;
		return (top_tmp);
	}
	else
		return (p_stk);
}
