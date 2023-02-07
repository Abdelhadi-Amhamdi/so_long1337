/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:16:46 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/02/05 15:47:12 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"
#include <mlx.h>

t_monster *ft_lst_creat(int mx, int my)
{
    t_monster *m;

    m = malloc(sizeof(t_monster));
    if(!m)
        return (NULL);

    m->monster_x = mx;
    m->monster_y = my;
    m->direction = 'r';
    m->next = NULL;
    return (m);
}

t_monster *last_lst(t_monster *monsters)
{
    t_monster *tmp;

    tmp = monsters;
    
    while(tmp->next)
        tmp = tmp->next;
    return (tmp);
}

void ft_lst_add_back(t_monster **monsters, t_monster *new_monster)
{
    t_monster *l;
    
    if(*monsters)
    {
        l = last_lst(*monsters);
        l->next = new_monster;
    }
    else
        *monsters = new_monster;
}

void create_monster(int mx, int my, t_monster **monsters)
{
    t_monster *monster;

    monster = ft_lst_creat(mx, my);
    ft_lst_add_back(monsters, monster);
}


void ft_draw_map(to_long *game, t_images *images)
{
    int x = 0;
    int y = 0;
    char **map;
    t_monster *ms;
    t_monster *coins;
    coins = NULL;
    ms = NULL;
    map = game->map;
    game->collects_n = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == '1')
                mlx_put_image_to_window(game->mlx, game->mlx_win, images->wall_image, (x * images->size), (y * images->size));
            else if(map[y][x] == 'C')
            {
                game->collects_n++;
                mlx_put_image_to_window(game->mlx, game->mlx_win, images->coins_image, (x * images->size), (y * images->size));
                create_monster(x * images->size, y * images->size, &coins);
            }
            else if(map[y][x] == 'P')
            {
                mlx_put_image_to_window(game->mlx, game->mlx_win, images->player_image, (x * images->size), (y * images->size));
                game->player->player_x = x * images->size;
                game->player->player_y = y * images->size;
            }
            else if(map[y][x] == 'E')
            {
                mlx_put_image_to_window(game->mlx, game->mlx_win, images->exit_image, (x * images->size), (y * images->size));
                game->exit_x = x * images->size;
                game->exit_y = y * images->size;                
            }
            else if(map[y][x] == 'M')
            {
                mlx_put_image_to_window(game->mlx, game->mlx_win, images->monster_image, (x * images->size), (y * images->size));
                create_monster(x * images->size , y * images->size, &ms);
            }
            else if(map[y][x] == '0')
                mlx_put_image_to_window(game->mlx, game->mlx_win, images->background_image, (x * images->size), (y * images->size));
            x++;
        }
        y++;
    }
    game->monsters = ms;
    game->coins = coins;
}