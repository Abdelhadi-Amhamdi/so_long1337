/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:06:36 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/02/06 09:25:01 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include <mlx.h>

int ft_strtablen(char **tabs)
{
    int i;
    
    i  = 0;
    while(tabs[i])
        i++;
    return i;
}

void calc_size(to_long *game)
{
    game->window_width = (ft_strlen(game->map[0]) * 64);
    game->window_heigth = (ft_strtablen(game->map) * 64);
}

void ft_init_images(to_long *game, t_images *images)
{
    int size = images->size = 64;

    images->background_image = mlx_xpm_file_to_image(game->mlx, "images/64-img/background64.xpm", &size, &size);
    images->wall_image = mlx_xpm_file_to_image(game->mlx, "images/wall-1-64.xpm", &size, &size);
    images->player_right_image = mlx_xpm_file_to_image(game->mlx, "images/player_right-64.xpm", &size, &size);
    images->player_left_image = mlx_xpm_file_to_image(game->mlx, "images/player_left-64.xpm", &size, &size);
    images->player_image = mlx_xpm_file_to_image(game->mlx, "images/player_64.xpm", &size, &size);
    images->coins_image = mlx_xpm_file_to_image(game->mlx, "images/coins-64/coin1.xpm", &size, &size);
    images->exit_image = mlx_xpm_file_to_image(game->mlx, "images/64-img/close-door-64.xpm", &size, &size);
    images->monster_image = mlx_xpm_file_to_image(game->mlx, "images/monster_64.xpm", &size, &size);
    images->open_exit = mlx_xpm_file_to_image(game->mlx, "images/64-img/open-door-64.xpm", &size, &size);
}

int	ft_close(int keycode, to_long *game, t_images *images)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
    // mlx_destroy_image(game->mlx, images->player_image);
    return (0);
}


int animate_monsters(to_long *game)
{
    static int i;
    static int j ;
    int width = 64;
    void *bg = mlx_xpm_file_to_image(game->mlx, "images/64-img/background64.xpm" , &width, &width);
    void *ms = mlx_xpm_file_to_image(game->mlx, "images/monster_64.xpm" , &width, &width);
    t_monster *monsters = game->monsters;

    while(monsters && i % 1000 == 0)
    {
        if(monsters->direction == 'r')
        {
            if(get_val(monsters->monster_x + 64 , monsters->monster_y, game) == 'P')
            {
                printf("you lose !!!.\n");
                exit(0);
            }
            set_val(game, (monsters->monster_x), (monsters->monster_y), '0');
            mlx_put_image_to_window(game->mlx, game->mlx_win, bg , (monsters->monster_x), (monsters->monster_y));
            monsters->monster_x += 64;
            set_val(game, (monsters->monster_x), (monsters->monster_y), 'M');
            mlx_put_image_to_window(game->mlx, game->mlx_win, ms, monsters->monster_x, monsters->monster_y);
            if(get_val(monsters->monster_x + 64 , monsters->monster_y, game) == '1')
                monsters->direction = 'l';
        }
        else if(monsters->direction == 'l')
        {
            if(get_val(monsters->monster_x - 64 , monsters->monster_y, game) == 'P')
            {
                printf("you lose !!!.\n");
                exit(0);
            }
            set_val(game, (monsters->monster_x), (monsters->monster_y), '0');
            mlx_put_image_to_window(game->mlx, game->mlx_win, bg, (monsters->monster_x), (monsters->monster_y));
            monsters->monster_x -= 64;
            set_val(game, (monsters->monster_x), (monsters->monster_y), 'M');
            mlx_put_image_to_window(game->mlx, game->mlx_win, ms, monsters->monster_x, monsters->monster_y);
            if(get_val(monsters->monster_x - 64 , monsters->monster_y, game) == '1')
                monsters->direction = 'r';
        }
        monsters = monsters->next;
    }
    void *coin1 = mlx_xpm_file_to_image(game->mlx, "images/coins-64/coin1.xpm", &width, &width); 
    void *coin2 = mlx_xpm_file_to_image(game->mlx, "images/coins-64/coin2.xpm", &width, &width); 
    void *coin3 = mlx_xpm_file_to_image(game->mlx, "images/coins-64/coin3.xpm", &width, &width); 
    void *coin4 = mlx_xpm_file_to_image(game->mlx, "images/coins-64/coin4.xpm", &width, &width); 
    void *coin5 = mlx_xpm_file_to_image(game->mlx, "images/coins-64/coin5.xpm", &width, &width); 
    void *coin6 = mlx_xpm_file_to_image(game->mlx, "images/coins-64/coin6.xpm", &width, &width); 
    
    t_monster *coins;

    coins = game->coins;
    while (coins && (i % 250 == 0))
    {
        if(coins->direction == 'r')
        {
            if(j == 0)
                mlx_put_image_to_window(game->mlx, game->mlx_win, coin2, coins->monster_x, coins->monster_y);
            else if (j == 1)
                mlx_put_image_to_window(game->mlx, game->mlx_win, coin3, coins->monster_x, coins->monster_y);
            else if (j == 2)
                mlx_put_image_to_window(game->mlx, game->mlx_win, coin4, coins->monster_x, coins->monster_y);
            else if (j == 3)
                mlx_put_image_to_window(game->mlx, game->mlx_win, coin5, coins->monster_x, coins->monster_y);
            else if (j == 4)
                mlx_put_image_to_window(game->mlx, game->mlx_win, coin6, coins->monster_x, coins->monster_y);
            else if (j == 5)
                mlx_put_image_to_window(game->mlx, game->mlx_win, coin1, coins->monster_x, coins->monster_y);
        }
        if(j == 6)
            j = 0;
        j++;
        coins = coins->next;
    }
    i++;
    return (0);
}


int main()
{

    struct so_long game;
    t_images images;
    game.player = malloc(sizeof(t_player));
    game.player->player_x = 0;
    game.player->player_y = 0;


    game.map = read_map("map");
    if(!game.map)
        return (0);
    calc_size(&game);
    game.mlx = mlx_init();
    game.mlx_win = mlx_new_window(game.mlx, game.window_width, game.window_heigth, "soooo_loooong!");
    ft_init_images(&game, &images);
    ft_draw_map(&game, &images);
    mlx_hook(game.mlx_win, 2, (1L << 0), move_player, &game);
    mlx_loop_hook(game.mlx, animate_monsters, &game);
    mlx_loop(game.mlx);
    return (0);
}