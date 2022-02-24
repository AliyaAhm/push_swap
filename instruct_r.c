#include "push_swap.h"

void	ra(t_strct *swap_strct)
{
	forw_rot(&(swap_strct->begin_stack_a), &(swap_strct->end_stack_a));
	swap_strct->oper_cnt++;
	write(1, "ra\n", 3);
	return ;
}

void	rra(t_strct *swap_strct)
{
	revs_rot(&(swap_strct->begin_stack_a), &(swap_strct->end_stack_a));
	swap_strct->oper_cnt++;
	write(1, "rra\n", 4);
	return ;
}

void	rb(t_strct *swap_strct)
{
	forw_rot(&(swap_strct->begin_stack_b), &(swap_strct->end_stack_b));
	swap_strct->oper_cnt++;
	return ;
}

void	rr(t_strct *swap_strct)
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
