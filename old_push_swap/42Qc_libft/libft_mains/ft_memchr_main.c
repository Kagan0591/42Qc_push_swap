#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	search[] = "TechOnTheNet";
	char	*ptr;
	size_t	size;

	size = 13;
	/* Recherche la position du premier “N” trouvé*/
	ptr = ft_memchr(search, 'N', size);
	/* Si “N” est trouvé, affiche sa position, sinon retourne NULL */
	if (ptr != NULL)
		printf("Nouvelle recherche de charactère. Recherche d'un 'N'... Le charactère a été trouvé a la position %ld.\n", 1+(ptr-search));
	else
		printf("Nouvelle recherche de charactère. Recherche d'un 'N'... Le charactère n'a pas été trouvé.\n");
		printf("%s\n", ptr);
	printf("\n");
	/* Recherche la position du premier “Z” trouvé*/
	ptr = ft_memchr(search, 'Z', size);
	/* Si “Z” est trouvé, affiche sa position, sinon retourne NULL */
	if (ptr != NULL) 
		printf("Nouvelle recherche de charactère. Recherche d'un 'Z'... Le charactère a été trouvé a la position %ld.\n", 1+(ptr-search));
	else
		printf("Nouvelle recherche de charactère. Recherche d'un 'Z'... Le charactère n'a pas été trouvé.\n");
		printf("%s\n", ptr);
		printf("\n");
	/* Recherche la position du '\0' */
		ptr = ft_memchr(search, '\0', size);
	/* Si '\0' est trouvé, affiche sa position, sinon retourne NULL */
	if (ptr != NULL) 
		printf("Nouvelle recherche de charactère. Recherche du charactère de fin de chaine... Le charactère de fin de chaine a été trouvé a la position %ld.\n", 1+(ptr-search));
	else
		printf("Nouvelle recherche de charactère. Recherche du charactère de fin de chaine... Oupss! Aucun de fin n'a pas été trouvé.\n");
		printf("%s\n", ptr);
	printf("\n");
	/* ----------Départ des test sur la fonction original---------- */
	printf("Test de la fonction original a partir d'ici!\n\n");
	/* Recherche la position du premier “N” trouvé*/
	ptr = memchr(search, 'N', size);
	/* Si “N” est trouvé, affiche sa position, sinon retourne NULL */
	if (ptr != NULL)
		printf("Nouvelle recherche de charactère. Recherche d'un 'N'... Le charactère a été trouvé a la position %ld.\n", 1+(ptr-search));
	else
		printf("Nouvelle recherche de charactère. Recherche d'un 'N'... Le charactère n'a pas été trouvé.\n");
		printf("%s\n", ptr);
	printf("\n");
	/* Recherche la position du premier “Z” trouvé*/
	ptr = memchr(search, 'Z', size);
	/* Si “Z” est trouvé, affiche sa position, sinon retourne NULL */
	if (ptr != NULL) 
		printf("Nouvelle recherche de charactère. Recherche d'un 'Z'... Le charactère a été trouvé a la position %ld.\n", 1+(ptr-search));
	else
		printf("Nouvelle recherche de charactère. Recherche d'un 'Z'... Le charactère n'a pas été trouvé.\n");
		printf("%s\n", ptr);
		printf("\n");
	/* Recherche la position du '\0' */
	ptr = memchr(search, '\0', size);
	/* Si '\0' est trouvé, affiche sa position, sinon retourne NULL */
	if (ptr != NULL) 
		printf("Nouvelle recherche de charactère. Recherche du charactère de fin de chaine... Le charactère de fin de chaine a été trouvé a la position %ld.\n", 1+(ptr-search));
	else
		printf("Nouvelle recherche de charactère. Recherche du charactère de fin de chaine... Oupss! Aucun de fin n'a pas été trouvé.\n");
		printf("%s\n", ptr);
	return (0);
}
