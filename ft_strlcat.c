/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:50:53 by sezequie          #+#    #+#             */
/*   Updated: 2023/10/05 15:50:53 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *source, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (dst[i] != '\0')
		i++;
	while (source[j] != '\0')
		j++;
	if (dstsize <= i)
		j += dstsize;
	else
		j += i;
	while (source[k] != '\0' && i + 1 < dstsize)
	{
		dst[i] = source[k];
		i++;
		k++;
	}
	dst[i] = '\0';
	return (j);
}
