/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:25:08 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/02/22 19:33:57 by aamhamdi         ###   ########.fr       */
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
	game->exit_x = x * img->size;
	game->exit_y = y * img->size;
}
