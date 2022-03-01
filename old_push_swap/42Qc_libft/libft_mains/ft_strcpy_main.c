#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	function_src[30] = {"Elle est ou la poulette !?"};
	char	function_dest[30];

	/* Affiche les valeurs initiales de function_src */
	printf("les valeur de la chaine source : %s\n", function_src);
	/* Les adresses des chaines de charactère function_src et function_dest */
	printf("L adresse memoire de la chaine source est : %p\n", function_src);
	printf("L adresse memoire de la chaine de destination est : %p\n", function_dest);
	/* Appel la fonction ft_strcpy() et affiche sa valeur de retour */
	printf("La valeur de retour de la fonction ft_strcpy est : %s\n", ft_strcpy(function_dest, function_src));
	/* remet a zéro la chaine de characrère function_dest */
	bzero(function_dest, sizeof(function_dest));
	/* Appel la fonction strcpy() original et affiche sa valeur de retour */
	printf("La valeur de retour de la fonction strcpy original est : %s\n", strcpy(function_dest, function_src));
	return (0);
}