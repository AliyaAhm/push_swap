/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_s_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <oshelba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 09:35:14 by oshelba           #+#    #+#             */
/*   Updated: 2022/03/06 09:36:06 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_strct *swap_strct, int flag)
{
	swap_lst(&(swap_strct->begin_stack_a), &(swap_strct->end_stack_a));
	swap_strct->oper_cnt++;
	if (flag == 1)
		write(1, "sa\n", 3);
	return ;
}

void	sb(t_strct *swap_strct, int flag)
{
	swap_lst(&(swap_strct->begin_stack_b), &(swap_strct->end_stack_b));
	swap_strct->oper_cnt++;
	if (flag == 1)
		write(1, "sb\n", 3);
	return ;
}

void	ss(t_strct *swap_strct, int flag)
{
	swap_lst(&(swap_strct->begin_stack_a), &(swap_strct->end_stack_a));
	swap_lst(&(swap_strct->begin_stack_b), &(swap_strct->end_stack_b));
	swap_strct->oper_cnt = swap_strct->oper_cnt + 2;
	if (flag == 1)
		write(1, "ss\n", 3);
	return ;
}

void	pa(t_strct *swap_strct, int flag)
{
	move_lst(&(swap_strct->begin_stack_b), &(swap_strct->end_stack_b),
		&(swap_strct->begin_stack_a), &(swap_strct->end_stack_a));
	swap_strct->num_a += 1;
	swap_strct->num_b -= 1;
	swap_strct->oper_cnt++;
	if (flag == 1)
		write(1, "pa\n", 3);
	return ;
}

void	pb(t_strct *swap_strct, int flag)
{
	move_lst(&(swap_strct->begin_stack_a), &(swap_strct->end_stack_a),
		&(swap_strct->begin_stack_b), &(swap_strct->end_stack_b));
	swap_strct->num_b += 1;
	swap_strct->num_a -= 1;
	swap_strct->oper_cnt++;
	if (flag == 1)
		write(1, "pb\n", 3);
	return ;
}
