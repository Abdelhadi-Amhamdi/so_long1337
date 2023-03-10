/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:25:08 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/03/10 11:38:20 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**ft_read_map(int fd)
{
	char	*line;
	char	*map;
	char	**tabs;

	map = calloc(1, 1);
	line = get_next_line(fd);
	while (line)
	{
		if (*line == '\n')
			return (NULL);
		map = ft_strjoin(map, line);
		free(line);
		line = get_next_line(fd);
	}
	tabs = ft_split(map, '\n');
	return (free(map), tabs);
}

void	ft_draw_exit(t_long *game, t_image *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_w, \
	img->e, (x * img->size), (y * img->size));
	game->e_x = x * img->size;
	game->e_y = y * img->size;
}

int	check_borders(char **map, int *sizes)
{
	if (!check_top_and_bottom(map[0], map[sizes[1] -1]))
		return (0);
	if (!check_sides(map, sizes[0]))
		return (0);
	return (1);
}

void	handle_enmey_touch_and_exit(char item, t_long *g)
{
	if (item == 'M')
		ft_putendl_fd("you die !!", 1);
	else if (item == 'E')
		ft_putendl_fd("you win !!", 1);
	if (item == 'M' || item == 'E' || item == 'e')
	{
		ft_free(g->map);
		free(g->p);
		ft_free_list(g->monsters);
		ft_free_list(g->coins);
		ft_destroy_all(g->img, g);
		mlx_destroy_window(g->mlx, g->mlx_w);
		exit(0);
	}
}

void	get_player_position(t_long *game)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	map = game->map;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				game->p->x = x;
				game->p->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
