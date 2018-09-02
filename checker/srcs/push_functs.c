/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:23:59 by tshata            #+#    #+#             */
/*   Updated: 2018/09/01 14:49:45 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		is_empty(t_stack *stack)
{
	if (stack->current_size)
		return (0);
	else
		return (1);
}
void	push_a(t_stack *s_a, t_stack *s_b)
{
	int temp;

	if (is_empty(s_b))
	{
		temp = (s_b->integers)[0];
		ft_memmove(&s_b->integers[0], &s_b->integers[1], sizeof(int) * s_b->current_size);
		ft_memmove(&s_a->integers[1], &s_a->integers[0], sizeof(int) * s_a->current_size);
		s_a->integers[0] = temp;
		s_a->current_size += 1;
		s_b->current_size -= 1;
	}
}

void	push_b(t_stack *s_a, t_stack *s_b)
{
	int temp;

	if (is_empty(s_b))
	{
		temp = (s_b->integers)[0];
		ft_memmove(&s_a->integers[0], &s_a->integers[1], sizeof(int) * s_a->current_size);
		ft_memmove(&s_b->integers[1], &s_b->integers[0], sizeof(int) * s_b->current_size);
		s_b->integers[0] = temp;
		s_b->current_size += 1;
		s_a->current_size -= 1;
	}
}
