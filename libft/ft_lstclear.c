/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:00:57 by biphuyal          #+#    #+#             */
/*   Updated: 2025/04/14 17:13:05 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
void	del(void *content) {
    free(content);
}
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*tmp;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		tmp = current->next;
		ft_lstdelone(current, del);
		current = tmp;
	}
	*lst = NULL;
}

/*
int	main(void) {
    t_list *lst = ft_lstnew(strdup("Node1"));
    lst->next = ft_lstnew(strdup("Node2"));
    lst->next->next = ft_lstnew(strdup("Node3"));

    ft_lstclear(&lst, del);
    printf("List after clear: %s\n", lst ? "NOT NULL" : "NULL");
    return (0);
}
*/
