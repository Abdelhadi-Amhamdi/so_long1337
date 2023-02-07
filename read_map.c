/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamhamdi <aamhamdi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 15:25:08 by aamhamdi          #+#    #+#             */
/*   Updated: 2023/02/05 10:53:47 by aamhamdi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "gnl/get_next_line.h"

char **read_map(char *map_file)
{
    char *map;
    char *line;
    int fd;
    
    map = ft_calloc(1, 1);
    fd = open(map_file, O_RDONLY);
    line = get_next_line(fd);
    while(line)
    {
        map = ft_strjoin(map, line);
        free(line);
        line = get_next_line(fd);
    }
    return (ft_split(map, '\n'));
}
