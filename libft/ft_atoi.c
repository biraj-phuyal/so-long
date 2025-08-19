/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 18:36:30 by biphuyal          #+#    #+#             */
/*   Updated: 2025/04/29 15:57:47 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;
	int	sign_count;

	result = 0;
	sign = 1;
	sign_count = 0;
	while ((*nptr == 32) || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	while (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
		sign_count++;
		if (sign_count > 1)
			return (0);
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = (result * 10) + (*nptr - '0');
		nptr++;
	}
	return (result * sign);
}
/* 
int	main(void)
{
    char *str = "123";
    printf("%d",ft_atoi(str));
} */