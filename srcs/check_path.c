/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:45:41 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/03/06 12:04:55 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_tabdup(char **map)
{
	int		size;
	int		index;
	char	**dup;

	index = 0;
	size = ft_str_tablen(map);
	dup = (char **)malloc(sizeof(char *) * (size + 1));
	if (!dup)
		return (0);
	while (index < size)
	{
		dup[index] = ft_strdup(map[index]);
		if (!dup[index])
			return (0);
		index++;
	}
	dup[index] = NULL;
	return (dup);
}

int	check_access_to_coins_and_player(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

void	check_path(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == '*')
		return ;
	map[y][x] = '*';
	check_path(map, x + 1, y);
	check_path(map, x - 1, y);
	check_path(map, x, y + 1);
	check_path(map, x, y - 1);
}

void	ft_free(char **data)
{
	int	index;

	if (!data)
		return ;
	index = 0;
	while (data[index])
	{
		free(data[index]);
		data[index] = NULL;
		index++;
	}
	free(data);
	data = NULL;
}

int	check_valid_path(t_long *game)
{
	char	**dup_map;

	dup_map = ft_tabdup(game->map);
	if (!dup_map)
		return (0);
	check_path(dup_map, game->p->x / 64, game->p->y / 64);
	if (!check_access_to_coins_and_player(dup_map))
		return (ft_free(dup_map), 0);
	return (ft_free(dup_map), 1);
}
