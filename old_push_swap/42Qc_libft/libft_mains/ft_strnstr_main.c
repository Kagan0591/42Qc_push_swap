#include <stdio.h>

int	main(void)
{
	char	*str = {"Une needle dans une botte de foin... sa pourrait piquer!"};
	char	*search = {"needle"};

	printf("%s\n", ft_strnstr(str, search, 20));
	return (0);
}