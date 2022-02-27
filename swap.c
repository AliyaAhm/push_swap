#include <stdio.h>
#include "push_swap.h"

void	swapa_3_hard(t_strct *swap_strct, int flag)
{
	if (flag == 1)
		sa(swap_strct, 1);
	else if (flag == 2)
	{
		pb(swap_strct, 1);
		sa(swap_strct, 1);
		move_sort(swap_strct);
		pa(swap_strct, 1);
	}
	else if (flag == 3)
	{
		pb(swap_strct, 1);
		move_sort(swap_strct);
		pa(swap_strct, 1);
	}
	else if (flag == 4)
	{
		move_sort(swap_strct);
		sa(swap_strct, 1);
	}
	return ;
}

void	swapa_3_hard_sit_5(t_strct *swap_strct)
{
	pb(swap_strct, 1);
	sa(swap_strct, 1);
	move_sort(swap_strct);
	pa(swap_strct, 1);
	return ;
}

void	swapb_3_l(t_strct *swap_strct, int c)
{
	if (c == 1)
	{
		rrb(swap_strct, 1);
		pa(swap_strct, 1);
		pa(swap_strct, 1);
		pa(swap_strct, 1);
	}
	if (c == 2)
	{
		pa(swap_strct, 1);
		pa(swap_strct, 1);
		pa(swap_strct, 1);
	}
	if (c == 3)
	{
		pa(swap_strct, 1);
		sb(swap_strct, 1);
		pa(swap_strct, 1);
		pa(swap_strct, 1);
	}
	return ;
}

void	swapb_3_l_2(t_strct *swap_strct, int c)
{
	if (c == 4)
	{
		rb(swap_strct, 1);
		pa(swap_strct, 1);
		pa(swap_strct, 1);
		pa(swap_strct, 1);
	}
	if (c == 5)
	{
		sb(swap_strct, 1);
		pa(swap_strct, 1);
		pa(swap_strct, 1);
		pa(swap_strct, 1);
	}
	if (c == 6)
	{
		rrb(swap_strct, 1);
		pa(swap_strct, 1);
		rrb(swap_strct, 1);
		pa(swap_strct, 1);
		pa(swap_strct, 1);
	}
	return ;
}
