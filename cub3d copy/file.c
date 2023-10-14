#include <stdio.h>
#include "file.h"

void get_map(t_all **all, int fd)
{
    char *line;
    char *tmp;

    tmp = NULL;
    line = NULL;
    tmp = get_next_line(fd);
    if(!tmp)
        exit(4);
    while(tmp)
    {
        tmp = ft_strjoin(line, tmp);
        line = ft_strdup(tmp);
        free(tmp);
        tmp = get_next_line(fd);
    }
    (*all)->map = ft_split(line, '\n');
}
void init_befor_init_hh(t_textr **txtr)
{
    (*txtr)->color_c = NULL;
    (*txtr)->color_f = NULL;
    (*txtr)->EA = NULL;
    (*txtr)->NO = NULL;
    (*txtr)->SO = NULL;
    (*txtr)->WE = NULL;
}
int start_reading_map(char *line)
{
    if(!strnstr(line, "NO", ft_strlen(line)) && !strnstr(line, "SO", ft_strlen(line)) &&\
    !strnstr(line, "WE", ft_strlen(line)) && !strnstr(line, "EA", ft_strlen(line)) &&\
    !strnstr(line, "F", ft_strlen(line)) && !strnstr(line, "C", ft_strlen(line)))
        return (-1);
    return(0);
}
void init_txters(t_textr **txtr, t_all *all)
{
    int i;
    int x;

    init_befor_init_hh(txtr);
    x = 0;
    i = 0;
    while(all->map[i])
    {
        if(start_reading_map(all->map[i]) == -1)
                break;
        if(strnstr(all->map[i], "NO", 2))
        {
            x++;
            (*txtr)->NO = ft_strdup(all->map[i]);
            all->map[i] = NULL;
        }
        else if(strnstr(all->map[i], "SO", 2))
        {
            x++;
            (*txtr)->SO = ft_strdup(all->map[i]);
            all->map[i] = NULL;
        }
        else if(strnstr(all->map[i], "WE", 2))
        {
            x++;
            (*txtr)->WE = ft_strdup(all->map[i]);
            all->map[i] = NULL;
        }
       else if(strnstr(all->map[i], "EA", 2))
       {
            x++;
            (*txtr)->EA = ft_strdup(all->map[i]);
            all->map[i] = NULL;
       }
        else if(strnstr(all->map[i], "F", 1))
        {

            x++;
            (*txtr)->color_f = ft_strdup(all->map[i]);
           all->map[i] = NULL;
        }
        else if(strnstr(all->map[i], "C", 1))
        {
            x++;
            (*txtr)->color_c = ft_strdup(all->map[i]);
            all->map[i] = NULL;
        }
        i++;
    }
    all->map = &all->map[x];
}

int check_errors(char **map)
{
    int i;
    int plr;
    int x;
    
    plr = 0;
    i = 0;
    while(map[i])
    {
        x = 0;
        while(map[i][x])
        {
            if(map[i][x] != 'N' && map[i][x] != 'E' && map[i][x] != 'S' && map[i][x] != 'W' && map[i][x] != '0' && map[i][x] != '1' && map[i][x] != ' ')
            {
                    return(1);
            }
            if(map[i][x] == 'N' || map[i][x] == 'E' || map[i][x] == 'S' || map[i][x] == 'W')
                plr++;
            x++;
        }
        i++;
    }
    if(plr > 1 || plr == 0)
        return(1);
    return(0);
}
void get_x_y_of_the_player(t_all **all)
{
    char c;
    while((*all)->map[(*all)->x])
    {
        (*all)->y = 0;
        while ((*all)->map[(*all)->x][(*all)->y])
        {
            c = (*all)->map[(*all)->x][(*all)->y];
            if(c == 'N')
            {
                return ;
                (*all)->player_angel = 0; //to comeback later
            }
            if(c == 'S')
            {
                return ;
                (*all)->player_angel = 0; //to comeback later
            }
            if(c == 'E')
            {
                return ;
                (*all)->player_angel = 0; //to comeback later
            }
            if(c == 'W')
            {
                return ;
                (*all)->player_angel = 0; //to comeback later
            }
        (*all)->y++;
        }
         (*all)->x++;
    }
}

int all_in_one(t_all **all, t_textr **txtr,  char **argv)
{
    (*all) = malloc(sizeof(t_all));
    (*txtr) = malloc(sizeof(t_textr));
    (*all)->fd = open(argv[1], O_RDONLY);
    if((*all)->fd == -1)
    {
        perror("file error\n");
         return (-1);
    }
    init_all(all);
    get_map(all, (*all)->fd);
    int i;
    i = 0;
     init_txters(&(*txtr), (*all));
    if(check_errors((*all)->map) || !(*txtr)->color_c || !(*txtr)->color_f || !(*txtr)->EA || !(*txtr)->NO || !(*txtr)->SO || !(*txtr)->WE)
    {
        printf("%s\n", (*all)->map[0]);
        printf("unvalid map :(\n");
        return(-1);
    }
    get_x_y_of_the_player((all));
    return(0);
}

