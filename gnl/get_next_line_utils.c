/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:48:57 by aamhamdi          #+#    #+#             */
/*   Updated: 2022/11/03 20:08:06 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *src)
{
	size_t	index;

	index = 0;
	while (src[index])
		index++;
	return (index);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(src);
	if (len == 0)
		return (size);
	while (src[i] && i < len - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (size);
}

int	ft_search(const char *data)
{
	int	index;

	index = 0;
	while (data[index])
	{
		if (data[index] == '\n')
			return (index);
		index++;
	}
	return (-1);
}

char	*ft_strdup(const char *string)
{
	size_t	size;
	char	*p;

	if (!string)
		return (NULL);
	size = ft_strlen(string) + 1;
	p = malloc(size * sizeof(char));
	if (!p)
		return (NULL);
	ft_strlcpy(p, string, size);
	return (p);
}

char	*ft_join(char *data, const char *buffer)
{
	char	*new_data;
	size_t	s1_s;
	size_t	s2_s;

	if (!data)
		data = ft_strdup("");
	s1_s = ft_strlen(data);
	s2_s = ft_strlen(buffer);
	new_data = malloc((s1_s + s2_s + 1) * sizeof(char));
	if (!new_data)
		return (NULL);
	ft_strlcpy(new_data, data, s1_s + 1);
	ft_strlcpy(new_data + s1_s, buffer, s2_s + 1);
	free(data);
	return (new_data);
}
