#include <stdio.h>
#include "push_swap.h"

int	check3b_l(t_strct *swap_strct)
{
	int	abc[3];

	abc[0] = swap_strct->begin_stack_b->value;
	abc[1] = swap_strct->begin_stack_b->next->value;
	abc[2] = swap_strct->begin_stack_b->next->next->value;
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

int	check_b_stack(t_strct *swap_strct)
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
			if (swap_strct->begin_stack_b->value < \
					swap_strct->begin_stack_b->next->value)
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

int	check_stack_b_seq(t_lst *lst, int stack_len, char c)
{
	int	curr_value;
	int	prev_value;

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

int	back_track_b(t_strct *swap_strct)
{	
	int	s_len;

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

void	stack_proc_btoa(t_strct *swap_strct)
{
	while (swap_strct->num_b > 3)
	{
		swap_strct->maxpoint = swap_strct->midpoint;
		swap_strct->midpoint
			= ((swap_strct->maxpoint - swap_strct->nextpoint) / 2)
			+ swap_strct->nextpoint;
		swap_strct->curr_group++;
		sort_ba(swap_strct);
	}
	check_b_stack(swap_strct);
	return ;
}
