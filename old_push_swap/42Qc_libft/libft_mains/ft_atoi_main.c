#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	char	*str = {"-1234"};
	printf("Resultat de la fonction libft atoi:\n");
	printf("%d\n\n", ft_atoi(str));
	printf("Resultat de la fonction original atoi: \n");
	printf("%d\n\n", atoi(str));
	return (0);
}