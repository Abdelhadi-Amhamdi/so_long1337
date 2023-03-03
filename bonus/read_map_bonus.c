/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:25:08 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/03/03 21:16:26 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	**read_map(char *map_file)
{
	char	*map;
	char	*line;
	int		fd;

	map = ft_calloc(1, 1);
	fd = open(map_file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		map = ft_strjoin(map, line);
		free(line);
		line = get_next_line(fd);
	}
	return (ft_split(map, '\n'));
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
