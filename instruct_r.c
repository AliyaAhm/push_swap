#include "push_swap.h"

void	ra(t_strct *swap_strct, int flag)
{
	forw_rot(&(swap_strct->begin_stack_a), &(swap_strct->end_stack_a));
	swap_strct->oper_cnt++;
	if (flag == 1)
		write(1, "ra\n", 3);
	return ;
}

void	rra(t_strct *swap_strct, int flag)
{
	revs_rot(&(swap_strct->begin_stack_a), &(swap_strct->end_stack_a));
	swap_strct->oper_cnt++;
	if (flag == 1)
		write(1, "rra\n", 4);
	return ;
}

void	rb(t_strct *swap_strct, int flag)
{
	forw_rot(&(swap_strct->begin_stack_b), &(swap_strct->end_stack_b));
	swap_strct->oper_cnt++;
	if (flag == 1)
		write(1, "rb\n", 4);
	return ;
}

void	rr(t_strct *swap_strct, int flag)
{
	forw_rot(&(swap_strct->begin_stack_a), &(swap_strct->end_stack_a));
	forw_rot(&(swap_strct->begin_stack_b), &(swap_strct->end_stack_b));
	swap_strct->oper_cnt = swap_strct->oper_cnt + 2;
	if (flag == 1)
		write(1, "rr\n", 4);
	return ;
}

void	rrb(t_strct *swap_strct, int flag)
{
	revs_rot(&(swap_strct->begin_stack_b), &(swap_strct->end_stack_b));
	swap_strct->oper_cnt++;
	if (flag == 1)
		write(1, "rrb\n", 4);
	return ;
}
