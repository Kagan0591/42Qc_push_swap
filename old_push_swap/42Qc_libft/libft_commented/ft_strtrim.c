#include "libft.h"

static int	ft_getstart(const char *s, const char *set)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (ft_strchr(set, s[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	ft_getend(const char *s, const char *set)
{
	size_t	i_lenght;
	size_t	i;

	i_lenght = ft_strlen(s) - 1;
	i = 0;
	while (s[i_lenght] > 0)
	{
		if (ft_strchr(set, s[i_lenght]) == 0)
			break ;
		i_lenght--;
		i++;
	}
	return (i);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*s2;
	size_t	start;
	size_t	end;
	size_t	s_lenght;

	start = ft_getstart(s1, set);
	end = ft_getend(s1, set);
	s_lenght = ft_strlen(s1) - start;
	s2 = ft_substr(s1, (unsigned int) start, s_lenght - end);
	return (s2);
}


/* Une version plus courte mais moins comprehensible de strtrim. La suppression des variables
 * start et end ecourte visuellement la fonction mais rend la lecture plus complexe */

/*
char	*ft_strtrim(const char *s1, const char *set)
{
	char	*s2;

	s2 = ft_substr(s1, (unsigned int) ft_getstart(s1, set),/
     (ft_strlen(s1) - (ft_getstart(s1, set))) - ft_getend(s1, set));
	return (s2);
}
*/
