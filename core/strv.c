/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:44:19 by biphuyal          #+#    #+#             */
/*   Updated: 2025/11/06 16:13:35 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**strv_new(size_t size)
{
	return (ft_calloc(sizeof(char *), size + 1));
}

static void	copy_strv_elements(char **dest, char **src, size_t *k)
{
	size_t	i;

	i = 0;
	while (src && src[i])
	{
		dest[*k] = src[i];
		(*k)++;
		i++;
	}
}

char	**strv_join(char **strv, char **str)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**new_strv;

	i = 0;
	j = 0;
	if (strv)
		while (strv[i])
			i++;
	while (str && str[j])
		j++;
	new_strv = strv_new(i + j);
	if (!new_strv)
		return (NULL);
	k = 0;
	copy_strv_elements(new_strv, strv, &k);
	copy_strv_elements(new_strv, str, &k);
	if (strv)
		free(strv);
	return (new_strv);
}

void	strv_free(char **strv)
{
	size_t	i;

	if (!strv)
		return ;
	i = 0;
	while (strv[i])
	{
		free(strv[i]);
		i++;
	}
	free(strv);
}

size_t	strv_len(char **strv)
{
	size_t	i;

	if (!strv)
		return (0);
	i = 0;
	while (strv[i])
		i++;
	return (i);
}
