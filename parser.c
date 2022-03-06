/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <oshelba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 09:35:37 by oshelba           #+#    #+#             */
/*   Updated: 2022/03/06 09:36:06 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*init_new_lst(int val)
{
	t_lst	*new_elem;

	new_elem = (t_lst *)malloc(sizeof(t_lst));
	if (!new_elem)
		return (NULL);
	new_elem->index = 0;
	new_elem->flag = 0;
	new_elem->value = val;
	new_elem->group = 0;
	new_elem->next = NULL;
	return (new_elem);
}

int	ft_parser(t_strct *swap_strct, char *argv, t_lst **lst)
{
	char	**arr;
	int		i;
	int		flag;

	i = 0;
	flag = 1;
	arr = ft_split(argv, ' ');
	while (arr[i])
	{
		if (!ft_isnum(arr[i]) || !ft_proc_seq(swap_strct, lst, arr[i]) \
				|| duplcheck(swap_strct->end_stack_a))
			flag = 0;
		swap_strct->num_a = swap_strct->num_a + 1;
		i++;
	}
	while (i--)
		free (arr[i]);
	free (arr);
	return (flag);
}

int	ft_isnum(char *str)
{
	int	num;

	num = 0;
	if (*str == '-')
		str++;
	while (*str && ft_isdigit(*str))
	{
		num = 1;
		str++;
	}
	if (*str != '\0' && !ft_isdigit(*str))
		num = 0;
	if (num == 0)
		ft_putstr_fd("ERROR\n", 2);
	return (num);
}

int	ft_proc_seq(t_strct *swap_strct, t_lst **lst, char *str_ar)
{
	long int	value;
	t_lst		*new_node;
	int			flag;

	flag = 1;
	if ((ft_atoi_ch(str_ar, &value)) != 'K')
	{
		ft_putstr_fd("ERROR\n", 2);
		flag = 0;
	}
	new_node = NULL;
	new_node = init_new_lst(value);
	if (*lst)
		(*lst)->next = new_node;
	*lst = new_node;
	if (!swap_strct->begin_stack_a)
		swap_strct->begin_stack_a = new_node;
	new_node->next = swap_strct->begin_stack_a;
	swap_strct->end_stack_a = new_node;
	return (flag);
}

int	duplcheck(t_lst *lst)
{
	t_lst	*ptr;
	t_lst	*end;
	int		m_dup;

	if (!lst)
		return (0);
	m_dup = lst->value;
	end = lst;
	ptr = lst->next;
	while (ptr != end && ptr)
	{
		lst = ptr;
		if (ptr->next != end)
			ptr = ptr->next;
		else
			ptr = NULL;
		if (m_dup == lst->value)
		{
			ft_putstr_fd("ERROR\n", 2);
			return (1);
		}
	}
	return (0);
}
