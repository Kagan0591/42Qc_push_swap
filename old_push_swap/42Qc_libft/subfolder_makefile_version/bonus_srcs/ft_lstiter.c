/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:25:30 by tchalifo          #+#    #+#             */
/*   Updated: 2021/10/19 13:30:41 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Itère sur la list lst et applique la fonction f au contenu chaque élément.
 *
 * Prototypes
 * #1 L’adresse du pointeur vers un élément.
 * #2. L’adresse de la fonction à appliquer. */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}
