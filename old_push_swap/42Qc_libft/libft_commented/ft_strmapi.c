/* 1. La fonction cree une chaine de char. La chaine est initialisee
 * avec malloc et prend la grandeur de la chaine s + 1 pour le '\0'.
 * 2. Cette meme chaine egale la valeur retournee de la chaine
 * passer en parametre de la fonction mystere f.
 * 3. Puis a chaine rst retournee
 *
 * Dans la foncition une protection pour malloc et si
 * la chaine s est vide est de mis */

/* La fonction va comme suit. Une chaine est cree pour le retour de valeur de la fonction ft_strmapi.
 * Puis, une variable de comptage est initialiser a 0 pour defiler la chiane s1 passer en
 * parametre de la fonction f. Ensuite la */
#include "libft.h"

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char    *sptr;
    size_t  i;

    i = 0;
    if (!s)
        return (0);
    sptr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
    if (!sptr)
        return (0);
    while (s[i])
   	{
    	sptr[i] = (*f)(i, s[i]);
    	i++;
    }
    sptr[i]  = '\0';
    return (sptr);
}
