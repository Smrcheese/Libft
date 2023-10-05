/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:50:41 by sezequie          #+#    #+#             */
/*   Updated: 2023/10/05 15:50:41 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, unsigned long n)
{
	unsigned char		*dest2;
	const unsigned char	*src2;

	dest2 = dest;
	src2 = src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n > 0)
	{
		*dest2 = *src2;
		dest2++;
		src2++;
		n--;
	}
	return (dest);
}
