/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouves.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:57:07 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/02/04 15:22:52 by aamhamdi         ###   ########.fr       */
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

int  move_player(int keycode, to_long *game)
{
    char c;
    t_images images;
    static int collects;

    ft_init_images(game, &images);
    if(keycode == 124)
    {
        c = get_val((game->p_x + 64), game->p_y, game);
        if( c == '0' || c == 'C')
        {
            if(c == 'C')
            {
                collects++;
                if(collects == game->collects_n)
                    mlx_put_image_to_window(game->mlx, game->mlx_win, images.open_exit, game->exit_x, game->exit_y);
                
            }
            set_val(game, (game->p_x), (game->p_y), '0');
            mlx_put_image_to_window(game->mlx, game->mlx_win, images.background_image, (game->p_x), (game->p_y));
            game->p_x += 64;
            set_val(game, (game->p_x), (game->p_y), 'P');
            mlx_put_image_to_window(game->mlx, game->mlx_win, images.player_right_image, game->p_x, game->p_y);
        }
        else if(c == 'E' && collects == game->collects_n)
        {
            printf("you win !!!.\n");
            exit(0);
        }
    }
    else if(keycode == 123)
    {
        c = get_val((game->p_x - 64), game->p_y, game);
        if( c == '0' || c == 'C')
        {
            if(c == 'C')
            {
                collects++;
                if(collects == game->collects_n)
                    mlx_put_image_to_window(game->mlx, game->mlx_win, images.open_exit, game->exit_x, game->exit_y);
                
            }
            set_val(game, (game->p_x), (game->p_y), '0');
            mlx_put_image_to_window(game->mlx, game->mlx_win, images.background_image, (game->p_x), (game->p_y));
            game->p_x -= 64;
            set_val(game, (game->p_x), (game->p_y), 'P');
            mlx_put_image_to_window(game->mlx, game->mlx_win, images.player_left_image, game->p_x, game->p_y);
        }
        else if(c == 'E' && collects == game->collects_n)
        {
            printf("you win !!!.\n");
            exit(0);
        }
    }
    else if(keycode == 126)
    {
        c = get_val((game->p_x), (game->p_y - 64), game);
        if(c == '0' || c == 'C')
        {
            if(c == 'C')
            {
                collects++;
                if(collects == game->collects_n)
                    mlx_put_image_to_window(game->mlx, game->mlx_win, images.open_exit, game->exit_x, game->exit_y);
                
            }
            set_val(game, (game->p_x), (game->p_y), '0');
            mlx_put_image_to_window(game->mlx, game->mlx_win, images.background_image, (game->p_x), (game->p_y));
            game->p_y -= 64;
            set_val(game, (game->p_x), (game->p_y), 'P');
            mlx_put_image_to_window(game->mlx, game->mlx_win, images.player_image, game->p_x, game->p_y);
        }
        else if(c == 'E' && collects == game->collects_n)
        {
            printf("you win !!!.\n");
            exit(0);
        }
    }
    else if(keycode == 125)
    {
        c = get_val(game->p_x, (game->p_y + 64), game);
        if(c == '0' || c == 'C')
        {
            if(c == 'C')
            {
                collects++;
                if(collects == game->collects_n)
                    mlx_put_image_to_window(game->mlx, game->mlx_win, images.open_exit, game->exit_x, game->exit_y);
                
            }
            set_val(game, (game->p_x), (game->p_y), '0');
            mlx_put_image_to_window(game->mlx, game->mlx_win, images.background_image, (game->p_x), (game->p_y));
            game->p_y += 64;
            set_val(game, (game->p_x), (game->p_y), 'P');
            mlx_put_image_to_window(game->mlx, game->mlx_win, images.player_image, game->p_x, game->p_y);
        }
        else if(c == 'E' && collects == game->collects_n)
        {
            printf("you win !!!.\n");
            exit(0);
        }
    }
    return 1;
}

