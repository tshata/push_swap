/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 12:19:19 by tshata            #+#    #+#             */
/*   Updated: 2018/09/17 12:08:51 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		solve_three(t_stack *s_a)
{
	find_min(s_a);
	if (is_sorted(s_a->nbrs, s_a->current_size))
		return ;
	if (s_a->nbrs[1] < s_a->nbrs[0] && s_a->nbrs[0] < s_a->nbrs[2])
	{
		ft_putendl("sa");
	}
	else if (s_a->nbrs[0] > s_a->nbrs[1] && s_a->nbrs[1] > s_a->nbrs[2])
	{
		ft_putendl("sa");
		ft_putendl("rra");
	}
	else if (s_a->nbrs[1] < s_a->nbrs[2] && s_a->nbrs[0] > s_a->nbrs[2])
	{
		ft_putendl("ra");
	}
	else if (s_a->min_nbr == s_a->nbrs[0] && s_a->nbrs[0] < s_a->nbrs[2]
			&& s_a->nbrs[1] > s_a->nbrs[2])
	{
		ft_putendl("rra");
		ft_putendl("sa");
	}
	else
		ft_putendl("rra");
}

void		solve_4(t_stack *s_a, t_stack *s_b)
{
		int i = 0;
	
	find_min(s_a);

	/*while(i < 4)
	{
		ft_putnbr(s_b->nbrs[i]);
		i++;
	}
*/
	if (is_sorted(s_a->nbrs, 4))
		return ;
	if (s_a->min_nbr == s_a->nbrs[0])
	{
		ft_putendl("pb");
		push_b(s_a, s_b);
	}
	else if (s_a->min_nbr == s_a->nbrs[1])
	{
		ft_putendl("sa");
		swap_top(s_a);
		if (is_sorted(s_a->nbrs, 4))
			return ;
		ft_putendl("pb");
		push_b(s_a, s_b);
	}
	else
		solve_4_2(s_a, s_b);
}

void		solve_4_2(t_stack *s_a, t_stack *s_b)
{
	if (s_a->min_nbr == s_a->nbrs[2])
	{
		ft_putendl("rra");
		reverse_rotate(s_a);
		ft_putendl("rra");
		reverse_rotate(s_a);
		if (is_sorted(s_a->nbrs, 4))
			return ;
		ft_putendl("pb");
		push_b(s_a, s_b);
	}
	else if (s_a->min_nbr == s_a->nbrs[3])
	{
		ft_putendl("rra");
		reverse_rotate(s_a);
		if (is_sorted(s_a->nbrs, 4))
			return ;
		ft_putendl("pb");
		push_b(s_a, s_b);
	}
}

void		solve_five(t_stack *s_a, t_stack *s_b)
{
	find_min(s_a);
	if (is_sorted(s_a->nbrs, s_a->current_size))
		return ;
	if (s_a->min_nbr == s_a->nbrs[0])
		solve_five_1(s_a, s_b);
	else if (s_a->min_nbr == s_a->nbrs[1])
		solve_five_2(s_a, s_b);
	else if (s_a->min_nbr == s_a->nbrs[2])
		solve_five_3(s_a, s_b);
	else if (s_a->min_nbr == s_a->nbrs[3])
		solve_five_4(s_a, s_b);
	else if (s_a->min_nbr == s_a->nbrs[4])
		solve_five_5(s_a, s_b);
}

void		solve_big(t_stack *s_a, t_stack *s_b)
{
	find_min(s_a);
	if (!is_sorted(s_a->nbrs, 2) && s_a->current_size == 2)
	{
		ft_putendl("rra");
		reverse_rotate(s_a);
		exit(1);
	}
	if (s_a->min_idx >= s_a->current_size/2)
	{
		while (s_a->min_nbr != s_a->nbrs[0])
		{
			find_min(s_a);
			ft_putendl("rra");
			reverse_rotate(s_a);
			if (s_a->min_nbr == s_a->nbrs[0])
			{
				ft_putendl("pb");
				push_b(s_a, s_b);
			}
		}
	}
	else
	{
		while (s_a->min_nbr != s_a->nbrs[0])
		{
			find_min(s_a);
			ft_putendl("ra");
			rotate(s_a);
			if (s_a->min_nbr == s_a->nbrs[0])
			{
				ft_putendl("pb");
				push_b(s_a, s_b);
			}
		}
	}
	while (s_b->current_size != 0)
	{
		ft_putendl("pa");
		push_a(s_a, s_b);
	}
}
