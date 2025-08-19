/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 18:37:54 by biphuyal          #+#    #+#             */
/*   Updated: 2025/04/13 20:16:29 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* 
void	*my_map_func(void *content)
{
	char *str = (char *)content;
	return ft_strdup(str); 
}

void	my_del_func(void *content)
{
	free(content);
}
 */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*new;
	void	*content;

	new = NULL;
	while (lst)
	{
		content = f(lst->content);
		if (!content)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		node = ft_lstnew(content);
		if (!node)
		{
			del(content);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, node);
		lst = lst->next;
	}
	return (new);
}
/* 
int	main(void)
{
	t_list *original = ft_lstnew(strdup("one"));
	ft_lstadd_back(&original, ft_lstnew(strdup("two")));
	ft_lstadd_back(&original, ft_lstnew(strdup("three")));

	t_list *mapped = ft_lstmap(original, my_map_func, my_del_func);

	t_list *temp = mapped;
	while (temp)
	{
		printf("%s\n", (char *)temp->content);
		temp = temp->next;
	}

	ft_lstclear(&original, my_del_func);
	ft_lstclear(&mapped, my_del_func);

	return 0;
}
  */
