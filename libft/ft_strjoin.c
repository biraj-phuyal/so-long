/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:36:10 by biphuyal          #+#    #+#             */
/*   Updated: 2025/08/19 11:08:33 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	int		total_length;
	char	*string;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	j = 0;
	total_length = ft_strlen(s1) + ft_strlen(s2);
	string = (char *)malloc(total_length + 1);
	if (!string)
		return (NULL);
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	while (s2[j])
		string[i++] = s2[j++];
	string[i] = '\0';
	free(s1);
	return (string);
}
/* 
int	main(void) {
    const char *dest = "Hello, ";
    const char *src = "World!";

    printf("%s", ft_strjoin(dest, src));
}
 */
