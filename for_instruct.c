/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_instruct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <oshelba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 09:34:27 by oshelba           #+#    #+#             */
/*   Updated: 2022/03/06 09:36:06 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	swap_lst(t_lst **begin, t_lst **end_a)
{
	t_lst	*tmp_1;
	t_lst	*tmp_2;
	t_lst	*tmp_3;

	if (*begin == NULL && *end_a == NULL)
		return ;
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

void	revs_rot(t_lst **begin, t_lst **end_a)
{
	t_lst	*ptr;

	if (*begin == NULL && *end_a == NULL)
		return ;
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

void	move_lst(t_lst **begin_stack_a, t_lst **end_stack_a,
		t_lst **begin_stack_b, t_lst **end_stack_b)
{
	t_lst	*tmp;

	if (*begin_stack_a == NULL && *end_stack_a == NULL)
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

void	rrr(t_strct *swap_strct, int flag)
{
	revs_rot(&(swap_strct->begin_stack_a), &(swap_strct->end_stack_a));
	revs_rot(&(swap_strct->begin_stack_b), &(swap_strct->end_stack_b));
	swap_strct->oper_cnt = swap_strct->oper_cnt + 2;
	while (flag == 1)
		write(1, "rrr\n", 4);
	return ;
}
