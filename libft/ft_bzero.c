/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:36:36 by biphuyal          #+#    #+#             */
/*   Updated: 2025/04/29 15:57:26 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*a;

	i = 0;
	a = (unsigned char *)s;
	while (i < n)
	{
		a[i] = 0;
		i++;
	}
}
/* 
int	main(void)
{
	char	str1[10];
	char	str2[10];

    str1[10] = "Hello";
    str2[10] = "World";
    
    printf("Before ft_bzero:\n");
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    
    ft_bzero(str1, sizeof(str1));
    ft_bzero(str2, 3);
    
    printf("\nAfter ft_bzero:\n");
    printf("str1: %s (all zeroed)\n", str1);
    printf("str2: %s (first 3 bytes zeroed)\n", str2);
    
    printf("\nstr1 bytes (as numbers): ");
    for (size_t i = 0; i < 5; i++) {
        printf("%d ", str1[i]);
    }
    printf("\n");
    
    return (0);
}
*/
