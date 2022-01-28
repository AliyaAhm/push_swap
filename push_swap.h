#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/errno.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_node
{
    int      index;
    int      flag;
    struct s_node *next;
    struct s_node *prev;
} t_node;

typedef struct s_arr
{
    t_node  *stack_a;
    t_node  *stack_b;
    int     size_a;
    int     size_b;
    int     min_a;
    int     max_a;
    int     mediana;
    int     len_a;
    int     len_b;
} t_array;

char **get_line(char **argv);
t_num *ft_parser(char **argv);
void    check_num(char **arr);

#endif