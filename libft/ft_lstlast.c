/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:34:44 by biphuyal          #+#    #+#             */
/*   Updated: 2025/04/13 13:42:06 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	current = lst;
	while (current && current->next != NULL)
		current = current->next;
	return (current);
}
/* 
int	main(void)
{
	t_list	*list;
	t_list	*last;
	t_list	*tmp;

    list = NULL;
    last = NULL;
    last = ft_lstlast(list);
    printf("Last of empty list: %s\n", last ? "NOT NULL (WRONG)" : "NULL (OK)");
    list = ft_lstnew("First");
    last = ft_lstlast(list);
    printf("Last of single-node list: %s\n", (char *)last->content);
    list->next = ft_lstnew("Second");
    list->next->next = ft_lstnew("Third");
    last = ft_lstlast(list);
    printf("Last of three-node list: %s\n", (char *)last->content);
    while (list)
    {
        tmp = list->next;
        free(list);
        list = tmp;
    }
    return (0);
}
 */
