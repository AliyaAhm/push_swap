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
		lst = swap_strct->end_stack_a;
	}
	return (1);
}

int	check_seq(t_lst *stack_a)
{
	t_lst	*pointer;
	t_lst	*start;
	int		prev_val;
	int		curr_val;

	if (!stack_a)
		return (0);
	pointer = stack_a;
	start = stack_a;
	prev_val = (stack_a)->value;
	while (pointer)
	{
		if (pointer->next != start)
			pointer = pointer->next;
		else
			pointer = NULL;
		curr_val = (stack_a)->value;
		if (curr_val < prev_val)
			return (1);
		prev_val = curr_val;
		stack_a = pointer;
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
		rra(swap_strct);
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
