/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_functs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:37:59 by tshata            #+#    #+#             */
/*   Updated: 2018/09/17 12:36:46 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	rotate(t_stack *stk)
{
	int	temp;

	if (stk->current_size)
	{
		temp = (stk->nbrs)[0];
		ft_memmove(&(stk->nbrs[0]), &(stk->nbrs[1]), 4 * (stk->current_size));
		stk->nbrs[stk->current_size - 1] = temp;
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
	ft_memmove(&(stack->nbrs[1]), &(stack->nbrs[0]), 4 * (stack->current_size));
	stack->nbrs[0] = temp;
}

void	reverse_rotate_both(t_stack *s_a, t_stack *s_b)
{
	reverse_rotate(s_a);
	reverse_rotate(s_b);
}
