/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:55:09 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/03/10 13:02:34 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_size(int *s)
{
	if (s[0] == s[1])
		return (0);
	return (1);
}

int	*check_all_rows_size(char **map)
{
	int	*sizes;

	sizes = ft_calloc(2, sizeof(int));
	sizes[0] = (int)ft_strlen(*map);
	sizes[1] = 0;
	while (*map)
	{
		if ((int)ft_strlen(*map) != sizes[0])
			return (0);
		map++;
		sizes[1]++;
	}
	return (sizes);
}

int	check_top_and_bottom(char *top, char *bottom)
{
	while (*top)
	{
		if (*top != '1' || *bottom != '1')
			return (0);
		top++;
		bottom++;
	}
	return (1);
}

int	check_sides(char **map, int width)
{
	int	index;

	index = 0;
	while (map[index])
	{
		if (map[index][0] != '1' || map[index][width -1] != '1')
			return (0);
		index++;
	}
	return (1);
}
