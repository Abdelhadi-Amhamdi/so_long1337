/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:25:08 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/27 12:01:22 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "gnl/get_next_line.h"

t_list *read_map(char *map_file)
{
    t_list *map;
    char *line;
    t_list *node;
    int fd;
    int size = 0;
    char **map_tab;
    int i = 0;
    
    line = NULL;
    map = NULL;
    fd = open(map_file, O_RDONLY);
    line = get_next_line(fd);
    while(line)
    {
        size++;
        if(!map)
        {
            map = ft_lstnew(line);
            if (!map)
                return (NULL);
        }
        else
        {
            node = ft_lstnew(line);
            if(!node)
                return (NULL);
            ft_lstadd_back(&map, node);
        }
        line = get_next_line(fd);
    }
    return map;
}
