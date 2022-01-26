#include <stdio.h>
#include "libft/libft.h"

char **get_line(char **argv)
{
    char *str_line;
    char *tmp;
    char **arr;
    int i;

    str_line = ft_strdup(argv[1]);
    i = 2;
    while(argv[i])
    {
        tmp = str_line;
        free(str_line);
        str_line = ft_strjoin(tmp, " ");
        //free(tmp);
        //tmp = str_line;
        free(str_line);
        str_line = ft_strjoin(tmp, argv[i]);
        //free(tmp);
        i++;
    }
    arr = ft_split(str_line, ' ');
    free(str_line);
    return (arr);
}
/*
t_num *ft_parser(char **argv)
{
    char    **arr;

    arr = get_line(argv);
}

int main(int argc, char **argv)
{
    t_num   *all;

    if (argc > 1)
    {
        all = ft_parser(argv);
    }
    return (0);
}*/

int main(int argc, char **argv)
{
    char **str;
    str = get_line(argv);
    printf("%s\n", str[0]);
    printf("%s\n", str[1]);
    free(str);
    return(0);
}