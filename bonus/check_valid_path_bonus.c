/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:23:36 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/03/10 12:55:24 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**ft_tab_dup(char **tab)
{
	char	**dup;
	int		index;

	index = 0;
	dup = malloc(sizeof(char *) * (ft_strtablen(tab) + 1));
	if (!dup)
		return (0);
	while (tab[index])
	{
		dup[index] = ft_strdup(tab[index]);
		index++;
	}
	dup[index] = NULL;
	return (dup);
}

void	fill_all_paths(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == '*' || map[y][x] == 'M')
		return ;
	map[y][x] = '*';
	fill_all_paths(map, x + 1, y);
	fill_all_paths(map, x - 1, y);
	fill_all_paths(map, x, y + 1);
	fill_all_paths(map, x, y - 1);
}

int	check_all_coins_and_exit_access(char **map)
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

void	ft_free(char **tabs)
{
	int	index;

	if (!tabs)
		return ;
	index = 0;
	while (tabs[index])
	{
		free(tabs[index]);
		tabs[index] = NULL;
		index++;
	}
	free(tabs);
	tabs = NULL;
}

int	check_for_valid_path(t_long *game)
{
	char	**dup_map;

	get_player_position(game);
	dup_map = ft_tab_dup(game->map);
	if (!dup_map)
	{
		ft_free(game->map);
		free(game->p);
		return (0);
	}
	fill_all_paths(dup_map, game->p->x, game->p->y);
	if (!check_all_coins_and_exit_access(dup_map))
	{
		ft_free(game->map);
		free(game->p);
		ft_free(dup_map);
		return (0);
	}
	ft_free(dup_map);
	return (1);
}
