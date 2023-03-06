/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:25:08 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/03/06 11:58:59 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_read_map(int fd)
{
	char	*line;
	char	*map;
	char	**tabs;

	map = calloc(1, 1);
	if (!map)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		if (*line == '\n')
			return (0);
		map = ft_strjoin(map, line);
		free(line);
		line = get_next_line(fd);
	}
	tabs = ft_split(map, '\n');
	return (free(map), tabs);
}

int	check_map_items(char **map, t_parsing_items *items)
{
	while (map[items->rows])
	{
		items->index = 0;
		while (map[items->rows][items->index])
		{
			if (map[items->rows][items->index] == 'P')
				items->p++;
			else if (map[items->rows][items->index] == 'C')
				items->c++;
			else if (map[items->rows][items->index] == 'E')
				items->e++;
			else if (map[items->rows][items->index] != '1' && \
			map[items->rows][items->index] != '0')
				return (0);
			items->index++;
		}
		items->rows++;
	}
	return (1);
}

void	ft_print_error(int status)
{
	if (!status)
		ft_putendl_fd(PLAYER_ERROR, 2);
	else if (status == 2)
		ft_putendl_fd(INVALID_MAP_STRUCTURE, 2);
	else if (status == -1)
		ft_putendl_fd(EXIT_ERROR, 2);
	else if (status == -2)
		ft_putendl_fd(COINS_ERROR, 2);
	else if (status == -3)
		ft_putendl_fd("Error", 2);
}
