#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	array[30] = {"Elle est ou la poulette !?"};
	char	returned[9];

	/* Affiche les valeurs initiales de array */
	printf("les valeur de la chaine source : %s\n", array);
	/* Les adresses des chaines de charactère array et returned */
	printf("L adresse memoire de la chaine source est : %p\n", array);
	printf("L adresse memoire de la chaine de destination est : %p\n", returned);
	/* Appel la fonction ft_strlcpy() et affiche sa valeur de retour */
	printf("La valeur de retour de la fonction ft_strlcpy (la longueur de la source) est : %zu\n", ft_strlcpy(returned, array, sizeof(returned)));
	/* Affiche les valeurs copiées dans returned */
	printf("La chaine de destination affiche maintenant les valeurs de la source : %s\n", returned);
	/* remet a zéro la chaine de characrère returned */
	bzero(returned, sizeof(returned));
	/* Appel la fonction strlcpy() original et affiche sa valeur de retour */
	printf("La valeur de retour de la fonction strlcpy original (la longueur de la source) est : %lu\n", strlcpy(returned, array, sizeof(returned)));
	/* Affiche les valeurs copiées dans returned */
	printf("La chaine de destination affiche maintenant les valeurs de la source : %s\n", returned);
	return (0);
}