/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:18:22 by tshata            #+#    #+#             */
/*   Updated: 2018/09/01 14:23:49 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	swap_top(t_stack *stack)
{
	int temp;

	if (stack->current_size >= 2)
	{
		temp = stack->integers[0];
		stack->integers[0] = stack->integers[1];
		stack->integers[1] = temp;
	}
}

void	swap_all(t_stack *s_a, t_stack *s_b)
{
	swap_top(s_a);
	swap_top(s_b);
}

int	exec_inst(t_stack *s_a, t_stack *s_b, char *line)
{
	if (ft_strcmp("sa", line) == 0)
		swap_top(s_a);
	else if (ft_strcmp("sb", line) == 0)
		swap_top(s_b);
	else if (ft_strcmp("ss", line) == 0)
		swap_all(s_a, s_b);
	else if (ft_strcmp("ra", line) == 0)
		rotate(s_a);
	else if (ft_strcmp("rb", line) == 0)
		rotate(s_b);
	else if (ft_strcmp("rr", line))
		rotate_all(s_a, s_b);
	else if (ft_strcmp("rra", line))
		reverse_rotate(s_a);
	else if (ft_strcmp("rrb", line))
		reverse_rotate(s_b);
	else if (ft_strcmp("rrr", line))
		reverse_rotate_all(s_a, s_b);
	else
	{
		ft_putstr("Error\n");
		return (0);
	}
	return (1);
}
