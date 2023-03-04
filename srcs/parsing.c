/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:21:04 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/03/04 14:23:18 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	chaeck_valid_map_name(const char *file_name)
{
	size_t	s;
	int		fd;

	s = ft_strlen(file_name);
	fd = open(file_name, O_RDONLY);
	if (s < 4 || ft_strncmp(file_name + (s - 4), ".ber", 4))
		return (-2);
	else if (fd == -1)
		return (-1);
	return (fd);
}

int	check_borders(char **map, int *sizes)
{
	if (!check_top_and_bottom(map[0], map[sizes[1] -1]))
		return (0);
	if (!check_sides(map, sizes[0]))
		return (0);
	return (1);
}

int	check_map_structure(char **map)
{
	int	*s;

	if (!*map || !map)
		return (0);
	s = check_all_rows_size(map);
	if (!s)
		return (0);
	if (!check_map_size(s))
		return (free(s), 0);
	if (!check_borders(map, s))
		return (free(s), 0);
	return (free(s), 1);
}

int	check_items(char **map)
{
	t_parsing_items	items;

	items.rows = 0;
	items.p = 0;
	items.e = 0;
	items.c = 0;
	if (!check_map_items(map, &items))
		return (-3);
	if (items.p != 1)
		return (0);
	else if (items.e != 1)
		return (-1);
	else if (items.c < 1)
		return (-2);
	return (1);
}

char	**parsing(int ac, char *filename)
{
	char	**map;
	int		status;
	int		items_s;

	if (ac < 2)
		return (ft_putendl_fd(INVALID_ARGS_NUMBER, 2), NULL);
	status = chaeck_valid_map_name(filename);
	if (status == -2)
		return (ft_putendl_fd(INVLIDE_MAP_NAME, 2), NULL);
	else if (status == -1)
		return (ft_putendl_fd(INVALID_FILE, 2), NULL);
	map = ft_read_map(status);
	if (!check_map_structure(map))
	{
		ft_free(map);
		return (ft_print_error(2), NULL);
	}
	items_s = check_items(map);
	if (!items_s || items_s == -1 || items_s == -2 || items_s == -3)
	{
		ft_free(map);
		return (ft_print_error(items_s), NULL);
	}
	return (map);
}
