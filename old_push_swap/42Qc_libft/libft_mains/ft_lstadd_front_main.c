/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_main.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 09:34:58 by tchalifo          #+#    #+#             */
/*   Updated: 2021/10/20 16:42:13 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int main(void)
{
	char	str1[] = "GROSSS!";
	char	str2[] = "On en a";
	char	str3[] = "Sir! Sir!";

	t_list	*new_element;

	new_element = ft_lstnew((void *)str1);
	printf("Avant l'ajout du nouvelle élément:\n\n%s\n\n\n", new_element->content);

	ft_lstadd_front(&new_element, ft_lstnew((void *)str2));
	ft_lstadd_front(&new_element, ft_lstnew((void *)str3));
	printf("Après l'ajout du nouvelle élément:\n\n%s\n", new_element->content);
	while (new_element != NULL)
	{
		new_element = new_element->next;
		printf("%s\n", new_element->content);
	}
	return (0);
}

