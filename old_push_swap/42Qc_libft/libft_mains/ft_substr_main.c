#include <stdio.h>

int main(void)
{
	char	*str_src = {"Sir! Sir! On en a gros!!!"};

	printf("%s\n", ft_substr(str_src, 'O', 7));
	return (0);
}

