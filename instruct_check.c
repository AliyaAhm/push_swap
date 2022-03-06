/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <oshelba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 09:35:03 by oshelba           #+#    #+#             */
/*   Updated: 2022/03/06 09:36:06 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check3a_l(t_strct *swap_strct)
{
	int	abc[3];

	abc[0] = swap_strct->begin_stack_a->value;
	abc[1] = swap_strct->begin_stack_a->next->value;
	abc[2] = swap_strct->begin_stack_a->next->next->value;
	if (abc[0] > abc[1] && abc[0] < abc[2])
		sa(swap_strct, 1);
	else if (abc[1] < abc[0] && abc[1] > abc[2])
	{
		sa(swap_strct, 1);
		rra(swap_strct, 1);
	}
	else if (abc[2] < abc[0] && abc[2] > abc[1])
		ra(swap_strct, 1);
	else if (abc[2] > abc[0] && abc[2] < abc[1])
	{
		sa(swap_strct, 1);
		ra(swap_strct, 1);
	}
	else if (abc[0] < abc[1] && abc[0] > abc[2])
		rra(swap_strct, 1);
	return (1);
}

int	check3a_h(t_strct *swap_strct)
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

int	check_a_stack_hard(t_strct *swap_strct, int d_group)
{
	int	flag;

	flag = 0;
	if (d_group <= 3)
	{
		if (d_group == 2)
		{
			if (swap_strct->begin_stack_a->value > \
			swap_strct->begin_stack_a->next->value)
				sa(swap_strct, 1);
		}
		else if (d_group == 3)
			check3a_h(swap_strct);
		flag = 1;
	}
	move_sort(swap_strct);
	d_group = d_check(swap_strct->begin_stack_a);
	return (flag);
}

int	check_a_stack(t_strct *swap_strct)
{
	int	flag;

	flag = 0;
	if (swap_strct->num_a <= 3)
	{
		set_groups(swap_strct->begin_stack_a, swap_strct->num_a);
		if (swap_strct->num_a == 2)
		{
			if (swap_strct->begin_stack_a->value > \
			swap_strct->begin_stack_a->next->value)
				sa(swap_strct, 1);
		}
		else if (swap_strct->num_a == 3)
			check3a_l(swap_strct);
		flag = 1;
	}
	return (flag);
}
