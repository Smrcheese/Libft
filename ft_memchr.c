/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:50:37 by sezequie          #+#    #+#             */
/*   Updated: 2023/10/05 15:50:37 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	unsigned char	*ptr;
	unsigned char	chr;

	ptr = (unsigned char *)str;
	chr = (unsigned char)c;
	while (len--)
	{
		if (*ptr == chr)
			return (ptr);
		ptr++;
	}
	return (0);
}
