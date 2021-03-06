/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 01:24:37 by tshata            #+#    #+#             */
/*   Updated: 2018/09/17 12:01:09 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	solve_five_1(t_stack *s_a, t_stack *s_b)
{
	if (is_sorted(s_a->nbrs, 5))
	{
		exit(1);
	}
	ft_putendl("pb");
	push_b(s_a, s_b);
	solve_4(s_a, s_b);
	solve_three(s_a);
	ft_putendl("pa");
	ft_putendl("pa");
}

void	solve_five_2(t_stack *s_a, t_stack *s_b)
{
	ft_putendl("sa");
	swap_top(s_a);
	ft_putendl("pb");
	push_b(s_a, s_b);
	solve_4(s_a, s_b);
	solve_three(s_a);
	ft_putendl("pa");
	ft_putendl("pa");
}

void	solve_five_3(t_stack *s_a, t_stack *s_b)
{
	int i = 0;
/*	while (i < 5)
	{
		ft_putnbr(s_a->nbrs[i]);
		i++;
	}
*/	ft_putendl("ra");
	rotate(s_a);i = 0;
/*	while (i < 5)
	{
		ft_putnbr(s_a->nbrs[i]);
		i++;
	}
*/	ft_putendl("sa");
	swap_top(s_a);
	ft_putendl("pb");
	push_b(s_a, s_b);
	solve_4(s_a, s_b);
	solve_three(s_a);
	ft_putendl("pa");
	ft_putendl("pa");
}

void	solve_five_4(t_stack *s_a, t_stack *s_b)
{
	ft_putendl("rra");
	reverse_rotate(s_a);
	reverse_rotate(s_a);
	ft_putendl("rra");
	if (is_sorted(s_a->nbrs, 5))
	{
		exit(1);
	}
	push_b(s_a, s_b);
	ft_putendl("pb");
	solve_4(s_a, s_b);
	solve_three(s_a);
	ft_putendl("pa");
	ft_putendl("pa");
}

void	solve_five_5(t_stack *s_a, t_stack *s_b)
{
	ft_putendl("rra");
	reverse_rotate(s_a);
	if (is_sorted(s_a->nbrs, 5))
	{
		exit(1);
	}
	ft_putendl("pb");
	push_b(s_a, s_b);
	solve_4(s_a, s_b);
	solve_three(s_a);
	ft_putendl("pa");
	ft_putendl("pa");
}
