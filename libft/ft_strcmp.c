/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:33:04 by biphuyal          #+#    #+#             */
/*   Updated: 2025/11/08 23:33:29 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s2[i] && s1[i])
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/* 
int	main(void)
{
    char *str = "LOLOLOL";
    const char *dest = "LOK";
    int s = ft_strcmp(dest, str);
    //printf("Last occurrence of %c in %s at %d" , dest, str, s - str);
} */