#include "file.h"
void init_all(t_all **all)
{
    (*all)->x = 0;
    (*all)->y = 0;
    (*all)->x_of_map = 0;
    (*all)->y_of_map = 0;;
    (*all)->player_angel = 0;
    (*all)->map = NULL;
}
void count_x_y_of_the_map(t_all **all)
{
    while((*all)->map[(*all)->y_of_map])
    {
        (*all)->x_of_map = 0;
        while ((*all)->map[(*all)->y_of_map][(*all)->x_of_map])
            (*all)->x_of_map++;
        (*all)->y_of_map++;
    }
}
int updatemap(t_all *all)
{
    char **updated_map;
    int x; 
    int i;
    int len;

    len = 0;
    i = 0;  
    x = 0;
    len = ft_strlen(all->map[0]);
    while(all->map[i])
    {
        x = 0;
        while (all->map[i][x])
            x++;
        if(x > len)
            len = x;
        i++;
    }
    return(len);
}


void fix_map(t_all **all, int len)
{
    char **new_map;
    int i;
    int x;
    i = 0;
    x = 0; 
    
    new_map =  calloc(sizeof(char *) ,  (*all)->y_of_map + 1);
    while(i <  (*all)->y_of_map)
    {
        new_map[i] = calloc(sizeof(char) , len + 1);
        i++;
    }
    i = 0;
    while(i < (*all)->y_of_map)
    {
        strcpy(new_map[i], (*all)->map[i]);
        i++;
    }
    new_map[i] = NULL;
    (*all)->map = new_map;
}
int check_if_close(char **map)
{
  int i;
  int x;

  i = 0;
  x  = 0;
   if(i == 0 && (strnstr(map[i], "0", strlen(map[i]) - 1) ||  strnstr(map[i], "N", strlen(map[i]) - 1) ||\
   strnstr(map[i], "S", strlen(map[i]) - 1) || strnstr(map[i], "E", strlen(map[i]) - 1) || strnstr(map[i], "W", strlen(map[i]) - 1)))
   {
    printf("not close - \n");
    return -1;
    }
  while (map[i])
  {
    x = 0;

    while (map[i][x])
    {
       if(map[i][0] == 'N' || map[i][0] == 'E' || map[i][0] == 'S' || map[i][0] == 'W' || map[i][0] == '0')
       {
            printf("not closex\n");
            return(-1);
       }
       if(map[i][ft_strlen(map[i]) - 1] == 'N' || map[i][ft_strlen(map[i]) - 1] == 'E' ||\
       map[i][ft_strlen(map[i]) - 1] == 'S' || map[i][ft_strlen(map[i]) - 1] == 'W' || map[i][ft_strlen(map[i]) - 1] == '0')
       {
            printf("not closex\n");
            return(-1);
       }
        x++;
    }
    i++;
  }
  i--;
  if((strnstr(map[i], "0", strlen(map[i])) ||  strnstr(map[i], "N", strlen(map[i])) ||\
   strnstr(map[i], "S", strlen(map[i])) || strnstr(map[i], "E", strlen(map[i])) || strnstr(map[i], "W", strlen(map[i]))))
   {
    printf("not close \n");
    return -1;
    }
  return (0);
}
int check_for_valid_map(char **map)
{
    int i;
    int x;
    i = 0;
    x = 0;
    
    while(map[i])
    {
        x = 0;
        while (map[i][x])
        {
            if(map[i][x] == '0')
            {
                if(i > 0 && (map[i - 1][x] == '\0' || map[i + 1][x] == '\0' || map[i - 1][x] == ' ' || map[i + 1][x] == ' '))
                {
                    printf("unvalid ;)\n");
                    return(-1);
                }
                if(x > 0 && (map[i][x - 1] == '\0' ||map[i][x + 1] == '\0' || map[i][x - 1] == ' ' ||map[i][x + 1] == ' '))
                {
                    printf("unvalid :)\n");
                    return(-1);
                }
            }
            x++;
        }
        i++;
    }
    if(ft_strchr(map[i - 1], '0'))
    {
        printf("unvalid ;)\n");
        return -1;
    }
    return(0);
}
int check_extionts(char *argv)
{
    int i;
    i = 0;
    if(argv[0] == '.')
        i++;
    while(argv[i])
    {
        if(argv[i] == '.')
            if(strcmp((argv + i + 1), "cub"))
            {
                printf("unvalid ext");
                return -1;
            }
            i++;
    }
    return(0);
}
int check_final(t_textr *txtr)
{
    //check for error txter 
    //almost finish
    
}
int main(int argc, char *argv[])
{
    t_all *all;
    t_textr *txtr;
    int len;
    
   if (check_extionts(argv[1]) == -1 || all_in_one(&all, &txtr, argv) == -1)
        return(0);
    len = updatemap(all);
    count_x_y_of_the_map(&all);
    fix_map(&all, len);
    if((check_if_close(all->map)) == -1)
        return -1;
    if(check_for_valid_map(all->map) == -1)
        return(-1);
    if(check_final(txtr) == -1)
        return (-1);
    return(0);
}

