/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:36:17 by biphuyal          #+#    #+#             */
/*   Updated: 2025/04/29 15:57:54 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_len(long n)
{
	int	len;

	len = (n <= 0);
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	fill_str(char *str, long nb, int len)
{
	if (nb == 0)
		str[0] = '0';
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb != 0)
	{
		str[--len] = '0' + (nb % 10);
		nb /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		len;

	nb = n;
	len = get_len(nb);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	fill_str(str, nb, len);
	return (str);
}
/* 
int	main(void)
{
	//printf("%d", get_len(100000));
	printf("INT MAX -> %s\n", ft_itoa(2147483647));
	printf("ZARO -> %s\n", ft_itoa(0));
	printf("INT MIN -> %s\n", ft_itoa(-2147483648));
}
 */
