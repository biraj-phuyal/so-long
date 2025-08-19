/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:23:19 by biphuyal          #+#    #+#             */
/*   Updated: 2025/04/13 13:41:30 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!*lst)
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	new->next = *lst;
	*lst = new;
}
/*
int	main(void) {
    t_list *lst = NULL;
    
    ft_lstadd_front(&lst, ft_lstnew("World"));
    printf("1st node: %s\n", (char*)lst->content);
    
    ft_lstadd_front(&lst, ft_lstnew("Hello"));
    printf("1st node after add: %s\n", (char*)lst->content);
    printf("2nd node: %s\n", (char*)lst->next->content);
    
    printf("Next of last node: %s\n", lst->next->next ? "NOT NULL" : "NULL");
    
    return (0);
}
 */
