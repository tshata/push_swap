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
