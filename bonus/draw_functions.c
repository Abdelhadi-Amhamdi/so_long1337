/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:32:18 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/03/10 12:17:25 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_draw_background(t_long *game, t_image *img, int x, int y)
{
	char	**map;
	int		s;

	s = img->size;
	map = game->map;
	if (map[y][x] == '0' && map[y][x + 1] == '1' && \
	map[y][x - 1] == '1' && map[y - 1][x] != '1' && map[y + 1][x] != '1')
		mlx_put_image_to_window(game->mlx, game->mlx_w, img->bc, x * s, y * s);
	else if (map[y][x] == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_w, img->bg, x * s, y * s);
}

void	ft_draw_player(t_long *game, t_image *img, int x, int y)
{
	int	s;

	s = img->size;
	mlx_put_image_to_window(game->mlx, game->mlx_w, img->pr, x * s, y * s);
	game->p->x = x * s;
	game->p->y = y * s;
}

void	ft_draw_coins(t_long *game, t_image *img, int x, int y)
{
	int	s;

	s = img->size;
	game->collects_n++;
	mlx_put_image_to_window(game->mlx, game->mlx_w, \
	game->c_img->c1, x * s, y * s);
	create_item(x * game->img->size, y * game->img->size, &game->coins);
}

void	ft_draw_monster(t_long *game, t_image *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_w, \
	game->m_img->mr1, (x * img->size), (y * img->size));
	create_item(x * game->img->size, y * game->img->size, &game->monsters);
}

void	ft_draw_walls(t_long *game, t_image *img, int x, int y)
{
	char	**map;
	int		s;

	s = img->size;
	map = game->map;
	if (map[y][x] == '1' && y == 0)
		mlx_put_image_to_window(game->mlx, game->mlx_w, img->wt, x * s, y * s);
	else if (map[y][x] == '1' && y == (game->w_h / 64) - 1)
		mlx_put_image_to_window(game->mlx, game->mlx_w, img->wb, x * s, y * s);
	else if (map[y][x] == '1' && x == 0)
		mlx_put_image_to_window(game->mlx, game->mlx_w, img->wl, x * s, y * s);
	else if (map[y][x] == '1' && x == (game->w_w / 64) - 1)
		mlx_put_image_to_window(game->mlx, game->mlx_w, img->wr, x * s, y * s);
	else if (map[y][x] == '1' && map[y - 1][x] != '1')
		mlx_put_image_to_window(game->mlx, game->mlx_w, img->wb, x * s, y * s);
	else if (map[y][x] == '1' && map[y + 1][x] != '1')
		mlx_put_image_to_window(game->mlx, game->mlx_w, img->wt, x * s, y * s);
	else if (map[y][x] == '1' && map[y + 1][x] == '1')
		mlx_put_image_to_window(game->mlx, game->mlx_w, img->wl, x * s, y * s);
}
