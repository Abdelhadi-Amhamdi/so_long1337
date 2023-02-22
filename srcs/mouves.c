/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouves.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:57:07 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/02/22 18:43:00 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_x(char d, t_long *game)
{
	char	c;

	if (d == 'r')
	{
		c = get_val((game->player->x + game->s), game->player->y, game);
		if (c != '1' && c != 'E')
		{
			set_val(game, (game->player->x), (game->player->y), '0');
			set_val(game, (game->player->x += game->s), (game->player->y), 'P');
		}
		else if (c == 'E' && !game->collects)
			ft_put_end_screen(game, 'w');
	}
	else
	{
		c = get_val((game->player->x - game->s), game->player->y, game);
		if (c != '1' && c != 'E')
		{
			set_val(game, (game->player->x), (game->player->y), '0');
			set_val(game, (game->player->x -= game->s), (game->player->y), 'P');
		}
		else if (c == 'E' && !game->collects)
			ft_put_end_screen(game, 'w');
	}
}

void	move_y(char d, t_long *game)
{
	char	c;

	if (d == 't')
	{
		c = get_val((game->player->x), (game->player->y - game->s), game);
		if (c != '1' && c != 'E')
		{
			set_val(game, (game->player->x), (game->player->y), '0');
			set_val(game, (game->player->x), (game->player->y -= game->s), 'P');
		}
		else if (c == 'E' && !game->collects)
			ft_put_end_screen(game, 'w');
	}
	else
	{
		c = get_val(game->player->x, (game->player->y + game->s), game);
		if (c != '1' && c != 'E')
		{
			set_val(game, (game->player->x), (game->player->y), '0');
			set_val(game, (game->player->x), (game->player->y += game->s), 'P');
		}
		else if (c == 'E' && !game->collects)
			ft_put_end_screen(game, 'w');
	}
}

int	move_player(int keycode, t_long *game)
{
	game->s = 64;
	if (keycode == 124)
		move_x('r', game);
	else if (keycode == 123)
		move_x('l', game);
	else if (keycode == 126)
		move_y('t', game);
	else if (keycode == 125)
		move_y('b', game);
	ft_draw_map(game);
	if (!game->collects)
		mlx_put_image_to_window(game->mlx, game->mlx_win, \
		game->images->eo, game->exit_x, game->exit_y);
	return (1);
}

void	ft_calc_sizes(int *w, int *h, t_long *game)
{
	if (game->win_w >= 849 && game->win_h >= 512)
	{
		*w = 849;
		*h = 512;
	}
	else if (game->win_w >= 664 && game->win_h >= 320)
	{
		*w = 664;
		*h = 320;
	}
	else
	{
		*w = 375;
		*h = 192;
	}
}

void	ft_put_end_screen(t_long *game, char type)
{
	int		w ;
	int		h ;
	void	*img;

	ft_calc_sizes(&w, &h, game);
	if (type == 'w')
	{
		printf("you win !!!. %d %d\n", game->win_h, game->win_w);
	}
	img = mlx_xpm_file_to_image(game->mlx, "images/end/win-md.xpm", &w, &h);
	mlx_clear_window(game->mlx, game->mlx_win);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img, \
	((game->win_w / 2) - w / 2), ((game->win_h / 2) - h / 2));
}
