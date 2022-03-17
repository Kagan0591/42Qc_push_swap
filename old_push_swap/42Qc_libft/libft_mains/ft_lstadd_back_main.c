#include <stdio.h>

int main(void)
{
    char    str1[] = "On en a";
    char    str2[] = "Sir! Sir!";
    char    str3[] = "HOOO!";
    char    str4[] = "GROSSS!";
    t_list  *pt_new_element;
    t_list  *new_element;

    new_element = ft_lstnew((void *)str1);
    printf("Avant l'ajout des nouvelles éléments:\n\n%s\n\n", new_element->content);

    ft_lstadd_front(&new_element, ft_lstnew((void *)str2));
    ft_lstadd_front(&new_element, ft_lstnew((void *)str3));
    pt_new_element = new_element;
    printf("Après l'ajout de nouvelles éléments au debut:\n\n%s\n", new_element->content);
    while (new_element->next != NULL)
    {
        new_element = new_element->next;
        printf("%s\n", new_element->content);
    }
    new_element = pt_new_element;
    ft_lstadd_back(&new_element, ft_lstnew((void *)str4));
    printf("Après l'ajout du nouvelle élément a la fin:\n\n%s\n", new_element->content);
    while (new_element->next != NULL)
    {
        new_element = new_element->next;
        printf("%s\n", new_element->content);
    }
    return (0);
}