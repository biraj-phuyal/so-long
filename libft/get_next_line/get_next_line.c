/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_single.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: biphuyal <biphuyal@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 15:30:00 by biphuyal          #+#    #+#             */
/*   Updated: 2025/08/04 15:26:06 by biphuyal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 10

int	ft_strlen(const char *s)
{
	int	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*dup;

	if (!s)
		return (NULL);
	dup = malloc(sizeof(char) * (n + 1));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n && s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_strjoin(char *str, char *dup)
{
	size_t	i;
	size_t	j;
	char	*new_str;

	if (!dup)
		return (NULL);
	if (!str)
		return (ft_strndup(dup, ft_strlen(dup)));
	new_str = malloc(sizeof(char) * (ft_strlen(str) + ft_strlen(dup) + 1));
	if (!new_str)
		return (NULL);
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	j = 0;
	while (dup[j])
		new_str[i++] = dup[j++];
	new_str[i] = '\0';
	free(str);
	return (new_str);
}

void	move_buffer(char *buff, char **str)
{
	size_t	i;
	size_t	j;
	char	*new;
	char	*temp;

	i = 0;
	j = 0;
	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	new = ft_strndup(buff, i);
	if (!new)
		return ;
	while (buff[i])
		buff[j++] = buff[i++];
	buff[j] = '\0';
	temp = *str;
	*str = ft_strjoin(temp, new);
	free(new);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	buff[BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = NULL;
	while (1)
	{
		if (buff[0] == '\0')
		{
			bytes_read = read(fd, buff, BUFFER_SIZE);
			if (bytes_read == 0)
				return (str);
			if (bytes_read == -1)
				return (free(str), NULL);
			buff[bytes_read] = '\0';
		}
		move_buffer(buff, &str);
		if (str && str[ft_strlen(str) - 1] == '\n')
			return (str);
	}
}
