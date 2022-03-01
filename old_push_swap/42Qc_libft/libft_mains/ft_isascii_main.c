#include <stdio.h>

int     main(void)
{
	printf("Le charactere u est un ascii %d\n\n", ft_isascii('u'));
	printf("Le charactere 7 est un ascii %d\n\n", ft_isascii('7'));
	printf("Le charactere & est un ascii %d\n\n", ft_isascii('&'));
	printf("Le charactere 128 du extended ascii n'est pas un ascii %d\n", ft_isascii(128));
	return (0);
}