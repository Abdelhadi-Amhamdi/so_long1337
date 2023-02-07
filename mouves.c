/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouves.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:57:07 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/02/05 19:03:51 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"
#include "libft/libft.h"
#include <mlx.h>

char get_val(int x, int y, to_long *game)
{
    if(x < 0 || y < 0)
        return 0;
    return (game->map[y / 64][x / 64]);
}

void set_val(to_long *game, int x, int y, char c)
{
    game->map[y / 64][x / 64] = c;
}
t_monster *get_item(int x, int y, to_long *game)
{
    t_monster *tmp;

    tmp = game->coins;
    while(tmp)
    {
        if(tmp->monster_x == x && tmp->monster_y == y)
            return (tmp);
        tmp = tmp->next;
    }
    return (NULL);
}
int  move_player(int keycode, to_long *game)
{
    char c;
    t_images images;
    static int collects;
    t_monster *item;
    void *win_img;
    int width;
    int height;

    ft_init_images(game, &images);
    if(keycode == 17)
    {
        printf("hello\n");
    }
    else if(keycode == 124)
    {
        c = get_val((game->player->player_x + 64), game->player->player_y, game);
        if( c == '0' || c == 'C')
        {
            if(c == 'C')
            {
                item = get_item(game->player->player_x + 64 , game->player->player_y, game);
                item->direction = 'b';
                if(++collects == game->collects_n)
                    mlx_put_image_to_window(game->mlx, game->mlx_win, images.open_exit, game->exit_x, game->exit_y);
            }
            set_val(game, (game->player->player_x), (game->player->player_y), '0');
            mlx_put_image_to_window(game->mlx, game->mlx_win, images.background_image, (game->player->player_x), (game->player->player_y));
            game->player->player_x += 64;
            set_val(game, (game->player->player_x), (game->player->player_y), 'P');
            mlx_put_image_to_window(game->mlx, game->mlx_win, images.player_right_image, game->player->player_x, game->player->player_y);
        }
        else if(c == 'E' && collects == game->collects_n)
        {
            printf("you win !!!.\n");
            exit(0);
        }
        else if(c == 'M')
        {
            printf("you die !!!.\n");
            exit(0);
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
                    mlx_put_image_to_window(game->mlx, game->mlx_win, images.open_exit, game->exit_x, game->exit_y);
            }
            set_val(game, (game->player->player_x), (game->player->player_y), '0');
            mlx_put_image_to_window(game->mlx, game->mlx_win, images.background_image, (game->player->player_x), (game->player->player_y));
            game->player->player_x -= 64;
            set_val(game, (game->player->player_x), (game->player->player_y), 'P');
            mlx_put_image_to_window(game->mlx, game->mlx_win, images.player_left_image, game->player->player_x, game->player->player_y);
        }
        else if(c == 'E' && collects == game->collects_n)
        {
            printf("you win !!!.\n");
            exit(0);
        }
        else if(c == 'M')
        {
            printf("you die !!!.\n");
            exit(0);
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
                    mlx_put_image_to_window(game->mlx, game->mlx_win, images.open_exit, game->exit_x, game->exit_y);
            }
            set_val(game, (game->player->player_x), (game->player->player_y), '0');
            mlx_put_image_to_window(game->mlx, game->mlx_win, images.background_image, (game->player->player_x), (game->player->player_y));
            game->player->player_y -= 64;
            set_val(game, (game->player->player_x), (game->player->player_y), 'P');
            mlx_put_image_to_window(game->mlx, game->mlx_win, images.player_image, game->player->player_x, game->player->player_y);
        }
        else if(c == 'E' && collects == game->collects_n)
        {
            printf("you win !!!.\n");
            exit(0);
        }
        else if(c == 'M')
        {
            printf("you die !!!.\n");
            exit(0);
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
                    mlx_put_image_to_window(game->mlx, game->mlx_win, images.open_exit, game->exit_x, game->exit_y);
            }
            set_val(game, (game->player->player_x), (game->player->player_y), '0');
            mlx_put_image_to_window(game->mlx, game->mlx_win, images.background_image, (game->player->player_x), (game->player->player_y));
            game->player->player_y += 64;
            set_val(game, (game->player->player_x), (game->player->player_y), 'P');
            mlx_put_image_to_window(game->mlx, game->mlx_win, images.player_image, game->player->player_x, game->player->player_y);
        }
        else if(c == 'E' && collects == game->collects_n)
        {
            
            if(game->window_width >= 849 && game->window_heigth >= 512)
            {
                width = 849;
                height = 512;
                win_img = mlx_xpm_file_to_image(game->mlx, "images/end-64/win-lg.xpm", &width , &height);
            }
            else if(game->window_width >= 664 && game->window_heigth >= 320)
            {
                width = 664;
                height = 320;
                win_img = mlx_xpm_file_to_image(game->mlx, "images/end-64/win-md.xpm", &width , &height);
            }
            else
            {
                width = 375;
                height = 192;
                win_img = mlx_xpm_file_to_image(game->mlx, "images/end-64/win-sm.xpm", &width , &height);
            }
            mlx_put_image_to_window(game->mlx, game->mlx_win, win_img, ((game->window_width / 2) - width / 2)  , ((game->window_heigth / 2) - height / 2));
            while(game->monsters)
            {
                game->monsters->direction = 'a';
                game->monsters = game->monsters->next;
            }
            printf("you win !!!.\n");
        }
        else if(c == 'M')
        {
            if(game->window_width >= 849 && game->window_heigth >= 512)
            {
                width = 849;
                height = 512;
                win_img = mlx_xpm_file_to_image(game->mlx, "images/end-64/over-lg.xpm", &width , &height);
            }
            else if(game->window_width >= 664 && game->window_heigth >= 320)
            {
                width = 664;
                height = 320;
                win_img = mlx_xpm_file_to_image(game->mlx, "images/end-64/over-md.xpm", &width , &height);
            }
            else
            {
                width = 375;
                height = 192;
                win_img = mlx_xpm_file_to_image(game->mlx, "images/end-64/over-sm.xpm", &width , &height);
            }
            mlx_put_image_to_window(game->mlx, game->mlx_win, win_img, ((game->window_width / 2) - width / 2)  , ((game->window_heigth / 2) - height / 2));
            while(game->monsters)
            {
                game->monsters->direction = 'a';
                game->monsters = game->monsters->next;
            }
            printf("you die !!!.\n");
            
        }
    }
    return 1;
}

