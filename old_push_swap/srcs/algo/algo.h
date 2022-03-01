#ifndef ALGO
#define ALGO

#include <stdlib.h>
#include <unistd.h>

typedef struct node
{
	int			arg; // for counting sort
	int			arg_unites; // for radix sort
	int			arg_tens; // for radix sort
	int			arg_hundreds; // for radix sort
	struct node	*next;
}node;

// Counting sort functions
int			*counting_sort_0to9_tab(int *unsort_nbr, int size);
int			*counting_sort_0to9_stk(node *unsort_nbr);

// Radix sort functions
int unites_to_top_rotate(node **lst, int nbr_to_find);

//	For testing (including main function)
void		ft_putstr(char *str);
void		ft_putnbr(int n);
void		ft_putchar(char c);
node		*ft_stknew(int nbr);
node		*ft_stkadd(node *p_stk, int nbr);
int			ft_stksize(node *p_stk);
node		*ft_stkdelone(node *p_stk);
node		*ft_stkclear(node *p_stk);


#endif
