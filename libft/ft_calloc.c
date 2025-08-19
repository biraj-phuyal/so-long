/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:36:45 by biphuyal          #+#    #+#             */
/*   Updated: 2025/04/29 16:11:16 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			total_size;
	void			*ptr;
	unsigned char	*byte_ptr;
	size_t			i;

	total_size = nmemb * size;
	if (nmemb != 0 && size != total_size / nmemb)
		return (NULL);
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	byte_ptr = (unsigned char *)ptr;
	i = 0;
	while (i < total_size)
	{
		byte_ptr[i] = 0;
		i++;
	}
	return (ptr);
}

/* 
int	main(void)
{
	size_t	i;
	size_t	size;
	int		*ptr;

    i = 1;
    size = 5;
    ptr = (int *)ft_calloc(i, size);
    if (ptr != NULL) {
        printf("Memory allocated successfully. Address: %p\n", (void *)ptr);
        free(ptr);
    } else {
        printf("Memory allocation failed.\n");
    }
    return (0);
}
 */