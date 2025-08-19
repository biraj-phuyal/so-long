/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 13:12:27 by biphuyal          #+#    #+#             */
/*   Updated: 2025/04/29 15:58:23 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
void	to_uppercase(unsigned int i, char *c)
{
    (void)i;
    *c = ft_toupper(*c);
}
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	j;

	j = 0;
	if (!s || !f)
		return ;
	while (s[j])
	{
		f(j, &s[j]);
		j++;
	}
}
/* 
int	main(void)
{
	char	str[];

    str[] = "hello world!";
    
    printf("Before: %s\n", str);
    ft_striteri(str, to_uppercase);
    printf("After:  %s\n", str);
    return (0);
}
 */
