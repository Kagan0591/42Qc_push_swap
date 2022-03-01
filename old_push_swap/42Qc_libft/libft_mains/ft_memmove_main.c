#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str[100] = "Learningisfun";
	char	*first
	char	*second;
	int	memspace; // Variable pour modifier la distance en memoire entre les deux chaines.

	first = str; // Variable pour tester memcpy
	second = str; // Variable pour tester ft_memmove
	memspace = 8;
	printf("La chaine de charactere initial est :: %s\n", str);
	printf("L'adresse de destination est %p et celle de la source est %p. Donc la destination est plus loin de %d emplacement memoire\n", first + memspace, first, memspace);
	/* when overlap happens then it just ignore it */
	memcpy(first + memspace, first, 10);
	printf("memcpy avec un chevauchement entre les deux chaines (overlap) si la valeur de la variable memspace est plus grande que 14 :: %s\n", str); 

	/* when overlap it start from first position */
	ft_memmove(second + memspace, first, 10);
	printf("memmove avec un chevauchement entre les deux chaines (overlap) si la valeur de la variable memspace est plus grande que 14 :: %s\n", str);
	return (0);
}