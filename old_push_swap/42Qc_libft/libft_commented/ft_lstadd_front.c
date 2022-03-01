/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 09:34:58 by tchalifo          #+#    #+#             */
/*   Updated: 2021/10/19 10:08:37 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Les paramètre de la fonction sont t_list **alst et t_list *new.
 *
 * Le premier est un double pointeur, pusiqu'il fait référence
 * au pointeur *next du dernier élément ajouté à la liste, celui le plus a gauche,
 * de la le double pointeur, l'un pointant a l'adresse de l'élément et l'autre
 * a l'adresse de sont pointeur *next. Le second est un pointeur vers l'adresse du nouvelle
 * élément que nous voudrons ajouter.
 *
 * La fonction permet d'ajouté de nouveau éléments depuis l'avant de la liste,
 * pensont que le début de la liste (NULL) est a la droite, nous ajouterons donc
 * depuis la gauche.
 *
 * Pour cela disont que nous avons 1 seul élément dans notre liste. Puis voulons ajouté à la suite
 * un élément supplémentaire. Il faudra pour cela que le nouvelle élément stock l'adresse
 * du pointeur *next du dernier élément deja présent dans sont propre pointeur *next.
 * Ensuite, le pointeur *next du dernier element déja présent prendra l'adresse du nouvelle élément lui même.
 *
 * Cela fait le nouvelle éléemnt aura pris sa place dans la liste chainée. */

#include "libft.h"

void ft_lstadd_front(t_list **alst, t_list *new)
{
    if (alst || new)
    {
        new->next = *alst; // Le nouvelle élément stock l'adresse du pointeur *next du dernier élément deja présent.
        *alst = new; // Le pointeur *next du dernier element déja présent stock l'adresse du nouvelle élément dans sont pointeur *next. Voir le main !
    }
}
