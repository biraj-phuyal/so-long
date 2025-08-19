/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:32:43 by biphuyal          #+#    #+#             */
/*   Updated: 2025/04/13 14:22:27 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s_len;
	size_t	d_len;
	size_t	i;

	s_len = ft_strlen(src);
	i = 0;
	d_len = 0;
	if (dst)
	{
		while (d_len < size && dst[d_len])
			d_len++;
	}
	if (d_len >= size)
		return (size + s_len);
	while (d_len + i + 1 < size && src[i])
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (s_len + d_len);
}
/* 
int	main(void) {
    char dest[20] = "Hello, ";
    const char *src = "World!";
    unsigned int size = sizeof(dest);

    unsigned int result = ft_strlcat(dest, src, size);

    printf("Resulting string: %s\n", dest);
    printf("Length of the resulting string: %u\n", result);
    
}
 */
