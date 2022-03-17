#include <stdio.h>

int		main(void)
{
	char	str1[] = "lorem ipsum dolor sit";
	char	str2[] = "lorem ipsum dolor sit";

	t_list	*new_element;

	new_element = ft_lstnew((void *)str1);
	printf("\n%s\n", new_element->content);
    new_element->content = str2;
	printf("\n%s\n", new_element->content);
}