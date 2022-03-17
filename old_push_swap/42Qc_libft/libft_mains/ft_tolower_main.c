\* Une lettre a la fois *\

#include <stdio.h>

int	main()
{
	char	uppercase;

	uppercase = 'G';
	printf("%c in lowercase is represented as %c", uppercase, ft_tolower(uppercase));
	return (0);
}

\* Une phrase complete *\

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main()
{
	char	str[] = "PAS BESOIN D'CRIER NON PLUS! @!#^&\n";
	char	uppercase;
	int	i;

	i = 0;
	while (str[i]) 
	{
		uppercase = str[i];
		ft_putchar(ft_tolower(uppercase));
		i++;
	}
	return (0);
}