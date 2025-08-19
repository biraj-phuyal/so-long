/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 17:44:53 by biphuyal          #+#    #+#             */
/*   Updated: 2025/04/29 16:26:01 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
void	print_content(void *content)
{
	char	*str;
	// WELL JUST A COMMENT
	printf("%s\n", (char *)content);
} 
*/
/* 
void	uppercase_first(void *content)
{
	str = (char *)content;
	if (str && *str)
		str[0] = ft_toupper(str[0]);
}
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current;

	if (!f)
		return ;
	current = lst;
	while (current)
	{
		f(current->content);
		current = current->next;
	}
}
/* 
int	main(void)
{
	t_list	*list;

    list = NULL;
    ft_lstiter(list, print_content);
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("hello")));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("world")));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("test")));
    printf("Original list:\n");
    ft_lstiter(list, print_content);
    ft_lstiter(list, uppercase_first);
    printf("\nModified list:\n");
    ft_lstiter(list, print_content);
    ft_lstclear(&list, free);
    return (0);
}
*/
