#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	original_function_src[15] = {"5678"}; //4 chars
	char	libft_function_src[15] = {"5678"}; //4 chars
	char	original_function_dest[15] = {"1234"}; //10 chars
	char	libft_function_dest[15] = {"1234"}; //10 chars
	int 	size_copie;

	size_copie = 6;
	/* Affiche la chaine original_function_src */
	printf("\nLa chaine original_function_src est: %s\n", original_function_src);
	/* Affiche la chaine initial original_function_dest */
	printf("La chaine original_function_dest est: %s\n", original_function_dest);
	/* Les adresses des chaines de charactère original_function_src et original_function_dest respectivement */
	printf("L'adresse memoire de la chaine source est : %p\n", original_function_src);
	printf("L'adresse memoire de la chaine de destination est : %p\n\n", original_function_dest);
	/* Appel la fonction strlcat() et affiche sa valeur de retour */
	printf("La valeur de retour de la fonction strlcat est: %zu\n\n", strlcat(original_function_dest, original_function_src, size_copie));
	/* Affiche la chaine original_function_dest après concatenation */
	printf("La chaine original_function_d apres concatenation est: %s\n\n\n", original_function_dest);
	/* ---------------------------------------------------------------------------------- */
	/* Affiche la chaine libft_function_src */
	printf("\nLa chaine libft_function_src est: %s\n", libft_function_src);
	/* Affiche la chaine initial libft_function_dest */
	printf("La chaine libft_function_dest est: %s\n", libft_function_dest);
	/* Les adresses des chaines de charactère libft_function_src et libft_function_dest respectivement */
	printf("L'adresse memoire de la chaine source est : %p\n", libft_function_src);
	printf("L'adresse memoire de la chaine de destination est : %p\n\n", libft_function_dest);
	/* Appel la fonction strlcat() et affiche sa valeur de retour */
	printf("La valeur de retour de la fonction strlcat est: %zu\n\n", ft_strlcat(libft_function_dest, libft_function_src, size_copie));
	/* Affiche la chaine libft_function_dest après concatenation */
	printf("La chaine libft_function_d apres concatenation est: %s\n\n", libft_function_dest);
	return (0);
}