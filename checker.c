#include <fcntl.h>
#include "push_swap.h"

int	get_next_line(char **line)
{
	int			i;
	int			rd;
	char		ch;
	static char	buffer[0];

	i = 0;
	*line = buffer;
	rd = read(0, &ch, 1);
	while (rd > 0 && ch != '\n')
	{
		buffer[i++] = ch;
		rd = read(0, &ch, 1);
	}
	buffer[i] = '\0';
	return (rd);
}

int	checkin(t_strct *swap_strct, char *line, int len)
{
	if (!ft_strncmp(line, "sa", len))
		sa(swap_strct, 0);
	else if (!ft_strncmp(line, "sb", len))
		sb(swap_strct, 0);
	else if (!ft_strncmp(line, "ss", len))
		ss(swap_strct, 0);
	else if (!ft_strncmp(line, "pa", len))
		pa(swap_strct, 0);
	else if (!ft_strncmp(line, "pb", len))
		pb(swap_strct, 0);
	else if (!ft_strncmp(line, "ra", len))
		ra(swap_strct, 0);
	else if (!ft_strncmp(line, "rra", len))
		rra(swap_strct, 0);
	else if (!ft_strncmp(line, "rb", len))
		rb(swap_strct, 0);
	else if (!ft_strncmp(line, "rrb", len))
		rrb(swap_strct, 0);
	else if (!ft_strncmp(line, "rr", len))
		rr(swap_strct, 0);
	else if (!ft_strncmp(line, "rrr", len))
		rrr(swap_strct, 0);
	else
		return (0);
	return (1);
}

int	ft_checker(t_strct *swap_strct)
{
	char	*line;
	int		len;

	line = NULL;
	while (get_next_line(&line) > 0)
	{
		len = ft_strlen(line);
		if (!checkin(swap_strct, line, len))
		{
			write(2, "Error\n", 6);
			return (0);
		}
	}
	return (1);
}

int	read_arr_1(int argc, char **argv, t_strct *swap_strct)
{
	int		i;
	t_lst	*lst;

	lst = NULL;
	i = 0;
	while (i < argc - 1)
	{
		i++;
		if (!ft_parser(swap_strct, argv[i], &lst))
		{
			write(2, "ERROR\n", 6);
			return (0);
		}
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_strct	*swap_strct;

	if (argc != 1)
	{
		swap_strct = (t_strct *)malloc(sizeof(t_strct));
		if (!swap_strct)
			return (0);
		init_struct(swap_strct);
		if (read_arr_1(argc, argv, swap_strct))
		{
			if (!ft_checker(swap_strct))
			{
				free_res(swap_strct);
			}
			if (!check_seq(swap_strct->begin_stack_a) && \
				swap_strct->begin_stack_b == NULL && \
				swap_strct->end_stack_b == NULL)
				write (1, "OK\n", 3);
			else
				write (1, "KO\n", 3);
		}
		free_res(swap_strct);
	}
	return (0);
}
