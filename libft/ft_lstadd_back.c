/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:35:38 by biphuyal          #+#    #+#             */
/*   Updated: 2025/04/29 14:28:59 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}
/* 
int	main(void) {
    t_list *lst = NULL;
    
    ft_lstadd_back(&lst, ft_lstnew("Hello"));
    printf("1st node: %s\n", (char*)lst->content);
    
    ft_lstadd_back(&lst, ft_lstnew("World"));
    printf("2nd node: %s\n", (char*)lst->next->content);
    
    ft_lstadd_back(&lst, ft_lstnew("!"));
    printf("3rd node: %s\n", (char*)lst->next->next->content);
    
    printf("Next of last node: %s\n",
		lst->next->next->next ? "NOT NULL" : "NULL");
    
    return (0);
}
 */
