#include "push_swap.h"

void	ft_process(t_strct *swap_strct)
{
	t_lst	*pointer;
	t_lst	*tmp;
	t_lst	*lst;
	int		k;

	lst = swap_strct->begin_stack_a;
	tmp = swap_strct->begin_stack_a;
	pointer = swap_strct->begin_stack_a;
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

void	atob_proc(t_strct *swap_strct)
{
	int	d_group;

	swap_strct->maxpoint = swap_strct->num_a;
	swap_strct->midpoint = ((swap_strct->maxpoint - swap_strct->nextpoint)
			/ 2 ) + swap_strct->nextpoint;
	d_group = d_check(swap_strct->begin_stack_a);
	swap_strct->curr_group = swap_strct->begin_stack_a->group;
	if (!check_a_stack(swap_strct) || \
		 !check_a_stack_hard(swap_strct, d_group))
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
				pb(swap_strct, 1);
			swap_strct->curr_group = swap_strct->begin_stack_a->group;
			stack_proc_btoa(swap_strct);
		}
	}
}

int	d_check(t_lst *lst)
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
			return (cnt);
		cnt++;
		lst = ptr;
	}
	return (cnt);
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
