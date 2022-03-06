/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <oshelba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 09:34:50 by oshelba           #+#    #+#             */
/*   Updated: 2022/03/06 09:36:06 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

char	ft_atoi_ch(const char *str, long int *nmbr)
{
	int					sign;

	sign = 1;
	*nmbr = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -sign;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		*nmbr = *nmbr * 10 + (*str - '0');
		str++;
	}
	*nmbr = *nmbr * sign;
	if (*nmbr > 2147483647)
		return ('H');
	else if (*nmbr < -2147483648)
		return ('L');
	else
		return ('K');
}

int	ft_index_elem(t_lst *lst, int k)
{
	t_lst	*pointer;
	t_lst	*start;
	int		value;
	int		index;

	index = 1;
	start = lst;
	pointer = lst->next;
	while (pointer)
	{
		value = pointer->value;
		if (value < k)
			index++;
		if (pointer->next != start)
			pointer = pointer->next;
		else
			pointer = NULL;
	}
	return (index);
}

void	set_groups(t_lst *lst, int num)
{
	while (num)
	{
		lst->group = -1;
		lst = lst->next;
		num--;
	}
	return ;
}

void	stack_clear(t_lst *lst)
{
	t_lst	*pointer;
	t_lst	*start;

	if (!lst)
		return ;
	start = lst;
	pointer = lst;
	while (pointer)
	{
		if (pointer->next != start)
			pointer = pointer->next;
		else
			pointer = NULL;
		if (lst)
			free (lst);
		lst = pointer;
	}
	return ;
}
