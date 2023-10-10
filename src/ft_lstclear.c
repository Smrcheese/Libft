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
	t_list	*ptrlst;
	t_list	*tmp;

	ptrlst = *lst;
	while (ptrlst)
	{
		tmp = ptrlst->next;
		ft_lstdelone(ptrlst, del);
		ptrlst = tmp;
	}
	*lst = 0;
}
