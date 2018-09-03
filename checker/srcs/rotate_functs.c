/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:37:59 by tshata            #+#    #+#             */
/*   Updated: 2018/09/01 14:55:50 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	rotate(t_stack *stack)
{
	int	temp;

	if (stack->cur_size)
	{
		temp = (stack->nums)[0];
		ft_memmove(&(stack->nums[0]), &(stack->nums[1]),
					sizeof(int) * (stack->cur_size));
		stack->nums[stack->cur_size - 1] = temp;
	}
}

void	rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}

void	reverse_rotate(t_stack *stack)
{
	int	temp;

	temp = stack->nums[stack->cur_size - 1];
	ft_memmove(&(stack->nums[1]), &(stack->nums[0]),
				sizeof(int) * (stack->cur_size));
	stack->nums[0] = temp;
}

void	reverse_rotate_both(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
