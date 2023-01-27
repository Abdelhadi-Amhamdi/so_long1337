/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouves.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 14:57:07 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/27 17:44:47 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"
#include "libft/libft.h"
#include <mlx.h>

char get_val(int x, int y, to_long *game)
{

    t_list *map;
    int i = 0;

    map = game->map;
    while(map)
    {
        if(i == (y / 50))
        {
            char *data;

            data = (char *)map->content;
            return (data[(x / 50)]);
            break;
        }
        map = map->next;
        i++;
    }
    return (0);
}

int  move_player(int keycode, to_long *game)
{
    void *background_img;
    void *player_img;
    int width = 50;
    char c;

    background_img = mlx_xpm_file_to_image(game, "images/background.xpm", &width, &width);
    player_img = mlx_xpm_file_to_image(game, "images/player_right.xpm", &width, &width);
    if(keycode == 124)
    {
        c = get_val((game->p_x + 50), game->p_y, game);
        if(c == 'E' || c == 'M')
        {
            mlx_put_image_to_window(game->mlx, game->mlx_win, background_img, (game->p_x), (game->p_y));
            ft_putendl_fd("u lose !!!", 1);
            exit (0);
        }
        else if( c != '1')
        {
            mlx_put_image_to_window(game->mlx, game->mlx_win, background_img, (game->p_x), (game->p_y));
            game->p_x += 50;
            mlx_put_image_to_window(game->mlx, game->mlx_win, player_img, game->p_x, game->p_y);
        }
    }
    else if(keycode == 123)
    {
        c = get_val((game->p_x - 50), game->p_y, game);
        if(c == 'E' || c == 'M')
        {
            mlx_put_image_to_window(game->mlx, game->mlx_win, background_img, (game->p_x), (game->p_y));
            ft_putendl_fd("u lose !!!", 1);
            exit (0);
        }
        else if( c != '1')
        {
            mlx_put_image_to_window(game->mlx, game->mlx_win, background_img, (game->p_x), (game->p_y));
            game->p_x -= 50;
            mlx_put_image_to_window(game->mlx, game->mlx_win, player_img, game->p_x, game->p_y);
        }
    }
    else if(keycode == 126)
    {
        c = get_val((game->p_x), (game->p_y - 50), game);
        if(c == 'E' || c == 'M')
        {
            mlx_put_image_to_window(game->mlx, game->mlx_win, background_img, (game->p_x), (game->p_y));
            ft_putendl_fd("u lose !!!", 1);
            exit (0);
        }
        else if(c != '1')
        {
            mlx_put_image_to_window(game->mlx, game->mlx_win, background_img, (game->p_x), (game->p_y));
            game->p_y -= 50;
            mlx_put_image_to_window(game->mlx, game->mlx_win, player_img, game->p_x, game->p_y);
        }
    }
    else if(keycode == 125)
    {
        c = get_val(game->p_x, (game->p_y + 50), game);
        if(c == 'E' || c == 'M')
        {
            mlx_put_image_to_window(game->mlx, game->mlx_win, background_img, (game->p_x), (game->p_y));
            ft_putendl_fd("u lose !!!", 1);
            exit (0);
        }
        else if(c != '1')
        {
            mlx_put_image_to_window(game->mlx, game->mlx_win, background_img, (game->p_x), (game->p_y));
            game->p_y += 50;
            mlx_put_image_to_window(game->mlx, game->mlx_win, player_img, game->p_x, game->p_y);
        }
    }
    return 1;
}

