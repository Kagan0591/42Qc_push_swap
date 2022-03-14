#include <stdio.h>

int main(void)
{
	char	*str = {"Bonjour Comment il va ?"};

	printf("La chaine de charactere duplique devrait retourner %s\n\n", str);
	printf("La chaine de charactere duplique retourne %s\n\n", ft_strdup(str));
	return (0);
}
