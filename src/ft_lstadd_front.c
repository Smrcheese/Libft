/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 18:59:20 by sezequie          #+#    #+#             */
/*   Updated: 2023/10/09 20:22:21 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// Adds the element ’new’ at the beginning(head) of the list.
void	ft_lstadd_front(t_list **lst, t_list *newvalue)
{
	if (lst && newvalue)
	{
		newvalue->next = *lst;
		*lst = newvalue;
	}
}
