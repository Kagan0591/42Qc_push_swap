/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalifo <tchalifo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 13:56:38 by tchalifo          #+#    #+#             */
/*   Updated: 2021/11/09 11:12:16 by tchalifo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclenght;

	i = 0;
	srclenght = ft_strlen(src);
	if (dstsize == 0)
		return (srclenght);
	while (src[i] != '\0' && dstsize-- > 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclenght);
}
