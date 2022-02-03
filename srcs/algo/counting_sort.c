/* Ce fichier contient des versions différentes de l'algo "counting sort".
 *
 * 1ere version: Une liste chainé en entrée, un tableau en sortie.
 * PROTOYPE:
 *	int *counting_sort_0to9(stack *unsort_nbr);
 *
 * 2ieme version: Un tableau en entrée, un tableau en sortie.
 * PROTOYPE:
 *	int *counting_sort_0to9(int *unsort_nbr, int size);
 */

#include "algo.h"
// -----***VERSION 1***-----
int	*counting_sort_0to9_stk(node *unsort_nbr)
{
	node	*pt_beginstk_of_unsort_nbr;
	int	counting_tab[9]; // This tab have 10 slots, one for each possible number (0 to 9).
	int	*sorted_nbr;
	int	i;

	i = 0;
//	Put all the tabs value at 0
	while (i < 10)
	{
		counting_tab[i] = 0;
		i++;
	}
//	Store the count of each unique value
	i = 0;
	pt_beginstk_of_unsort_nbr = unsort_nbr;
	while (i < 10)
	{
		while (unsort_nbr != NULL)
		{
			if (unsort_nbr->arg == i)
				counting_tab[i] = counting_tab[i] + 1; // Increment of 1 when finding corresponding number
			unsort_nbr = unsort_nbr->next; // Increment into the stack
		}
		unsort_nbr = pt_beginstk_of_unsort_nbr; // restore the stack from begining to repeate the process for each num
		i++;
	}
//	Modify the count array by adding the previous counts.
	i = 0;
	while (i < 9)
	{
		counting_tab[i + 1] = (counting_tab[i] + counting_tab[i + 1]);
		i++;
	}
	sorted_nbr = calloc((ft_stksize(pt_beginstk_of_unsort_nbr) - 1), sizeof(int));
	while (unsort_nbr != NULL)
	{
		sorted_nbr[counting_tab[unsort_nbr->arg] - 1] = unsort_nbr->arg;
		counting_tab[unsort_nbr->arg] = counting_tab[unsort_nbr->arg] - 1;
		unsort_nbr = unsort_nbr->next;
	}
	return (sorted_nbr);
}

// -----***VERSION 2***-----
int	*counting_sort_0to9_tab(int *unsort_nbr, int size)
{
	int	counting_tab[9]; // This tab have 10 slots, one for each possible number (0 to 9).
	int	*sorted_nbr;
	int	i;
	int j;

	i = 0;
//	Put all the tabs value at 0
	while (i < 10)
	{
		counting_tab[i] = 0;
		i++;
	}
//	Store the count of each unique value
	i = 0;
	j = 0;
	while (i < 10)
	{
		while (j < size)
		{
			if (unsort_nbr[j] == i)
				counting_tab[i] = counting_tab[i] + 1; // Increment of 1 when finding corresponding number
			j++;
		}
		j = 0;
		i++;
	}
//	Modify the count array by adding the previous counts.
	i = 0;
	while (i < 9)
	{
		counting_tab[i + 1] = (counting_tab[i] + counting_tab[i + 1]);
		i++;
	}
//	Allocate memory to the sorted_nbr tab and place the objects in their correct
//	position and decrease the count by one.
	sorted_nbr = calloc(size, sizeof(int));
	while (j < size)
	{
		sorted_nbr[counting_tab[unsort_nbr[j]] - 1] = unsort_nbr[j];
		counting_tab[unsort_nbr[j]] = counting_tab[unsort_nbr[j]] - 1;
		j++;
	}
	return (sorted_nbr);
}

// -----***MAIN_TO_TEST***-----
int	main(void)
{
	node	*stk;
	int	tab[5];
	int	*stk_a_sort;
	int	*tab_a_sort;
	int	i;

	ft_putstr("All the input are the numbers 4167\n\n");
//	Value for stack input test
	stk = ft_stknew(2);
	stk = ft_stkadd(stk, 4);
	stk = ft_stkadd(stk, 1);
	stk = ft_stkadd(stk, 6);
	stk = ft_stkadd(stk, 7);
//	Value for tab input test
	tab[0] = 2;
	tab[1] = 4;
	tab[2] = 1;
	tab[3] = 6;
	tab[4] = 7;
	tab_a_sort = counting_sort_0to9_tab(tab, 5);
	stk_a_sort = counting_sort_0to9_stk(stk);
//	Results
	ft_putstr("check the final sorted_nbr stk \n\n");
	i = 0;
	while (i < 5)
	{
		ft_putstr("L'index ");
		ft_putnbr(i);
		ft_putstr(" = ");
		ft_putnbr(stk_a_sort[i]);
		ft_putstr("\n\n");
		i++;
	}
	ft_putstr("check the final sorted_nbr tab \n\n");
	i = 0;
	while (i < 5)
	{
		ft_putstr("L index ");
		ft_putnbr(i);
		ft_putstr(" = ");
		ft_putnbr(tab_a_sort[i]);
		ft_putstr("\n\n");
		i++;
	}
	free(stk_a_sort);
	free(tab_a_sort);
	ft_stkclear(stk);
	return (0);
}
