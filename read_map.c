/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:25:08 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/01/26 15:46:26 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "gnl/get_next_line.h"

int read_map(char *map_file)
{
    t_list *map;
    char *line;
    t_list *node;
    int fd;
    
    line = NULL;
    map = NULL;
    fd = open(map_file, O_RDONLY);
    line = get_next_line(fd);
    while(line)
    {
        if(!map)
        {
            map = ft_lstnew(line);
            if (!map)
                return (0);
        }
        else
        {
            node = ft_lstnew(line);
            if(!node)
                return (0);
            ft_lstadd_back(&map, node);
        }
        line = get_next_line(fd);
    }
    while (map)
    {
        printf("%s", map->content);
        map = map->next;
    }
    
    return 1;
}

int main()
{
    char *file_name = "map";
    read_map(file_name);
}