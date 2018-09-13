/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:37:59 by tshata            #+#    #+#             */
/*   Updated: 2018/09/13 14:01:55 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack *stack)
{
	int	temp;

	if (stack->current_size)
	{
		temp = (stack->nbrs)[0];
		ft_memmove(&(stack->nbrs[0]), &(stack->nbrs[1]),
					sizeof(int) * (stack->current_size));
		stack->nbrs[stack->current_size - 1] = temp;
	}
}

void	rotate_both(t_stack *s_a, t_stack *s_b)
{
	rotate(s_a);
	rotate(s_b);
}

void	reverse_rotate(t_stack *stack)
{
	int	temp;

	temp = stack->nbrs[stack->current_size - 1];
	ft_memmove(&(stack->nbrs[1]), &(stack->nbrs[0]),
				sizeof(int) * (stack->current_size));
	stack->nbrs[0] = temp;
}

void	reverse_rotate_both(t_stack *s_a, t_stack *s_b)
{
	reverse_rotate(s_a);
	reverse_rotate(s_b);
}
