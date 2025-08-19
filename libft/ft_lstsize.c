/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:34:44 by biphuyal          #+#    #+#             */
/*   Updated: 2025/04/13 13:42:16 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*current;
	int		counter;

	current = lst;
	counter = 0;
	while (current)
	{
		current = current->next;
		counter++;
	}
	return (counter);
}
/* 
int	main(void)
{
    t_list *head = NULL;
    printf("Size of empty list: %d\n", ft_lstsize(head)); 
    
    t_list node1;
    node1.content = "First node";
    node1.next = NULL;
    head = &node1;
    
    printf("Size after 1 node: %d\n", ft_lstsize(head)); 
    
    t_list node2;
    node2.content = "Second node";
    node2.next = NULL;
    node1.next = &node2;
    
    printf("Size after 2 nodes: %d\n", ft_lstsize(head)); 

    return (0);
} 
*/
