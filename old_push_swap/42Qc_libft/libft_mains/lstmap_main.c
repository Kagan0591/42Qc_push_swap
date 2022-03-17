#include <stdio.h>

int	main(void)

{
	t_list	*my_list;
	t_list	*my_second_list;

	char	str1[] = "GROSSS!";
	char	str2[] = "On en a";
	char	str3[] = "Sir! Sir!";
	char	str4[] = "HOOO!";

	my_list = ft_lstnew(void *content);
	printf("Valeur de my_list\n\n");
	ft_lstadd_front(&new_element, ft_lstnew((void *)str2));
	ft_lstadd_front(&new_element, ft_lstnew((void *)str3));
	ft_lstadd_front(&new_element, ft_lstnew((void *)str3));
	while (new_element->next != NULL)
	{
		new_element = new_element->next;
		printf("%s\n", new_element->content);
	}
	my_second_list = ft_lstmap(my_list, void *(*f)(void *), void (*del)(void *));


}