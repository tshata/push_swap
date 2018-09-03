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
	if (stack->cur_size)
		return (0);
	else
		return (1);
}
void	push_on_a(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;

	if (!empty_stack(stack_b))
	{
		temp = (stack_b->nums)[0];
		ft_memmove(&(stack_b->nums[0]), &(stack_b->nums[1]),
					sizeof(int) * (stack_b->cur_size));
		ft_memmove(&(stack_a->nums[1]), &(stack_a->nums[0]),
					sizeof(int) * (stack_a->cur_size));
		(stack_a->nums)[0] = temp;
		(stack_a->cur_size)++;
		(stack_b->cur_size)--;
	}
}

void	push_on_b(t_stack *stack_a, t_stack *stack_b)
{
	int	temp;

	if (!empty_stack(stack_a))
	{
		temp = (stack_a->nums)[0];
		ft_memmove(&(stack_a->nums[0]), &(stack_a->nums[1]),
					sizeof(int) * (stack_a->cur_size));
		ft_memmove(&(stack_b->nums[1]), &(stack_b->nums[0]),
					sizeof(int) * (stack_b->cur_size));
		(stack_b->nums)[0] = temp;
		(stack_b->cur_size)++;
		(stack_a->cur_size)--;
	}
}

char		**check_for_flags(char **av, t_flags *flags, int *ac)
{
	int		s;
	int		c;
	int		args;

	s = 1;
	c = 0;
	args = *ac;
	while ((s < args) && av[s][c] == '-' || av[s][c] == 'c' && !ft_isdigit(av[s][c + 1]))
	{
		if (av[s][c] == 'c')
			flags->c = 1;
		if (av[s][c] == 'c' && !av[s][c + 1])
		{
			s++;
			c = 0;
			(*ac)--;
		}
		else
			c++;
	}
	return (&(av[s]));
}
