/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:33:38 by biphuyal          #+#    #+#             */
/*   Updated: 2025/04/29 15:57:47 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (const char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
/* 
int	main(void)
{
    int c = 'a';
    char *str = "HHssafsas";
    char *s = ft_strrchr(str, c);
    printf("Last occurrence of %c in %s at %d" , c, str, s - str);
} */