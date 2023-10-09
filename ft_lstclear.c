/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:05:47 by sezequie          #+#    #+#             */
/*   Updated: 2023/10/09 19:05:57 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void	*))
{
	t_list	*n;
	t_list	*tmp;

	n = *lst;
	while (n)
	{
		tmp = n->next;
		ft_lstdelone(n, del);
		n = tmp;
	}
	*lst = 0;
}
