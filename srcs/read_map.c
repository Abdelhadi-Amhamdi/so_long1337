/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:25:08 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/03/01 12:11:37 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
