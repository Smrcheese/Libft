/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sezequie <sezequie@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:07:52 by sezequie          #+#    #+#             */
/*   Updated: 2023/10/09 21:06:08 by sezequie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void	*(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newlistptr;

	newlist = NULL;
	while (lst)
	{
		newlistptr = ft_lstnew(f(lst->content));
		if (!newlistptr)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, newlistptr);
		lst = lst->next;
	}
	return (newlist);
}

// void	*my_function(void *content)
// {
// 	int	*value;
// 	int	*result;

// 	value = (int *)content;
// 	result = malloc(sizeof(int));
// 	if (result)
// 		*result = (*value) + 1;
// 	return (result);
// }

// void	my_delete(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	t_list	*list ;
// 	t_list	*temp;
// 	t_list	*new_list;
// 	int		i;
// 	int		*value;

// 	list = NULL;
// 	i = 0;
// 	while (i < 5)
// 	{
// 		value = malloc(sizeof(int));
// 		if (value)
// 		{
// 			*value = i;
// 			ft_lstadd_back(&list, ft_lstnew(value));
// 		}
// 		i++;
// 	}
// 	new_list = ft_lstmap(list, my_function, my_delete);
// 	printf("Original list: ");
// 	temp = list;
// 	while (temp)
// 	{
// 		printf("%d ", *((int *)temp->content));
// 		temp = temp->next;
// 	}
// 	printf("\n");
// 	printf("Mapped list (added 1 to each element): ");
// 	temp = new_list;
// 	while (temp)
// 	{
// 		printf("%d ", *((int *)temp->content));
// 		temp = temp->next;
// 	}
// 	printf("\n");
// 	ft_lstclear(&list, my_delete);
// 	ft_lstclear(&new_list, my_delete);
// 	return (0);
// }
