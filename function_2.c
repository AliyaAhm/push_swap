/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <oshelba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 09:39:47 by oshelba           #+#    #+#             */
/*   Updated: 2022/03/06 09:44:28 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	double_check(char **arr)
{
	int	i;
	int	j;
	int	num_1;
	int	num_2;

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

int	read_arr(int argc, char **argv, t_strct *swap_strct)
{
	int		i;
	t_lst	*lst;

	lst = NULL;
	i = 0;
	while (i < argc - 1)
	{
		i++;
		if (!ft_parser(swap_strct, argv[i], &lst))
			return (0);
	}
	return (1);
}

int	check_seq(t_lst *stack)
{
	t_lst	*pointer;
	t_lst	*start;
	int		prev_val;
	int		curr_val;

	if (!stack)
		return (0);
	pointer = stack;
	start = stack;
	prev_val = (stack)->value;
	while (pointer)
	{
		if (pointer->next != start)
			pointer = pointer->next;
		else
			pointer = NULL;
		curr_val = (stack)->value;
		if (curr_val < prev_val)
			return (1);
		prev_val = curr_val;
		stack = pointer;
	}
	return (0);
}

void	step_exec(t_strct *swap_strct)
{
	int	step;

	step = d_check(swap_strct->begin_stack_a);
	step = swap_strct->num_a - step;
	while (step)
	{
		step--;
		rra(swap_strct, 1);
	}
	return ;
}

void	free_arr(char **arr, int flag)
{
	while (*arr)
	{
		free(*arr);
		arr++;
	}
	if (flag != 0)
		ft_putstr_fd("ERROR\n", 2);
	return ;
}
