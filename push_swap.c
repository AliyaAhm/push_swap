#include <stdio.h>
#include "libft/libft.h"
#include "push_swap.h"

/*char **get_line(char **argv)
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
}*/

void    err()
{
    ft_putstr_fd("ERROR\n", 2);
}

void    free_arr(char **arr, int flag)
{
    while (*arr)
    {
        free(*arr);
        arr++;
    }
    if (flag != 0)
        err();
    return ;
}

void    double_check(char **arr)// повторяемость чисел
{
    int i;
    int j;
    int num_1;
    int num_2;

    i = 0;
    while (arr[i])
    {
        num_1 = ft_atoi(arr[i]);
        j = i + 1;
        while (arr[j])
        {
            num_2 = ft_atoi(arr[j]);
            if (num_1 == num_2)
                free_arr(arr, 1);
            j++;
        }
        i++;
    }
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

t_lst   *init_new_lst(int val)
{
    t_lst *new_elem;

    new_elem = (t_lst *)malloc(sizeof(t_lst));
    if (!new_elem)
        return (NULL);
    new_elem->index = 0;
    new_elem->flag = 0;
    new_elem->value = val;
    new_elem->group = 0;
    new_elem->next = NULL;
    return (new_elem);
}

char    ft_atoi_ch(const char *str, long int *nbr)
{
	int			minus;
	int			i;
	char		*s;

	i = 0;
	minus = 1;
    *nbr = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'\
			|| str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
    s = (char *)str;
    while (ft_isdigit(*str))
    {
        *nbr = *nbr * 10 + (*str - '0');
        str++;
    }
    *nbr = *nbr * minus;
	if (*nbr > 2147483647)
        return('H');
    else if (*nbr < -2147483648)
        return('L');
    else
        return('K');
}
/*
int ft_proc_seq(t_strct *swap_strct, t_lst **lst, char *str_ar)//заполняет стек а новыми значениями
{
    t_lst *new_lst;
    long int val;
    int flag;

    flag = 1;
    if ((ft_atoi_ch(str_ar, &value)) != 'K')
        {
            err();
            flag = 0;
        } 
    new_lst = NULL;
    new_lst = init_new_lst(value);
    if (*lst)
        (*lst)->next = new_lst;
    new_lst->next = *lst;
    if (!swap_strct->begin_stack_a) // если первое значение, то 
        swap_strct->begin_stack_a = new_lst;//сохраняем адрес нового листа
    new_lst->next = swap_strct->begin_stack_a;//кладем в новый лист адрес на начало стека а
    swap_strct->end_stack_a = new_lst;//сохраняем в структуру свап конец стека а - новый лист
    return(flag);    
}*/

int     ft_proc_seq(t_strct *swap_strct, t_lst **lst, char *str_ar)
{
    int         flag;
    long int    value;
    t_lst       *new_node;

    flag = 1;
    if ((ft_atoi_ch(str_ar, &value)) != 'K')
    {
        err();
        flag = 0;
    } 
    new_node = NULL;
    new_node = init_new_lst(value);
    if (*lst)//если не первое число
    {
        (*lst)->next = new_node;
        //*lst = new_node;
    }
    else//если первое число
    {
        *lst = new_node;//lst ссылается на новую структуру
        swap_strct->begin_stack_a = new_node;//запоминаем начала стека
    }
    new_node->next = swap_strct->begin_stack_a;//кладем в последний элемент начало структутуры
    swap_strct->end_stack_a = new_node;//запоминаем конец структуры в свапструктуру
    return (flag);
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
}

int     duplcheck(t_lst *lst)//проверка повторяемости числа
{
    t_lst   *ptr;
    t_lst   *end;
    int     m_dup;

    if (!lst)
        return (0);
    m_dup = lst->value;//текущее значение
    end = lst;//запоминаем конец стека
    ptr = lst->next;// некст указывает на начало списка
    while (ptr != end && ptr)//пока ptr не равно лст
    {
        lst = ptr;
        if (ptr->next != end) //если не достигли конца стека
            ptr = ptr->next;// сдвигаем наш бегунок
        else
            ptr = NULL;//если он достиг конца стека, то присваиваем ему NULL и выходим из цикла
        if (m_dup == lst->value) //сравниваем с текущим значением 
        {
            err();
            return(1);
        }
    }
    return (0);
}

int     ft_parser(t_strct *swap_strct, char *argv, t_lst **lst)
 {
     int i;
     int flag;
     char **arr;

     i = 0;
     flag =1;
     arr = ft_split(argv, ' ');
     while (arr[i])
     {
        if (!ft_isnum(arr[i]) || !ft_proc_seq(swap_strct, lst, arr[i] /*заполняются листы*/)\
        || duplcheck(swap_strct->end_stack_a)/*повторяется ли число*/)
            flag = 0;
        swap_strct->num_a = swap_strct->num_a + 1;//считаем количество чисел в стеке а
        i++;
     }
    while (i--)
        free (arr[i]);
    free (arr);
    return (flag);
}

int     read_arr(int argc, char **argv, t_strct *swap_strct)//читает массив
{
    int     i;
    t_lst   *lst;

    lst = NULL;
    i = 0;
    while (i < argc - 1)//пока есть что парсить
    {
        i++;
        if (!ft_parser(swap_strct, argv[i], &lst))
            return (0);
        lst = swap_strct->end_stack_a;//
    }
    //(swap_strct->begin_stack_a)->next = swap_strct->end_stack_a;//ссылку на последний лист сохраняем в структуру свап конец стека а
    return (1);
}

int     check_seq(t_lst *stack_a)//проверяем последовательность
{
    t_lst   *pointer;
    t_lst   *start;
    int     prev_val;
    int     curr_val;

    if (!stack_a)
        return (0);
    pointer = stack_a;
    start = stack_a;
    prev_val = (stack_a)->value;
    while(pointer)
    {
        if (pointer->next != start) //если у нас не один лист в стеке
            pointer = pointer->next; //то указатель поинтер ссылается на поле некст(переходит к следующему листу)
        else
            pointer = NULL; //если элемент один, то указатель поинтер = нулу
        curr_val = (stack_a)->value;
        if (curr_val < prev_val)
            return (1);
        prev_val = curr_val;
        stack_a = pointer;        
    }
    return (0); // не поняла до конца что делает функция
}

int     ft_index_elem(t_lst *lst, int k) // пирсваиваем индекс каждому числу
{
    t_lst   *pointer;
    t_lst   *start;
    int value;
    int index;

    index = 1;
    start = lst;
    pointer = lst->next;
    while (pointer)
    {
        value = pointer->value;
        if (value < k) 
            index++;
        if (pointer->next != start)
            pointer = pointer->next;
        else
            pointer = NULL;
    }
    return (index);
}

int	    d_check(t_lst *lst)//проверяем к какой группе относится
{
	t_lst	*ptr;
	t_lst	*start;
	int		cnt;
	int		base_group;

	cnt = 0;
	base_group = lst->group;
	start = lst;
	ptr = lst;
	while (ptr)
	{
		if (ptr->next != start)
			ptr = ptr->next;
		else
			ptr = NULL;
		if (lst->group != base_group)
			return (cnt);// сколько чисел относится к этой группе
		cnt++;
		lst = ptr;
	}
	return (cnt);
}

void    set_groups(t_lst *lst, int num)//установка флагов -1 в группу
{
    while (num)
    {
        lst->group = -1;
        lst = lst->next;
        num--;
    }
    return;    
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
    *begin = (*begin)->next;
    (*begin)->next = tmp_1;
    (*begin)->next->next = tmp_3;
    (*end_a)->next = *begin;
    return;
}

void	forw_rot(t_lst **begin, t_lst **end_a)
{
	if (*begin == NULL && *end_a == NULL)
		return ;
	*begin = (*begin)->next;
	*end_a = (*end_a)->next;
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

/*void    take_abc(t_lst *begin_stack_a, int *abc)
{
    abc[0] = begin_stack_a->value;
    abc[1] = begin_stack_a->next->value;
    abc[2] = begin_stack_a->next->next->value;
    return ;
}*/

int     check3a_l(t_strct *swap_strct)
{
	int	abc[3];
	
    abc[0] = swap_strct->begin_stack_a->value;
    abc[1] = swap_strct->begin_stack_a->next->value;
    abc[2] = swap_strct->begin_stack_a->next->next->value;//!!!
	if (abc[0] > abc[1] && abc[0] < abc[2])
		sa(swap_strct);
	else if (abc[1] < abc[0] && abc[1] > abc[2])
	{
		sa(swap_strct);
		rra(swap_strct);
	}
	else if (abc[2] < abc[0] && abc[2] > abc[1])
		ra(swap_strct);
	else if (abc[2] > abc[0] && abc[2] < abc[1])
	{
		sa(swap_strct);
		ra(swap_strct);
	}
	else if (abc[0] < abc[1] && abc[0] > abc[2])
		rra(swap_strct);
	return (1);
}

void    move_sort(t_strct *swap_strct)
{
    t_lst *tmp;
    int len;
    int flag;

    flag = 1;
    tmp = swap_strct->begin_stack_a;
    len = swap_strct->num_a;
    while(len)
    {
        if (tmp->group != -1)
            flag = 0;
        len--;
    }
    if (flag == 0 && swap_strct->num_a > 3)
    {
        while (swap_strct->begin_stack_a->index == swap_strct->nextpoint)
        {
            swap_strct->begin_stack_a->group = -1;
            swap_strct->nextpoint++;
            ra(swap_strct);
        }
    }
    return ;
}

void	swapa_3_hard(t_strct *swap_strct, int flag)
{
    if (flag == 1)
        sa(swap_strct);
	else if (flag == 2)
    {
        pb(swap_strct);
        sa(swap_strct);
        move_sort(swap_strct);
        pa(swap_strct);
    }
    else if (flag == 3)
    {
        pb(swap_strct);
        move_sort(swap_strct);
        pa(swap_strct);
    }
    else if (flag == 4)
    {
        move_sort(swap_strct);
        sa(swap_strct);
    }
    return ;
}

void	swapa_3_hard_sit_5(t_strct *swap_strct)
{
	pb(swap_strct);
	sa(swap_strct);
	move_sort(swap_strct);
	pa(swap_strct);
	return ;
}

int     check3a_h(t_strct *swap_strct)
{
    int	abc[3];
    
    abc[0] = swap_strct->begin_stack_a->value;
    abc[1] = swap_strct->begin_stack_a->next->value;
    abc[2] = swap_strct->begin_stack_a->next->next->value;
    if (abc[0] > abc[1] && abc[0] < abc[2])
		swapa_3_hard(swap_strct, 1);
	else if (abc[1] < abc[0] && abc[1] > abc[2])
		swapa_3_hard(swap_strct, 2);
	else if (abc[2] < abc[0] && abc[2] > abc[1])
		swapa_3_hard(swap_strct, 3);
	else if (abc[2] > abc[0] && abc[2] < abc[1])
		swapa_3_hard(swap_strct, 4);
	else if (abc[0] < abc[1] && abc[0] > abc[2])
		swapa_3_hard_sit_5(swap_strct);
	return (1);
}

int     check_a_stack(t_strct *swap_strct)//
{
    int flag;

    flag = 0;
    if (swap_strct->num_a <= 3)
    {
        set_groups(swap_strct->begin_stack_a, swap_strct->num_a);
        if (swap_strct->num_a == 2)
        {
            if (swap_strct->begin_stack_a->value > swap_strct->begin_stack_a->next->value)//если два элемента просто переворачивает
                sa(swap_strct);
        }
        else if (swap_strct->num_a == 3)
        {
            check3a_l(swap_strct);//!!!!
        }
        flag = 1;
    }
    return (flag);
}

int     check_a_stack_hard(t_strct *swap_strct, int d_group)
{
    int flag;

    flag = 0;
    if (d_group <= 3)
    {
        if (d_group == 2)
        {
            if (swap_strct->begin_stack_a->value > swap_strct->begin_stack_a->next->value)
                sa(swap_strct);
        }
        else if (d_group == 3)
            check3a_h(swap_strct);
        flag = 1;
    }
    move_sort(swap_strct);
    d_group = d_check(swap_strct->begin_stack_a);
    return(flag);
}

int     sort_ab(t_strct *swap_strct, int d_group)
{
    int i;
    int key;
    int s_len;

    key = swap_strct->midpoint;
    s_len = d_group;
    while (s_len--)
    {
        i = swap_strct->begin_stack_a->index;
        if (i <= key)//если индекс меньше середины
            pb(swap_strct);//перекидываем в стек б
        else 
            ra(swap_strct);//просто переворачиваем стек
    }
    return (0);
}

void    step_exec(t_strct *swap_strct)
{
    int step;

    step = d_check(swap_strct->begin_stack_a);
    step = swap_strct->num_a - step;
    while (step)
    {
        rra(swap_strct);
        step--;
    }
    return ;
}

int	    check_stack_b_seq(t_lst *lst, int stack_len, char c)
{
	int		curr_value;
	int		prev_value;

	prev_value = lst->index;
	while (stack_len--)
	{
		curr_value = lst->index;
		if (c == 'd' && curr_value > prev_value)
			return (0);
		if (c == 'a' && curr_value < prev_value)
			return (0);
		prev_value = curr_value;
		lst = lst->next;
	}
	return (1);
}

int	    back_track_b(t_strct *swap_strct)
{
    int s_len;

    s_len = swap_strct->num_b;
    if (check_stack_b_seq(swap_strct->begin_stack_b, s_len, 'd'))
    {
        while (s_len--)
            pa(swap_strct);
        move_sort(swap_strct);
    }
    else if (check_stack_b_seq(swap_strct->begin_stack_b, s_len, 'a'))
    {
        while (s_len--)
        {
            pa(swap_strct);
            move_sort(swap_strct);
        }
    }
    return (0);
}

int	    sort_ba(t_strct *swap_strct)
{
    int i;
    int key;
    int s_len;

    back_track_b(swap_strct);
    key = swap_strct->midpoint;
    s_len = swap_strct->num_b;
    while (s_len--)
    {
        i = swap_strct->begin_stack_b->index;
        swap_strct->begin_stack_b->group = swap_strct->curr_group;
        if (i > key)
            pa(swap_strct);
        else 
            rb(swap_strct);
    }
    return (0);
}

void	swapb_3_l(t_strct *swap_strct, int c)
{
    if (c == 1)
    {
        rrb(swap_strct);
	    pa(swap_strct);
	    pa(swap_strct);
	    pa(swap_strct);
    }
    if (c == 2)
    {
        pa(swap_strct);
	    pa(swap_strct);
	    pa(swap_strct);
    }
    if (c == 3)
    {
	    pa(swap_strct);
	    sb(swap_strct);
	    pa(swap_strct);
	    pa(swap_strct);
    }
    return;
}

void	swapb_3_l_2(t_strct *swap_strct, int c)
{
    if (c == 4)
    {
        rb(swap_strct);
	    pa(swap_strct);
	    pa(swap_strct);
	    pa(swap_strct);
    }
    if (c == 5)
    {
        sb(swap_strct);
	    pa(swap_strct);
	    pa(swap_strct);
	    pa(swap_strct);
    }
    if (c == 6)
    {
        rrb(swap_strct);
	    pa(swap_strct);
	    rrb(swap_strct);
	    pa(swap_strct);
	    pa(swap_strct);
    }
    return ;
}

int	    check3b_l(t_strct *swap_strct)
{
	int	abc[3];

	abc[0] = swap_strct->begin_stack_a->value;
    abc[1] = swap_strct->begin_stack_a->next->value;
    abc[2] = swap_strct->begin_stack_a->next->next->value;
	if (abc[0] > abc[1] && abc[0] < abc[2])
		swapb_3_l(swap_strct, 1);
	else if (abc[1] < abc[0] && abc[1] > abc[2])
		swapb_3_l(swap_strct, 2);
	else if (abc[2] < abc[0] && abc[2] > abc[1])
		swapb_3_l(swap_strct, 3);
	else if (abc[2] > abc[0] && abc[2] < abc[1])
		swapb_3_l_2(swap_strct, 4);
	else if (abc[0] < abc[1] && abc[0] > abc[2])
		swapb_3_l_2(swap_strct, 5);
	else
		swapb_3_l_2(swap_strct, 6);
	return (1);
}

int     check_stack_b(t_strct *swap_strct)
{
	int	flag;

	flag = 0;
	if (swap_strct->num_b <= 3)
	{
		set_groups(swap_strct->begin_stack_b, swap_strct->num_b);
		if (swap_strct->num_b == 1)
			pa(swap_strct);
		else if (swap_strct->num_b == 2)
		{
			if (swap_strct->begin_stack_b->value < swap_strct->begin_stack_b->next->value)
				sb(swap_strct);
			pa(swap_strct);
			pa(swap_strct);
		}
		else if (swap_strct->num_b == 3)
			check3b_l(swap_strct);
		flag = 1;
	}
	move_sort(swap_strct);
	return (flag);
}

void	stack_proc_btoa(t_strct *swap_strct)
{
	while (swap_strct->num_b > 3)
	{
		swap_strct->maxpoint = swap_strct->midpoint;
		swap_strct->midpoint
			= ((swap_strct->maxpoint - swap_strct->nextpoint) / 2)
			+ swap_strct->nextpoint;
		swap_strct->curr_group++;
		sort_ba(swap_strct);//
	}
	check_stack_b(swap_strct);
	return ;
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

/*2*//*
int check_stack_a(t_lst *begin)
{
    t_lst   *pointer;
    t_lst   *start;
    int     v_current;
    int     v_next;

    if (!begin)
        return (0);
    start = begin;
    pointer = begin;
    v_next = lst_value; 
    while (pointer)
    {
        if (pointer->next != start)
            pointer = pointer->next;
        else
            pointer = NULL;
        v_current = (lst)->value;
        if (v_current = )
    }
}*/

void	stack_clear(t_lst *lst)
{
	t_lst	*pointer;
	t_lst	*start;

	if (!lst)
		return ;
	start = lst;
	pointer = lst;
	while (pointer)
	{
		if (pointer->next != start)
			pointer = pointer->next;
		else
			pointer = NULL;
		if (lst)
            free (lst);
		lst = pointer;
	}
	return ;
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
        if (read_arr(argc, argv, swap_strct))
            if (check_seq(swap_strct->begin_stack_a))
                ft_process(swap_strct);
        stack_clear(swap_strct->begin_stack_a);
        stack_clear(swap_strct->begin_stack_b);
        free (swap_strct);
    }
    return (0);
}