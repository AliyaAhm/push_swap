/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshelba <oshelba@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 09:35:45 by oshelba           #+#    #+#             */
/*   Updated: 2022/03/06 09:36:06 by oshelba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_lst
{
	struct s_lst	*next;
	int				index;
	int				flag;
	int				value;
	int				group;
}	t_lst;

typedef struct s_strct
{
	t_lst	*begin_stack_a;
	t_lst	*begin_stack_b;
	t_lst	*end_stack_a;
	t_lst	*end_stack_b;
	int		num_a;
	int		num_b;
	int		nextpoint;
	int		maxpoint;
	int		midpoint;
	int		curr_group;
	int		oper_cnt;
}	t_strct;

/*parser.c*/
t_lst	*init_new_lst(int val);
int		ft_parser(t_strct *swap_strct, char *argv, t_lst **lst);
int		ft_isnum(char *str);
int		ft_proc_seq(t_strct *swap_strct, t_lst **lst, char *str_ar);
int		duplcheck(t_lst *lst);

/*sort.c*/
int		stacka_is_sorted(t_strct *swap_strct);
void	move_sort(t_strct *swap_strct);
int		sort_ab(t_strct *swap_strct, int d_group);
int		sort_ba(t_strct *swap_strct);
/***/

/*ft_process*/
void	ft_process(t_strct *swap_strct);
void	atob_proc(t_strct *swap_strct);
void	btoa_proc(t_strct *swap_strct);
int		d_check(t_lst *lst);
void	init_struct(t_strct *swap_strct);
/***/

/*swap.c*/
void	swapa_3_hard_sit_5(t_strct *p_strct);
void	swapa_3_hard(t_strct *p_strct, int flag);
void	swapb_3_l_2(t_strct *swap_strct, int c);
void	swapb_3_l(t_strct *swap_strct, int c);
/***/
/*instruct_check.c*/
int		check_a_stack(t_strct *swap_strct);
int		check3a_l(t_strct *swap_strct);
int		check_a_stack_hard(t_strct *swap_strct, int d_group);
int		check3a_h(t_strct *swap_strct);
/***/

/*checker.c*/
int		get_next_line(char **line);
void	form_stack_a(t_strct *swap_strct);
void	free_res(t_strct *swap_strct);
int		checkin(t_strct *swap_strct, char *line, int len);
/***/

/*function.c*/
char	ft_atoi_ch(const char *str, long int *nbr);
int		ft_index_elem(t_lst *swap_strct, int k);
void	set_groups(t_lst *lst, int num);
void	stack_clear(t_lst *lst);
void	free_arr(char **arr, int flag);
/***/

/*instruct_s_p.c*/
void	sa(t_strct *swap_strct, int flag);
void	sb(t_strct *swap_strct, int flag);
void	ss(t_strct *swap_strct, int flag);
void	pa(t_strct *swap_strct, int flag);
void	pb(t_strct *swap_strct, int flag);
/***/

/*instruct_r.c*/
void	ra(t_strct *swap_strct, int flag);
void	rra(t_strct *swap_strct, int flag);
void	rb(t_strct *swap_strct, int flag);
void	rrb(t_strct *swap_strct, int flag);
void	rr(t_strct *swap_strct, int flag);
/***/

/*for_instruct.c*/
void	rrr(t_strct *swap_strct, int flag);
void	swap_lst(t_lst **begin, t_lst **end_of);
void	forw_rot(t_lst **begin, t_lst **end_a);
void	revs_rot(t_lst **begin, t_lst **end_a);
void	move_lst(t_lst **begin_stack_a, t_lst **end_stack_a, \
	t_lst **begin_stack_b, t_lst **end_stack_b);
/***/

/*instruct_check_1.c*/
int		check_b_stack(t_strct *swap_strct);
int		check3b_l(t_strct *swap_strct);
int		check3b_l(t_strct *swap_strct);
int		back_track_b(t_strct *swap_strct);
void	stack_proc_btoa(t_strct *swap_strct);
/***/
/*function_2.c*/
void	step_exec(t_strct *swap_strct);
int		read_arr(int argc, char **argv, t_strct *swap_strct);
int		check_seq(t_lst *stack);
void	double_check(char **arr);
void	free_arr(char **arr, int flag);
/***/
/*cheker.c*/
int		read_arr_1(int argc, char **argv, t_strct *swap_strct);
int		ft_checker(t_strct *swap_strct);
int		checkin(t_strct *swap_strct, char *line, int len);
/***/

#endif
