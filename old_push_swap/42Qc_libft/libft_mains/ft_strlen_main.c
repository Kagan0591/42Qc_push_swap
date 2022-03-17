#include <stdio.h>

int     main(void)
{
	char    str[] = {"C'est pas faux!"}; 

	printf("..C'est pas faux!.. devrait retourner 15 characteres. ft_strlen() retourne: %lld characteres\n", ft_strlen(str));
	return (0);
}
