#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char	array[10] = {"123456789"};
	char	returned[10] = {"0123456789"};
	size_t	init_lenght;
	size_t	dest_lenght;

	init_lenght = strlen(array);
	/* Afficher les valeurs initiales de array */
	printf("La chaine source est initialement de %zu charactères :: %s\n", init_lenght, array);
	/* Copier les valeurs de array dans returned */
	ft_memcpy(returned, array, sizeof(array));
	dest_lenght = strlen(returned);
	/* Afficher les valeurs copiées dans returned */
	printf("La chaine, une fois copié, retourne bien %zu charactères :: %s\n", dest_lenght, returned);
	/* S’assurer que les deux chaines ne sont pas adjecente en mémoire l’une, l’autre */
	printf("L'emplacement mémoire de la source est :: %p\n", array);
	printf("l'emplacement mémoire de la destination est :: %p\n", returned);
	return (0);
}