#include <stdio.h>

int     main(void)
{
	printf("Le charactere u est un charactere imprimable %d\n\n",
	ft_isprint('u'));
	printf("Le charactere 7 est un charactere imprimable %d\n\n",
	ft_isprint('7'));
	printf("Le charactere & est un charactere imprimable %d\n\n",
	ft_isprint('&'));
	printf("Le charactere espace est un charactere imprimable %d\n\n",
	ft_isprint(' '));
	printf("Le charactere TAB du ascii n'est pas un charactere imprimable %d\n",
	ft_isprint(9));
	return (0);
}