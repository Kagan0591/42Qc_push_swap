#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
	char	array[8] = {"Bonjour"};

	/* Afficher les valeurs initiales */
	printf("%s\n", array);
	/* Remise a zero du bloc mémoire */
	ft_bzero(array, sizeof(array));
	printf("\n");
	/* Afficher les nouvelles valeurs */
	printf("%s\n", array);
	return (0);
}
