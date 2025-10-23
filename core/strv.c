/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 11:44:19 by biphuyal          #+#    #+#             */
/*   Updated: 2025/10/23 20:36:58 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**strv_new(size_t size)
{
	char	**strv;
	size_t	i;

	strv = (char **)malloc(sizeof(char *) * (size + 1));
	if (!strv)
		return (NULL);
	i = 0;
	while (i < size)
	{
		strv[i] = NULL;
		i++;
	}
	strv[size] = NULL;
	return (strv);
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
	i = 0;
	while (strv && strv[i])
		new_strv[k++] = strv[i++];
	i = 0;
	while (str && str[i])
		new_strv[k++] = str[i++];
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