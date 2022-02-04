/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 09:10:05 by tchalifo          #+#    #+#             */
/*   Updated: 2021/11/11 10:40:22 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	s1_length;

	s1_length = ft_strlen(s1) + 1;
	s2 = malloc(sizeof(*s2) * s1_length);
	if (!s2)
		return (0);
	ft_strlcpy(s2, s1, s1_length);
	free((void*)s1);
	return (s2);
}
