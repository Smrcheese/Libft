/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:04:17 by sezequie          #+#    #+#             */
/*   Updated: 2023/10/09 20:22:33 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Adds the element ’new’ at the end(tail) of the list.
void	ft_lstadd_back(t_list **list, t_list *newvalue)
{
	t_list	*n;

	if (list && newvalue)
	{
		if (!*list)
			*list = newvalue;
		else
		{
			n = ft_lstlast(*list);
			n->next = newvalue;
		}
	}
}
