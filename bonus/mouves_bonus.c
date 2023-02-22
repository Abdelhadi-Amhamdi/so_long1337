/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouves_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:57:07 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/02/22 20:59:06 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long_bonus.h"

char get_val(int x, int y, t_long *game)
{
	if(x < 0 || y < 0)
		return 0;
	return (game->map[y / 64][x / 64]);
}

void set_val(t_long *game, int x, int y, char c)
{
	game->map[y / 64][x / 64] = c;
}
t_item *get_item(int x, int y, t_long *game)
{
	t_item *tmp;

	tmp = game->coins;
	while(tmp)
	{
		if(tmp->item_x == x && tmp->item_y == y)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
int  move_player(int keycode, t_long *game)
{
	char c;
	t_image images;
	static int collects;
	t_item *item;
	void *win_img;
	int width;
	int height;

	ft_init_images(game, &images);
	if(keycode == 124)
	{
		c = get_val((game->player->player_x + 64), game->player->player_y, game);
		if( c == '0' || c == 'C')
		{
			if(c == 'C')
			{
				item = get_item(game->player->player_x + 64 , game->player->player_y, game);
				item->direction = 'b';
				if(++collects == game->collects_n)
					mlx_put_image_to_window(game->mlx, game->mlx_w, images.oe, game->exit_x, game->exit_y);
			}
			set_val(game, (game->player->player_x), (game->player->player_y), '0');
			mlx_put_image_to_window(game->mlx, game->mlx_w, images.bg, (game->player->player_x), (game->player->player_y));
			game->player->player_x += 64;
			set_val(game, (game->player->player_x), (game->player->player_y), 'P');
			mlx_put_image_to_window(game->mlx, game->mlx_w, images.pr, game->player->player_x, game->player->player_y);
		}
	}
	else if(keycode == 123)
	{
		c = get_val((game->player->player_x - 64), game->player->player_y, game);
		if( c == '0' || c == 'C')
		{
			if(c == 'C')
			{
				item = get_item(game->player->player_x - 64 , game->player->player_y, game);
				item->direction = 'b';
				if(++collects == game->collects_n)
					mlx_put_image_to_window(game->mlx, game->mlx_w, images.oe, game->exit_x, game->exit_y);
			}
			set_val(game, (game->player->player_x), (game->player->player_y), '0');
			mlx_put_image_to_window(game->mlx, game->mlx_w, images.bg, (game->player->player_x), (game->player->player_y));
			game->player->player_x -= 64;
			set_val(game, (game->player->player_x), (game->player->player_y), 'P');
			mlx_put_image_to_window(game->mlx, game->mlx_w, images.pl, game->player->player_x, game->player->player_y);
		}
	}
	else if(keycode == 126)
	{
		c = get_val((game->player->player_x), (game->player->player_y - 64), game);
		if(c == '0' || c == 'C')
		{
			if(c == 'C')
			{
				item = get_item(game->player->player_x , game->player->player_y - 64, game);
				item->direction = 'b';
				if(++collects == game->collects_n)
					mlx_put_image_to_window(game->mlx, game->mlx_w, images.oe, game->exit_x, game->exit_y);
			}
			set_val(game, (game->player->player_x), (game->player->player_y), '0');
			if(game->map[game->player->player_y / 64][(game->player->player_x / 64) + 1] == '1' && game->map[game->player->player_y / 64][(game->player->player_x - 1) / 64] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_w, images.bc, (game->player->player_x), (game->player->player_y));
			else
				mlx_put_image_to_window(game->mlx, game->mlx_w, images.bg, (game->player->player_x), (game->player->player_y));
				
			game->player->player_y -= 64;
			set_val(game, (game->player->player_x), (game->player->player_y), 'P');
			if(game->map[game->player->player_y / 64][(game->player->player_x / 64) + 1] == '1' && game->map[game->player->player_y / 64][(game->player->player_x - 1) / 64] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_w, images.pc, game->player->player_x, game->player->player_y);
			else
				mlx_put_image_to_window(game->mlx, game->mlx_w, images.p, game->player->player_x, game->player->player_y);
		}
	}
	else if(keycode == 125)
	{
		c = get_val(game->player->player_x, (game->player->player_y + 64), game);
		if(c == '0' || c == 'C')
		{
			if(c == 'C')
			{
				item = get_item(game->player->player_x , game->player->player_y + 64, game);
				item->direction = 'b';
				if(++collects == game->collects_n)
					mlx_put_image_to_window(game->mlx, game->mlx_w, images.oe, game->exit_x, game->exit_y);
			}
			set_val(game, (game->player->player_x), (game->player->player_y), '0');
			if(game->map[game->player->player_y / 64][(game->player->player_x / 64) + 1] == '1' && game->map[game->player->player_y / 64][(game->player->player_x - 1) / 64] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_w, images.bc, (game->player->player_x), (game->player->player_y));
			else
				mlx_put_image_to_window(game->mlx, game->mlx_w, images.bg, (game->player->player_x), (game->player->player_y));
				
			game->player->player_y += 64;
			set_val(game, (game->player->player_x), (game->player->player_y), 'P');
			if(game->map[game->player->player_y / 64][(game->player->player_x / 64) + 1] == '1' && game->map[game->player->player_y / 64][(game->player->player_x - 1) / 64] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_w, images.pc, game->player->player_x, game->player->player_y);
			else
				mlx_put_image_to_window(game->mlx, game->mlx_w, images.p, game->player->player_x, game->player->player_y);
		}
		else if(c == 'E' && collects == game->collects_n)
			ft_put_end_screen(game, 'E');
		else if(c == 'M')
			ft_put_end_screen(game, 'M');
	}
	return 1;
}

void ft_calc_sizes(int *w, int *h, t_long *game)
{
	if (game->window_width >= 849 && game->window_heigth >= 512)
	{
		*w = 849;
		*h = 512;
	}
	else if(game->window_width >= 664 && game->window_heigth >= 320)
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

void ft_put_end_screen(t_long *game, char type)
{
	int width;
	int height;
	void *win_img;
	t_item *monsters;

	monsters = game->monsters;
	
	ft_calc_sizes(&width, &height, game);
	if(type == 'E')
	{
		win_img = mlx_xpm_file_to_image(game->mlx, "images/end/win-lg.xpm", &width , &height);
		printf("you win !!!.\n");
	}
	else
	{
		win_img = mlx_xpm_file_to_image(game->mlx, "images/end/over-lg.xpm", &width , &height);
		printf("you die !!!.\n");
	}

	while(monsters)
	{
		monsters->direction = 'a';
		monsters = monsters->next;
	}
	// mlx_clear_window(game->mlx, game->mlx_w);
	mlx_put_image_to_window(game->mlx, game->mlx_w, win_img, ((game->window_width / 2) - width / 2)  , ((game->window_heigth / 2) - height / 2));
}
