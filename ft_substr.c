/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:37:32 by sezequie          #+#    #+#             */
/*   Updated: 2023/10/06 16:30:44 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (start < ft_strlen(s) && i < len)
	{
		str[i++] = s[start++];
	}
	str[i] = '\0';
	return (str);
}

// #include <stdio.h>
// int	main()
// {
// 	char	*str = "Hello World!";
// 	char	*sub = ft_substr("BONJOUR LES HARICOTS !", 8, 14);

// 	printf("|%s|\n", sub);
// 	free(sub);
// 	return (0);
// }