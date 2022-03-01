#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char
	array[] = {85, 63, 35, 8, 21, 24};
	size_t  i;
	size_t  size;
    
    i = 0;
    size = 8; // Variable qui dicte combien de case du tableau doivent etres set
	/* Afficher les valeurs initiales */
	while(i < sizeof(array))
	{
		printf("%d\n", array[i]);
		i++;
	}
	/* Remise a zero du bloc mémoire */
	ft_memset(array, 0, size); // La deuxieme valeur est a la valeur de subtitution
	printf("\n");

	/* Afficher les nouvelles valeurs */
	i = 0;
	while(i < sizeof(array))
	{
		printf("%d\n", array[i]);
		i++;
	}
	printf("\n");
	return (0);
}
