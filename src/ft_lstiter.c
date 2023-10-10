/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:07:05 by sezequie          #+#    #+#             */
/*   Updated: 2023/10/09 20:23:49 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *list, void (*f)(void	*))
{
	t_list	*listptr;

	listptr = list;
	while (listptr)
	{
		f(listptr->content);
		listptr = listptr->next;
	}
}
