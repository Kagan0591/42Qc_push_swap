#include <stdio.h>
#include <unistd.h>

\* Une lettre a la fois *\

int	main(void)

{
	char	lowercase;
	lowercase = 'g';
	printf("%c in uppercase is represented as %c", lowercase, ft_toupper(lowercase));
	return (0);
}

\* Une phrase complete *\

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	main(void)
{
	char	str[] = "C'est pas faux!\n";
	char	lowercase;
	int	i;

	i = 0;
	while (str[i])
	{
		lowercase = str[i];
		ft_putchar(ft_toupper(lowercase));
		i++;
	}
	return (0);
}