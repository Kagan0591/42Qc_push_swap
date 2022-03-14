#include <stdio.h>
int	main(void)
{
	const char	*source_str = "      split       this for   me  !       "; //23 chars
	char	delemiter = ' ';
	char	**str_of_str;
	size_t	i_str_of_str;
	size_t	total_words;

	printf("\nMAIN FUNCTION TEST, la string source est : %s\n\n", source_str);
	printf("MAIN FUNCTION TEST, Le nombre de mots est de %zu mots\n\n", count_words((char *)source_str, delemiter, 0, 0));
	str_of_str = ft_split(source_str, delemiter);
	i_str_of_str = 0;
	total_words = count_words((char *)source_str, delemiter, 0, 0) + 1;
	while (i_str_of_str < total_words)
	{
		printf("Les adresses alloue sont : %p\n", &str_of_str[i_str_of_str]);
		printf("Les mots sont : %s\n", str_of_str[i_str_of_str]);
		i_str_of_str++;
	}
	return (0);
}