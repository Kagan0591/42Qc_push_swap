#include <stdio.h>

int	main(void)
{
	char	*str1 = {"Bonjour, "};
	char	*str2 = {"comment allez vous ?"};

	printf("%s\n", ft_strjoin(str1, str2));
}
