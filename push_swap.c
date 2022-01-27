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
        str_line = ft_strjoin(str_line, " ");
        str_line = ft_strjoin(str_line, argv[i]);
        i++;
    }
    arr = ft_split(str_line, ' ');
    free(str_line);
    return (arr);
}

void err()
{
    ft_putstr_fd("ERROR\n", 2);
    exit(EXIT_SUCCESS);
}

void    free_arr(char **arr, int flag)
{
    while (*arr != '\0')
    {
        free(*arr);
        arr++;
    }
    if (flag != 0)
        err();
}

void    check_num(char **arr)
{
    
    int i;
    int j;

    i = 0;
    while (arr[i] != '\0')
    {
        j = 0;
        while (arr[i][j] != '\0')
        {
            if (arr[i][j] == '-')
                j++;
            if (!((arr[i][j] >= '0') && (arr[i][j] <= '9')))//проверка является массив числом
                free_arr(arr, 1);
            j++;
        }
        num = ft_atoi(arr[i]);
        if (num < MIN_INT || num > MAX_INT)//проверка входит ли значение в пределы int
            free_arr(arr, 1);
        else if
            i++;
    }
}

void double_check(char **arr)// повторяемость цифр
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (arr[i] != '\0')
    {
        while (arr[i][j] != '\0')
        {
            if (arr[i][j])
            j++;
        }
        
        i++;
    }
    

}

t_num *ft_parser(char **argv)
{
    char    **arr;
    int     i;

    arr = get_line(argv);
    check_num(arr);
    double_check(arr);
}
/*
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
    printf("%s\n", str[2]);
    free(str);
    return(0);
}