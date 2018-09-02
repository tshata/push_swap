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
	int temp;

	if(!is_empty(stack))
	{
		temp  = stack->integers[0];
		ft_memmove(&(stack->integers[0]), &(stack->integers[1]), 
						sizeof(int)* (stack->current_size));
		stack->integers[stack->current_size - 1] = temp;
	}
}

void	rotate_all(t_stack *s_a, t_stack *s_b)
{
	rotate(s_a);
	rotate(s_b);
}

void	reverse_rotate(t_stack *stack)
{
	int		temp;

	if (!is_empty(stack))
	{
		temp = stack->integers[stack->current_size - 1];
		ft_memmove(&(stack->integers[1]), &stack->integers[0], 
				sizeof(int) * (stack->current_size));
		stack->integers[0] = temp;
	}
}

void	reverse_rotate_all(t_stack *s_a, t_stack *s_b)
{
	reverse_rotate(s_a);
	reverse_rotate(s_b);
}
