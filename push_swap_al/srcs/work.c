/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 05:48:15 by tshata            #+#    #+#             */
/*   Updated: 2018/09/15 05:48:19 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char		*update_solution(char *solution, char *op)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(solution);
	dst = solution + len;
	ft_strcpy(dst, op);
	ft_strcat(dst, "\n");
	solution = ft_memalloc(len + 5);
	return (solution);
}

void		reverse_op(char *op, t_stack *s_a, t_stack *s_b)
{
	if (ft_strcmp(op, "rra") == 0)
		reverse_rotate(s_a);
	else if (ft_strcmp(op, "rrb") == 0)
		reverse_rotate(s_b);
	else if (ft_strcmp(op, "rrr") == 0)
		reverse_rotate_both(s_a, s_b);
}

int			exec_inst(char *op, t_stack *s_a, t_stack *s_b)
{
	if (ft_strcmp(op, "sa") == 0)
		swap_top(s_a);
	else if (ft_strcmp(op, "sb") == 0)
		swap_top(s_b);
	else if (ft_strcmp(op, "ss") == 0)
		swap_both(s_a, s_b);
	else if (ft_strcmp(op, "pa") == 0)
		push_a(s_a, s_b);
	else if (ft_strcmp(op, "pb") == 0)
		push_b(s_a, s_b);
	else if (ft_strcmp(op, "ra") == 0)
		rotate(s_a);
	else if (ft_strcmp(op, "rb") == 0)
		rotate(s_b);
	else if (ft_strcmp(op, "rr") == 0)
		rotate_both(s_a, s_b);
	else if (ft_strcmp(op, "rra") == 0 || ft_strcmp(op, "rrb") == 0
			|| ft_strcmp(op, "rrr") == 0)
		reverse_op(op, s_a, s_b);
	else
	{
		ft_putstr("Error\n");
		exit(1);
	}
	return (1);
}

void		find_min(t_stack *s_a)
{
	int		min;
	int		i;

	min = s_a->nbrs[0];
	s_a->min_nbr = min;
	i = 1;
	while (i < s_a->current_size)
	{
		if (s_a->nbrs[i] < min)
		{
			min = s_a->nbrs[i];
			s_a->min_nbr = min;
			s_a->min_idx = i;
		}
		i++;
	}
}
