/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:16:46 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/02/21 18:04:49 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_components(char c, t_long *game, int x, int y)
{
	t_image	*img;

	img = game->images;
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_win, img->w, x, y);
	else if (c == 'C')
	{
		game->collects++;
		mlx_put_image_to_window(game->mlx, game->mlx_win, img->c, x, y);
	}
	else if (c == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, img->p, x, y);
		game->player->x = x;
		game->player->y = y;
	}
	else if (c == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_win, img->ex, x, y);
		game->exit_x = x;
		game->exit_y = y;
	}
	else if (c == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win, img->bg, x, y);
}

void	ft_draw_map(t_long *game)
{
	int		x;
	int		y;
	char	**map;
	int		s;

	y = 0;
	map = game->map;
	game->collects = 0;
	s = 64;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			draw_components(map[y][x], game, (x * s), (y * s));
			x++;
		}
	y++;
	}
}
