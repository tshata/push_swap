/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_functs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:18:22 by tshata            #+#    #+#             */
/*   Updated: 2018/09/03 17:18:06 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	swap_top(t_stack *stack)
{
	int	temp;

	if (stack->current_size >= 2)
	{
		temp = stack->nbrs[0];
		stack->nbrs[0] = stack->nbrs[1];
		stack->nbrs[1] = temp;
	}
}

void	swap_both(t_stack *s_a, t_stack *s_b)
{
	swap_top(s_a);
	swap_top(s_b);
}

int		empty_stack(t_stack *stack)
{
	if (!stack->current_size)
		return (1);
	else
		return (0);
}

