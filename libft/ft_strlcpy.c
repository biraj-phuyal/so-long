/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:32:50 by biphuyal          #+#    #+#             */
/*   Updated: 2025/04/29 15:57:26 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	s_len;
	size_t	i;

	s_len = 0;
	i = 0;
	while (src[s_len])
		s_len++;
	if (size == 0)
		return (s_len);
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (s_len);
}
/* 
int	main(void) {
    char dest[20] = "Hello, ";
    const char *src = "World!";
    unsigned int size = sizeof(dest);

    unsigned int result = ft_strlcpy(dest, src, size);

    printf("Resulting string: %s\n", dest);
    printf("Length of the resulting string: %u\n", result);
    
}
 */