/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:52:37 by biphuyal          #+#    #+#             */
/*   Updated: 2025/04/29 13:38:49 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
void	del(void *content) {
    printf("Deleted: %s\n", (char *)content);
    free(content);
}
 */

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		lst->next = NULL;
		del(lst->content);
		free(lst);
	}
}
/* 
int	main(void) {
    t_list *node = ft_lstnew(strdup("Hello"));
    ft_lstdelone(node, del);

    ft_lstdelone(NULL, del);
    ft_lstdelone(ft_lstnew(NULL), NULL);

    return (0);
}
 */
