/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:16:46 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/02/26 16:31:39 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_background(t_long *game, t_image *img, int x, int y)
{
	char	**map;
	int		s;

	s = 64;
	map = game->map;
	if (map[y][x + 1] == '1' && \
	map[y][x - 1] == '1' && map[y - 1][x] != '1' && map[y + 1][x] != '1')
		mlx_put_image_to_window(game->mlx, game->mlx_w, img->bc, x * s, y * s);
	else
		mlx_put_image_to_window(game->mlx, game->mlx_w, img->bg, x * s, y * s);
}

void	ft_draw_walls(t_long *game, t_image *img, int x, int y)
{
	char	**map;
	int		s;

	s = 64;
	map = game->map;
	if (map[y][x] == '1' && y == 0)
		mlx_put_image_to_window(game->mlx, game->mlx_w, img->wt, x * s, y * s);
	else if (map[y][x] == '1' && y == (game->win_h / 64) - 1)
		mlx_put_image_to_window(game->mlx, game->mlx_w, img->wb, x * s, y * s);
	else if (map[y][x] == '1' && x == 0)
		mlx_put_image_to_window(game->mlx, game->mlx_w, img->wl, x * s, y * s);
	else if (map[y][x] == '1' && x == (game->win_w / 64) - 1)
		mlx_put_image_to_window(game->mlx, game->mlx_w, img->wr, x * s, y * s);
	else if (map[y][x] == '1' && map[y - 1][x] != '1')
		mlx_put_image_to_window(game->mlx, game->mlx_w, img->wb, x * s, y * s);
	else if (map[y][x] == '1' && map[y + 1][x] != '1')
		mlx_put_image_to_window(game->mlx, game->mlx_w, img->wt, x * s, y * s);
	else if (map[y][x] == '1' && map[y + 1][x] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_w, img->wl, x * s, y * s);
}

void	draw_components(char c, t_long *game, int x, int y)
{
	if (c == '1')
		ft_draw_walls(game, game->img, x / 64, y / 64);
	else if (c == 'C')
	{
		game->collects++;
		mlx_put_image_to_window(game->mlx, game->mlx_w, game->img->c, x, y);
	}
	else if (c == 'P')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_w, game->img->pr, x, y);
		game->p->x = x;
		game->p->y = y;
	}
	else if (c == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->mlx_w, game->img->e, x, y);
		game->e_x = x;
		game->e_y = y;
	}
	else
		ft_draw_background(game, game->img, x / 64, y / 64);
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
