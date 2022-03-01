#include "push_swap.h"
/*
void	radix_sort(void)
{

}

*/
int	*counting_sort_0to9(node *unsort_nbr)
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

/*
exemple de table :
no-t	t-un	t-diz
10		10		10
14		20		14
25		52		20
52		14		25
20		25		49
49		49		52
*/
