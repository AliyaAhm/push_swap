#include <fcntl.h>
#include "push_swap.h"

/*void	init_struct(t_strct *swap_strct)
{
	swap_strct->begin_stack_a = NULL;
    swap_strct->begin_stack_b = NULL;
    swap_strct->end_stack_a = NULL;
    swap_strct->end_stack_b = NULL;
    swap_strct->num_a = 0;
    swap_strct->num_b = 0;
    swap_strct->oper_cnt = 0;
	return ;
}

int     ft_isnum(char *str)
{
    int num;
    
    num = 0;
    if (*str == '-')
        str++;
    while (*str && ft_isdigit(*str))
    {
        num = 1;
        str++;
    }
    if (*str != '\0' && !ft_isdigit(*str))
        num = 0;
    if (num == 0)
        err();
    return (num);
}*/

/*int	get_next_line(char **line)
{
	int			i;
	int			rd;
	char		ch;
	static char	buffer[0];

	i = 0;
	*line = buffer;
	rd = read(0, &ch, 1);
	while (rd > 0 && ch != '\n')
	{
		buffer[i++] = ch;
		rd = read(0, &ch, 1);
	}
	buffer[i] = '\0';
	return (rd);
}

void	form_stack_a(t_strct *swap_strct)
{
	int	n;

	n = swap_strct->num_b;
	while (n--)
		pa(swap_strct);
	return ;
}

void	free_res(t_strct *swap_strct)
{
	stack_clear(swap_strct->begin_stack_a);
	stack_clear(swap_strct->begin_stack_b);
	free (swap_strct);
	exit (1);
}

void	init_struct(t_strct *swap_strct)
{
	swap_strct->begin_stack_a = NULL;
    swap_strct->begin_stack_b = NULL;
    swap_strct->end_stack_a = NULL;
    swap_strct->end_stack_b = NULL;
    swap_strct->num_a = 0;
    swap_strct->num_b = 0;
    swap_strct->nextpoint = 0;
    swap_strct->maxpoint = 0;
    swap_strct->midpoint = 0;
    swap_strct->curr_group = 0;
    swap_strct->oper_cnt = 0;
	return ;
}

void    sa(t_strct *swap_strct)//поменять местами первые два значения
{
    swap_lst(&(swap_strct->begin_stack_a), &(swap_strct->end_stack_a));
    swap_strct->oper_cnt++;
    write(1, "sa\n", 3);
    return;
}

void    sb(t_strct *swap_strct)
{
    swap_lst(&(swap_strct->begin_stack_b), &(swap_strct->end_stack_b));
    swap_strct->oper_cnt++;
    write(1, "sb\n", 3);
    return;
}

void    ss(t_strct *swap_strct)
{
    swap_lst(&(swap_strct->begin_stack_a), &(swap_strct->end_stack_a));
    swap_lst(&(swap_strct->begin_stack_b), &(swap_strct->end_stack_b));
    swap_strct->oper_cnt = swap_strct->oper_cnt + 2;
    write(1, "ss\n", 3);
}

void    ra(t_strct *swap_strct)//сдвинуть вверх все элементы стека а на 1
{
    forw_rot(&(swap_strct->begin_stack_a), &(swap_strct->end_stack_a));
    swap_strct->oper_cnt++;
    write(1, "ra\n", 3);
    return;
}

void	rra(t_strct *swap_strct)
{
	revs_rot(&(swap_strct->begin_stack_a), &(swap_strct->end_stack_a));
	swap_strct->oper_cnt++;
    write(1, "rra\n", 4);
	return ;
}

void    rb(t_strct *swap_strct)//сдвинуть вверх все элементы стека b на 1
{
    forw_rot(&(swap_strct->begin_stack_b), &(swap_strct->end_stack_b));
    swap_strct->oper_cnt++;
    return;
}

void    rr(t_strct *swap_strct)
{
    forw_rot(&(swap_strct->begin_stack_a), &(swap_strct->end_stack_a));
    forw_rot(&(swap_strct->begin_stack_b), &(swap_strct->end_stack_b));
    swap_strct->oper_cnt = swap_strct->oper_cnt + 2;
    return ;
}

void	rrb(t_strct *swap_strct)
{
	revs_rot(&(swap_strct->begin_stack_b), &(swap_strct->end_stack_b));
	swap_strct->oper_cnt++;
    write(1, "rrb\n", 4);
	return ;
}

void    rrr(t_strct *swap_strct)
{
    revs_rot(&(swap_strct->begin_stack_a), &(swap_strct->end_stack_a));
    revs_rot(&(swap_strct->begin_stack_b), &(swap_strct->end_stack_b));
	swap_strct->oper_cnt = swap_strct->oper_cnt + 2;
	return ;
}

void    pa(t_strct  *swap_strct)
{
	move_lst(&(swap_strct->begin_stack_b), &(swap_strct->end_stack_b),
		&(swap_strct->begin_stack_a), &(swap_strct->end_stack_a));
    swap_strct->num_a += 1;
    swap_strct->num_b -= 1;
    swap_strct->oper_cnt++;
    write(1, "pa\n", 3);
    return ;
}

void    pb(t_strct  *swap_strct)
{
	move_lst(&(swap_strct->begin_stack_a), &(swap_strct->end_stack_a),
		&(swap_strct->begin_stack_b), &(swap_strct->end_stack_b));
    swap_strct->num_b += 1;
    swap_strct->num_a -= 1;
    swap_strct->oper_cnt++;
    write(1, "pb\n", 3);
    return ;
}

void	revs_rot(t_lst **begin, t_lst **end_a)//поднять последний элемент вверх стека
{
    //t_lst   *tmp;
    t_lst   *ptr;
    //t_lst   *start;

    if (*begin == NULL && *end_a == NULL)
		return ;
    //tmp = *end_a;
    *begin = *end_a;
    ptr = (*end_a)->next;
    while (ptr)
	{
		if (ptr->next == (*end_a))
        {
			(*end_a) = ptr;
            ptr = NULL;
        }
        else 
            ptr = ptr->next;
	}
    return ;
}

void	forw_rot(t_lst **begin, t_lst **end_a)
{
	if (*begin == NULL && *end_a == NULL)
		return ;
	*begin = (*begin)->next;
	*end_a = (*end_a)->next;
	return ;
}

void    swap_lst(t_lst **begin, t_lst **end_a)//поменять местами первые два элемента
{
    t_lst *tmp_1;
    t_lst *tmp_2;
    t_lst *tmp_3;

    if (*begin == NULL && *end_a == NULL)
        return;
    tmp_2 = (*begin)->next;
    tmp_3 = tmp_2->next;
    tmp_1 = *begin;
    if (tmp_2 == (*end_a))
        {
            *begin = (*begin)->next;
            *end_a = tmp_1;
            return ;
        }
    *begin = (*begin)->next;
    (*end_a)->next = *begin;
    (*begin)->next = tmp_1;
    (*begin)->next->next = tmp_3;
    return;
}

void    move_lst(t_lst  **begin_stack_a, t_lst  **end_stack_a, 
        t_lst  **begin_stack_b, t_lst  **end_stack_b)
{
    t_lst   *tmp;

    if (*begin_stack_a == NULL && *end_stack_a== NULL)
        return ;
    tmp = *begin_stack_a;
    if (*begin_stack_b)
        tmp = *begin_stack_b;
    *begin_stack_b = *begin_stack_a;
    *begin_stack_a = (*begin_stack_a)->next;
    (*end_stack_a)->next = *begin_stack_a;
    if (*begin_stack_a == *begin_stack_b)
    {
        *begin_stack_a = NULL;
        *end_stack_a = NULL;
    }
    if (!*end_stack_b)
        *end_stack_b = *begin_stack_b;
    (*begin_stack_b)->next = tmp;
    (*end_stack_b)->next = *begin_stack_b;
    return ;
}

int checkin(t_strct *swap_strct, char *line, int len)
{
    if (!ft_strncmp(line, "sa", len))
	    sa(swap_strct);
    else if (!ft_strncmp(line, "sb", len))
		sb(swap_strct);
	else if (!ft_strncmp(line, "ss", len))
		ss(swap_strct);
	else if (!ft_strncmp(line, "pa", len))
		pa(swap_strct);
	else if (!ft_strncmp(line, "pb", len))
		pb(swap_strct);
	else if (!ft_strncmp(line, "ra", len))
		ra(swap_strct);
	else if (!ft_strncmp(line, "rra", len))
		rra(swap_strct);
	else if (!ft_strncmp(line, "rb", len))
		rb(swap_strct);
	else if (!ft_strncmp(line, "rrb", len))
		rrb(swap_strct);
	else if (!ft_strncmp(line, "rr", len))
		rr(swap_strct);
	else if (!ft_strncmp(line, "rrr", len))
		rrr(swap_strct);
	else
		return (0);
	return (1);
}

int ft_checker(t_strct *swap_strct)
{
    char *line;
    int len;

    line = NULL;
    while (get_next_line(&line) > 0)
    {
        len = ft_strlen(line);
        if (!checkin(swap_strct, line, len))
        {
			write(2, "Error\n", 6);
			return (0);
        }
    }
    return (1);
}

void    atob_proc(t_strct *swap_strct)//dopisat
{
    int d_group;
    
    swap_strct->maxpoint = swap_strct->num_a;
    swap_strct->midpoint = ((swap_strct->maxpoint - swap_strct->nextpoint)/2) + swap_strct->nextpoint;
    d_group = d_check(swap_strct->begin_stack_a);//сколько чисел относится к этой группе
    swap_strct->curr_group = swap_strct->begin_stack_a->group;
    if (!check_a_stack(swap_strct) || !check_a_stack_hard(swap_strct, d_group))
    {
        sort_ab(swap_strct, d_group);
        step_exec(swap_strct);
    }
    check_a_stack(swap_strct);
    stack_proc_btoa(swap_strct);
}

void	btoa_proc(t_strct *swap_strct)
{
	int	d_group;

	while (swap_strct->begin_stack_a->group > 0)
	{
		d_group = d_check(swap_strct->begin_stack_a);
		if (!check_a_stack_hard(swap_strct, d_group))
		{
			swap_strct->midpoint = swap_strct->nextpoint + d_group - 1;
			while (d_group--)
				pb(swap_strct);
			swap_strct->curr_group = swap_strct->begin_stack_a->group;
			stack_proc_btoa(swap_strct);
		}
	}
}

void    ft_process(t_strct *swap_strct)
{
    t_lst   *pointer;
    //t_lst   *start;
    t_lst   *tmp;
    t_lst   *lst;
    int k;

    lst = swap_strct->begin_stack_a;
    tmp = swap_strct->begin_stack_a;
    pointer = swap_strct->begin_stack_a; 
    //start = tmp; 
    while (pointer)
    {
        k = lst->value;
        lst->index = ft_index_elem(pointer, k);
        if (pointer->next != tmp)
            pointer = pointer->next;
        else
            pointer = NULL;
        lst = pointer;
    }
    swap_strct->nextpoint = 1;
    while (swap_strct->begin_stack_a->group > -1)
    {
        atob_proc(swap_strct);
        btoa_proc(swap_strct);
    }
}

int     read_arr_1(int argc, char **argv, t_strct *swap_strct)//читает массив
{
    int     i;
    t_lst   *lst;

    lst = NULL;
    i = 0;
    while (i < argc - 1)//пока есть что парсить
    {
        i++;
        if (!ft_parser(swap_strct, argv[i], &lst))
            {
                write(2, "ERROR\n", 6);
                return (0);
            }
    }
    (swap_strct->begin_stack_a)->next = swap_strct->end_stack_a;//ссылку на последний лист сохраняем в структуру свап конец стека а
    return (1);
}

int     main(int argc, char **argv)
{
    t_strct *swap_strct;
    
    if (argc != 1)
    {
        swap_strct = (t_strct *)malloc(sizeof(t_strct));
        if (!swap_strct)
            return (0);
        init_struct(swap_strct);
        if (read_arr_1(argc, argv, swap_strct))
        {
            if (!ft_checker(swap_strct))
                free_res(swap_strct);
            if (!check_seq(swap_strct->begin_stack_a) && swap_strct->begin_stack_b == NULL && swap_strct->end_stack_b == NULL)
                write (1, "OK\n", 3);
            else
                write (1, "KO\n", 3);
        }
        free_res(swap_strct);
    }
    return (0);
}*/