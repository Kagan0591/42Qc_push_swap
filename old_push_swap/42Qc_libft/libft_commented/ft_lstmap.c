/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:36:19 by tchalifo          #+#    #+#             */
/*   Updated: 2021/10/21 11:25:33 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Itère sur la liste lst et applique la fonction f au contenu de chaque élément.
 * Crée une nouvelle liste résultant des applications successives de f. la
 * fonction del est la pour detruire le contenu d un element si necessaire
 *
 * Prototypes
 * #1. L’adresse du pointeur vers un élément.
 * #2. L’adresse de la fonction à appliquer.
 *
 * case si pas lst ou funciton f
 * case si
 *
 * */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*new_node;

	first = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (!new_node)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		ft_lstadd_back(&first, new_node);
		lst = lst->next;
	}
	return (first);
}
