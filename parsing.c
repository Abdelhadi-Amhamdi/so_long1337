#include "libft/libft.h"
#include "gnl/get_next_line.h"

#define INVALID_ARGS_NUMBER "expected 1 args 0 founded"
#define INVLIDE_MAP_NAME "expected .ber map format"
#define INVALID_FILE "file does not exist"
#define INVALID_MAP_SIZE "invalid map size"
#define INVALID_MAP_STRUCTURE "invalid map structure"
#define PLAYER_ERROR "player not founded or more than one"
#define EXIT_ERROR "exit not founded or more than one"
#define COINS_ERROR "at least one collectable reqired"

int chaeck_valid_map_name(const char *file_name)
{
    size_t s;
    int fd;

    s = strlen(file_name);
    fd = open(file_name, O_RDONLY);
    if(s < 4 || strncmp(file_name + (s - 4), ".ber", 4))
        return (-2);
    else if(fd == -1)
        return (-1);
    return (fd);
}

int *check_all_rows_size(char **map)
{
    int *sizes = calloc(2 , sizeof(int));
    sizes[0] = (int)ft_strlen(*map);
    sizes[1] = 0;
    while(*map)
    {
        if(ft_strlen(*map) != sizes[0])
            return 0;
        map++;
        sizes[1]++;
    }
    return (sizes);
}

int check_map_size(int *s)
{
    if(s[0] < s[1])
        return 0;
    return 1;
}

int check_top_and_bottom(char *top, char *bottom)
{
    while(*top)
    {
        if(*top != '1' || *bottom != '1')
            return 0;
        top++;
        bottom++;
    }
    return 1;
}

int check_sides(char **map, int width)
{
    int index;

    index = 0;
    while(map[index])
    {
        if(map[index][0] != '1' || map[index][width -1] != '1')
            return 0;
        index++;
    }
    return 1;
}

int check_borders(char **map, int *sizes)
{
    if(!check_top_and_bottom(map[0] , map[sizes[1] -1]))
        return 0;
    if(!check_sides(map, sizes[0]))
        return 0;
    return 1;
}


int check_map_structure(char **map)
{
    int *s;

    s = check_all_rows_size(map);
    if(!s)
        return (0);
    if(!check_map_size(s))
        return (0);
    if(!check_borders(map, s))
        return (0);
    return 1;
}

char **read_map(int fd)
{
    char *line;
    char *map = calloc(1, 1);
    line = get_next_line(fd);
    while(line)
    {
        map = ft_strjoin(map, line);
        free(line);
        line= get_next_line(fd);
    }
    return (ft_split(map, '\n'));
}

int check_items(char **map)
{
    int p = 0;
    int e = 0;
    int c = 0;
    int index;
    int rows;

    rows = 0;
    while(map[rows])
    {
        index = 0;
        while(map[rows][index])
        {
            if(map[rows][index] == 'P')
                p++;
            else if (map[rows][index] == 'C')
                c++;
            else if (map[rows][index] == 'E')
                e++;
            index++;
        }
        rows++;
    }
    if(p != 1)
        return 0;
    else if ( e != 1)
        return -1;
    else if (c < 1)
        return -2;
    return 1;
}

int main(int ac, char **av)
{
    char **map;
    int status;

    if(ac < 2)
        return (ft_putendl_fd(INVALID_ARGS_NUMBER ,2), 0);
    status = chaeck_valid_map_name(av[1]);
    if(status == -2)
        return (ft_putendl_fd(INVLIDE_MAP_NAME, 2),0);
    else if(status == -1)
        return(ft_putendl_fd(INVALID_FILE, 2),0);
    map = read_map(status);
    if(!check_map_structure(map))
        return (ft_putendl_fd(INVALID_MAP_STRUCTURE, 2),0);
    if(!check_items(map))
        return (ft_putendl_fd(PLAYER_ERROR, 2),0);
    if(check_items(map) == -1)
        return (ft_putendl_fd(EXIT_ERROR, 2),0);
    if(check_items(map) == -2)
        return (ft_putendl_fd(COINS_ERROR, 2),0);
}