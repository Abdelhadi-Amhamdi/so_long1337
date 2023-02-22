/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:34:09 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/02/22 21:47:28 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void ft_init_monster_images(t_monster_imgs *img)
{
	int	width;
	
	width = 64;
	img->mr1 = mlx_xpm_file_to_image(game->mlx, "images/ms/mr1.xpm", &width, &width);;
	img->mr2 = mlx_xpm_file_to_image(game->mlx, "images/ms/mr2.xpm", &width, &width);
	img->mr3 = mlx_xpm_file_to_image(game->mlx, "images/ms/mr3.xpm", &width, &width);
	img->ml1 = mlx_xpm_file_to_image(game->mlx, "images/ms/ml1.xpm", &width, &width);
	img->ml2 = mlx_xpm_file_to_image(game->mlx, "images/ms/ml2.xpm", &width, &width);
	img->ml3 = mlx_xpm_file_to_image(game->mlx, "images/ms/ml3.xpm", &width, &width);
}

void ft_init_coins_img(t_coin_imgs *img)
{
	img->c1 = mlx_xpm_file_to_image(game->mlx, "images/css/cs1.xpm", &width, &width); 
	img->c2 = mlx_xpm_file_to_image(game->mlx, "images/css/cs2.xpm", &width, &width); 
	img->c3 = mlx_xpm_file_to_image(game->mlx, "images/css/cs3.xpm", &width, &width); 
	img->c4 = mlx_xpm_file_to_image(game->mlx, "images/css/cs4.xpm", &width, &width); 
	img->c5 = mlx_xpm_file_to_image(game->mlx, "images/css/cs5.xpm", &width, &width); 
	img->c6 = mlx_xpm_file_to_image(game->mlx, "images/css/cs6.xpm", &width, &width); 
}

int	animate_monsters(t_long *game)
{
	static int	i;
	static int	j ;
	static int	k;
	t_monster_imgs *m_img;
	t_coin_imgs *c_img;
	t_item *monsters = game->monsters;

	ft_init_monster_images(m_img);
	ft_init_coins_images(c_img);
	
	
	k = 0;
	void *bg = mlx_xpm_file_to_image(game->mlx, "images/bg1.xpm" , &width, &width);

	while(monsters)
	{
		if(i % 300 == 0)
		{
			if(monsters->direction == 'r')
			{
				if(k == 0)
					mlx_put_image_to_window(game->mlx, game->mlx_w, mr2, monsters->item_x, monsters->item_y);
				else if (k == 1)
					mlx_put_image_to_window(game->mlx, game->mlx_w, mr3, monsters->item_x, monsters->item_y);
				else if (k == 2)
					mlx_put_image_to_window(game->mlx, game->mlx_w, mr1, monsters->item_x, monsters->item_y);
			}
			else if(monsters->direction == 'l')
			{
				if (k == 0)
					mlx_put_image_to_window(game->mlx, game->mlx_w, ml1, monsters->item_x, monsters->item_y);
				else if (k == 1)
					mlx_put_image_to_window(game->mlx, game->mlx_w, ml2, monsters->item_x, monsters->item_y);
				else if (k == 2)
					mlx_put_image_to_window(game->mlx, game->mlx_w, ml3, monsters->item_x, monsters->item_y);
			}
		}
		if(i % 800 == 0)
		{
			if(monsters->direction == 'r')
			{
				if(get_val(monsters->item_x + 64 , monsters->item_y, game) == 'P')
				{
					printf("you lose !!!.\n");
					exit(0);
				}
				set_val(game, (monsters->item_x), (monsters->item_y), '0');
				mlx_put_image_to_window(game->mlx, game->mlx_w, bg , (monsters->item_x), (monsters->item_y));
				monsters->item_x += 64;
				set_val(game, (monsters->item_x), (monsters->item_y), 'M');
				mlx_put_image_to_window(game->mlx, game->mlx_w, m_img->mr2, monsters->item_x, monsters->item_y);
				if(get_val(monsters->item_x + 64 , monsters->item_y, game) == '1')
					monsters->direction = 'l';
			}
			else if(monsters->direction == 'l')
			{
				if(get_val(monsters->item_x - 64 , monsters->item_y, game) == 'P')
				{
					printf("you lose !!!.\n");
					exit(0);
				}
				set_val(game, (monsters->item_x), (monsters->item_y), '0');
				mlx_put_image_to_window(game->mlx, game->mlx_w, bg, (monsters->item_x), (monsters->item_y));
				monsters->item_x -= 64;
				set_val(game, (monsters->item_x), (monsters->item_y), 'M');
				mlx_put_image_to_window(game->mlx, game->mlx_w, m_img->ml1, monsters->item_x, monsters->item_y);
				if(get_val(monsters->item_x - 64 , monsters->item_y, game) == '1')
					monsters->direction = 'r';
			}
		}
		k++;
		if(k == 3)
			k = 0;
		monsters = monsters->next;
	}
	
	
	t_item *coins;

	coins = game->coins;
	while (coins && (i % 150 == 0))
	{
		if(coins->direction == 'r')
		{
			if(j == 0)
				mlx_put_image_to_window(game->mlx, game->mlx_w, coin2, coins->item_x, coins->item_y);
			else if (j == 1)
				mlx_put_image_to_window(game->mlx, game->mlx_w, coin3, coins->item_x, coins->item_y);
			else if (j == 2)
				mlx_put_image_to_window(game->mlx, game->mlx_w, coin4, coins->item_x, coins->item_y);
			else if (j == 3)
				mlx_put_image_to_window(game->mlx, game->mlx_w, coin5, coins->item_x, coins->item_y);
			else if (j == 4)
				mlx_put_image_to_window(game->mlx, game->mlx_w, coin6, coins->item_x, coins->item_y);
			else if (j == 5)
				mlx_put_image_to_window(game->mlx, game->mlx_w, coin1, coins->item_x, coins->item_y);
		}
		if(j == 6)
			j = 0;
		j++;
		coins = coins->next;
	}
	i++;
	return (0);
}


int main(int ac, char **av)
{

	t_long game;
	t_image images;
	game.player = malloc(sizeof(t_player));
	if(!game.player)
		return (0);
	game.player->player_x = 0;
	game.player->player_y = 0;

	game.map = read_map(av[1]);
	if(!game.map)
		return (0);
	calc_size(&game);
	game.mlx = mlx_init();
	game.mlx_w = mlx_new_window(game.mlx, game.window_width, game.window_heigth, "soooo_loooong!");
	ft_init_images(&game, &images);
	ft_draw_map(&game, &images);
	mlx_hook(game.mlx_w, 2, (1L << 0), move_player, &game);
	mlx_loop_hook(game.mlx, animate_monsters, &game);
	mlx_loop(game.mlx);
	return (0);
}