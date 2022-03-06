/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <oshelba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 09:35:51 by oshelba           #+#    #+#             */
/*   Updated: 2022/03/06 09:36:02 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	stacka_is_sorted(t_strct *swap_strct)
{
	int		len;
	t_lst	*tmp;

	tmp = swap_strct->begin_stack_a;
	len = swap_strct->num_a;
	while (len)
	{
		len--;
		if (tmp->group != -1)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	move_sort(t_strct *swap_strct)
{
	if (!stacka_is_sorted(swap_strct) && swap_strct->num_a > 3)
	{
		while (swap_strct->begin_stack_a->index == swap_strct->nextpoint)
		{
			swap_strct->begin_stack_a->group = -1;
			swap_strct->nextpoint++;
			ra(swap_strct, 1);
		}
	}
	return ;
}

int	sort_ab(t_strct *swap_strct, int d_group)
{
	int	i;
	int	key;
	int	s_len;

	key = swap_strct->midpoint;
	s_len = d_group;
	while (s_len--)
	{
		i = swap_strct->begin_stack_a->index;
		if (i <= key)
			pb(swap_strct, 1);
		else
			ra(swap_strct, 1);
	}
	return (0);
}

int	sort_ba(t_strct *swap_strct)
{
	int	i;
	int	key;
	int	s_len;

	back_track_b(swap_strct);
	key = swap_strct->midpoint;
	s_len = swap_strct->num_b;
	while (s_len--)
	{
		i = swap_strct->begin_stack_b->index;
		swap_strct->begin_stack_b->group = swap_strct->curr_group;
		if (i > key)
			pa(swap_strct, 1);
		else
			rb(swap_strct, 1);
	}
	return (0);
}

void	free_res(t_strct *swap_strct)
{
	stack_clear(swap_strct->begin_stack_a);
	stack_clear(swap_strct->begin_stack_b);
	free (swap_strct);
	exit (1);
}
