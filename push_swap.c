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

void double_check(char **arr)// повторяемость чисел
{
    int i;
    int j;
    int num_1;
    int num_2;

    i = 0;
    while (arr[i] != '\0')
    {
        num_1 = ft_atoi(arr[i]);
        j = i + 1;
        while (arr[j] != '\0')
        {
            num_2 = ft_atoi(arr[j]);
            if (num_1 == num_2)
                free_arr(arr, 1);
            j++;
        }
        i++;
    }
}

t_node	*new_list(int num, int index)
{
	t_node	*list;

	list = malloc(sizeof(t_node));
	if (list == NULL)
		return (NULL);
	list->num = num;
	list->flag = 0;
	list->index = index;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

void stack_add(t_array *all, char **arr)
{
    int     *not_sort;
    int     *sort;
    int     len;
    int     i;
    int     j;
    int     tmp;
    int     count;

    len = 0;
    while (arr[len] != '\0')
    {
            len++;
    }
    not_sort = malloc(sizeof(int) * (len));//выделение памяти под массив
    i = 0;
    while (i < len)//перевод символолв в инты и внесение их в массив
    {
        not_sort[i] = ft_atoi(arr[i]);
        sort[i] = not_sort[i];
        i++;
    }
    i = 0;//сортировка пузырьком
    count = 0;
    while (i < len)// 3 2 5 0 4 // 2 3 5 0 4 // 23054//23045//20345 // 02345
    {
        j = 0;
        while (j < (len - 1 - i)) //0<4//1<4//2<4//3<4 // 0<3//1<3//2<3 // 0<2 // 1 < 2
        {
            if (sort[j] > sort[j + 1]) //3>2//2>5//5>0//5>4 // 2>3//3>0//3>4 // 2>0//2>3
            {
                tmp = sort[j + 1]; 
                sort[j + 1] = sort[j]; 
                sort[j] = tmp;
            }
            j++;//1//2//3//4 // 1//2//3 // 1
        }
        i++; //1//2
    }
    i = 0;
    while (i < len)//прописаться с повторением его индекса//добавить аргументы в стэк (min_a = 1)
    {
        j = 0;
        while (j < len)
        {
            if (not_sort[i] == sort[j])
            {
                all->stack_a;
                ft_lstadd_back(&all->stack_a, new_list(not_sort[i], j + 1)) // добавить новый элемент в конец списка
                new_list(not_sort[i], j + 1);
                j++;
                break;
            }
            j++;
        }
        i++;
    }
    free(not_sort);
    free(sort);
}

t_num *ft_parser(char **argv)
{
    char    **arr;
    int     i;
    t_array *all;   

    arr = get_line(argv);
    check_num(arr);
    double_check(arr);
    i = 0;
    while (arr[i] != '\0')
        i++;
    all = malloc(sizeof(T_array));
    if (!all)
        return (NULL);
    all->stack_a = NULL;
    all->stack_b = NULL;
    all->len_a = i;
    all->len_b = 0;
    all->min_a = 1;
    stack_add(all, arr);
    return (all);
}
/*
int main(int argc, char **argv)
{
    t_array   *a;

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