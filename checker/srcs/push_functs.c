/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:23:59 by tshata            #+#    #+#             */
/*   Updated: 2018/09/14 20:45:09 by tshata           ###   ########.fr       */
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
	int	temp;

	if (!is_empty(s_b))
	{
		temp = (s_b->nbrs)[0];
		ft_memmove(&(s_b->nbrs[0]), &(s_b->nbrs[1]), 4 * (s_b->current_size));
		ft_memmove(&(s_a->nbrs[1]), &(s_a->nbrs[0]), 4 * (s_a->current_size));
		(s_a->nbrs)[0] = temp;
		(s_a->current_size)++;
		(s_b->current_size)--;
	}
}

void	push_b(t_stack *s_a, t_stack *s_b)
{
	int	temp;

	if (!is_empty(s_a))
	{
		temp = (s_a->nbrs)[0];
		ft_memmove(&(s_a->nbrs[0]), &(s_a->nbrs[1]), 4 * (s_a->current_size));
		ft_memmove(&(s_b->nbrs[1]), &(s_b->nbrs[0]), 4 * (s_b->current_size));
		(s_b->nbrs)[0] = temp;
		(s_b->current_size)++;
		(s_a->current_size)--;
	}
}


