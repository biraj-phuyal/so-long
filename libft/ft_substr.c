/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:33:52 by biphuyal          #+#    #+#             */
/*   Updated: 2025/04/29 15:57:54 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	size_t	str_len;
	char	*string;

	if (!s)
		return (NULL);
	str_len = ft_strlen(s);
	if (start >= str_len)
		return (ft_strdup(""));
	if (len > str_len - start)
		len = str_len - start;
	string = (char *)malloc(len + 1);
	if (!string)
		return (NULL);
	j = 0;
	while (j < len && s[start + j])
	{
		string[j] = s[start + j];
		j++;
	}
	string[j] = '\0';
	return (string);
}

/* 
int	main(int argc, char **argv)
{
	const char	*s;

    s = "HHHH";
    printf(ft_substr(*s, 2, 3));
}
*/