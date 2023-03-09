/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utills.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:23:05 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/03/09 15:23:30 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_str_tablen(char **tabs)
{
	int	i;

	i = 0;
	while (tabs[i])
		i++;
	return (i);
}

void	calc_window_size(t_long *game)
{
	game->win_w = (ft_strlen(game->map[0]) * 64);
	game->win_h = (ft_str_tablen(game->map) * 64);
}

char	get_val(int x, int y, t_long *game)
{
	if (x < 0 || y < 0)
		return (0);
	return (game->map[y / 64][x / 64]);
}

void	set_val(t_long *game, int x, int y, char c)
{
	game->map[y / 64][x / 64] = c;
}

void	get_player_position(t_long *game)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	map = game->map;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				game->p->x = x * 64;
				game->p->y = y * 64;
				return ;
			}
			x++;
		}
		y++;
	}
}
