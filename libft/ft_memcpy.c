/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:31:09 by biphuyal          #+#    #+#             */
/*   Updated: 2025/04/29 15:57:26 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*d;
	const char	*s;

	if (!dest && !src)
		return (NULL);
	i = 0;
	d = (char *)dest;
	s = (const char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/* 
int main(void)
{
	char source[] = "Hello, memcpy!";
	char destination[50];  // make sure it's big enough

	// Copy the first 13 bytes (including the null terminator)
	ft_memcpy(destination, source, strlen(source) + 1);

	printf("Source:      %s\n", source);
	printf("Destination: %s\n", destination);

	return 0;
}
 */
