/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:06:36 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/27 17:44:05 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include <mlx.h>

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

void calc_size(to_long *game, t_list *map)
{
    game->width = ((ft_strlen((char *)map->content) - 1) * 50);
    game->heigth = ((ft_lstsize(map)) * 50);
}

void ft_init_images(to_long *game, t_images *images)
{
    int width;
    int height;

    width = 50;
    height = 50;
    images->background_image = mlx_xpm_file_to_image(game->mlx, "images/background.xpm", &width, &height);
    images->wall_image = mlx_xpm_file_to_image(game->mlx, "images/wall.xpm", &width, &height);
    images->player_image = mlx_xpm_file_to_image(game->mlx, "images/player.xpm", &width, &height);
    images->coins_image = mlx_xpm_file_to_image(game->mlx, "images/coin.xpm", &width, &height);
    images->exit_image = mlx_xpm_file_to_image(game->mlx, "images/exit.xpm", &width, &height);
    images->monster_image = mlx_xpm_file_to_image(game->mlx, "images/monster.xpm", &width, &height);
}

int	ft_close(int keycode, to_long *game, t_images *images)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
    // mlx_destroy_image(game->mlx, images->player_image);
    return (0);
}

void animate_monsters(to_long *game)
{
    void *background_img;
    void *monster_img;
    int width = 50;
    char c;

    background_img = mlx_xpm_file_to_image(game, "images/background.xpm", &width, &width);
    monster_img = mlx_xpm_file_to_image(game, "images/monster.xpm", &width, &width);
    // find_all_monsters_position(game->map);
    while(1)
    {
        c = get_val((game->p_x + 50), game->p_y, game);
        if( c != '1')
        {
            mlx_put_image_to_window(game->mlx, game->mlx_win, background_img, (game->p_x), (game->p_y));
            game->p_x += 50;
            mlx_put_image_to_window(game->mlx, game->mlx_win, monster_img, game->p_x, game->p_y);
        }
        else
        {
            mlx_put_image_to_window(game->mlx, game->mlx_win, background_img, (game->p_x), (game->p_y));
            game->p_x += 50;
            mlx_put_image_to_window(game->mlx, game->mlx_win, monster_img, game->p_x, game->p_y);
        }
    }
}


int main()
{

    struct so_long game;
    t_images images;
    

    game.map = read_map("map");
    if(!game.map)
        return (0);
        
    calc_size(&game, game.map);
    game.mlx = mlx_init();
    game.mlx_win = mlx_new_window(game.mlx, game.width, game.heigth, "soooo_loooong!");
    ft_init_images(&game, &images);
    ft_draw_map(&game, &images, game.map);
    // mlx_hook(game.mlx_win, 2, 1L<<0, ft_close, &game);
    mlx_hook(game.mlx_win, 2, (1L << 0), move_player, &game);
    // animate_monsters(&game);
    mlx_loop(game.mlx);
    return (0);
}