#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/errno.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_lst
{
    int      index;
    int      flag;
    int      value;
    int      group;
    struct s_lst *next;
    //struct s_node *prev;
} t_lst;

typedef struct s_strct
{
    t_lst  *begin_stack_a;
    t_lst  *begin_stack_b;
    t_lst   *end_stack_a;
    t_lst   *end_stack_b;
    int     num_a;
    int     num_b;
    int     nextpoint;
    int     maxpoint;
    int     midpoint;
    int     curr_group;
    int     oper_cnt;
} t_strct;

/*char **get_line(char **argv);
t_num *ft_parser(char **argv);
void    check_num(char **arr);*/
/*read arr && check stack*/
t_lst   *init_new_lst(int val);
int     read_arr(int argc, char **argv, t_strct *swap_strct);
void	init_struct(t_strct *swap_strct);
int     ft_parser(t_strct *swap_strct, char *argv, t_lst **lst);
int     ft_isnum(char *str);
int     ft_proc_seq(t_strct *swap_strct, t_lst **lst, char *str_ar);
int     duplcheck(t_lst *lst);
int     check_seq(t_lst *stack_a);
char    ft_atoi_ch(const char *str, long int *nbr);
/***/
/*ft_process*/
void    ft_process(t_strct *swap_strct);
int     ft_index_elem(t_lst *swap_strct, int k);
void    atob_proc(t_strct *swap_strct);
void	btoa_proc(t_strct *swap_strct);
int     sort_ab(t_strct *swap_strct, int d_group);
int	    d_check(t_lst *lst);
int     check_a_stack(t_strct *swap_strct);
void    set_groups(t_lst *lst, int num);
int     check3a_l(t_strct *swap_strct);
int     check_a_stack_hard(t_strct *swap_strct, int d_group);
int     sort_ab(t_strct *swap_strct, int d_group);
void    step_exec(t_strct *swap_strct);
int	    sort_ba(t_strct *swap_strct);
void	stack_proc_btoa(t_strct *swap_strct);
void	swapa_3_hard_sit_5(t_strct *p_strct);
void	swapa_3_hard(t_strct *p_strct, int flag);
int     check_stack_b(t_strct *swap_strct);
int	    check3b_l(t_strct *swap_strct);
void	swapb_3_l_2(t_strct *swap_strct, int c);
void	swapb_3_l(t_strct *swap_strct, int c);
int     check3a_h(t_strct *swap_strct);
void    move_sort(t_strct *swap_strct);
void	stack_clear(t_lst *lst);
int     stacka_is_sorted(t_strct *swap_strct);
/***/

void    free_arr(char **arr, int flag);
void	stack_clear(t_lst *lst);
void    err();

/*instructions*/
void    sa(t_strct *swap_strct);
void    sb(t_strct *swap_strct);
void    ss(t_strct *swap_strct);
void    ra(t_strct *swap_strct);
void	rra(t_strct *swap_strct);
void    rb(t_strct *swap_strct);
void	rrb(t_strct *swap_strct);
void    rr(t_strct *swap_strct);
void    rrr(t_strct *swap_strct);
void    pa(t_strct  *swap_strct);
void    pb(t_strct  *swap_strct);
/***in instructions*/
void    swap_lst(t_lst **begin, t_lst **end_of);
void	forw_rot(t_lst **begin, t_lst **end_a);
void	revs_rot(t_lst **begin, t_lst **end_a);
void    move_lst(t_lst  **begin_stack_a, t_lst  **end_stack_a, 
        t_lst  **begin_stack_b, t_lst  **end_stack_b);
/***/





#endif