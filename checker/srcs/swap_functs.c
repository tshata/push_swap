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

void	swap_first_two(t_stack *stack)
{
	int	temp;

	if (stack->cur_size >= 2)
	{
		temp = stack->nums[0];
		stack->nums[0] = stack->nums[1];
		stack->nums[1] = temp;
	}
}

void	swap_both(t_stack *stack_a, t_stack *stack_b)
{
	swap_first_two(stack_a);
	swap_first_two(stack_b);
}

int		empty_stack(t_stack *stack)
{
	if (!stack->cur_size)
		return (1);
	else
		return (0);
}

