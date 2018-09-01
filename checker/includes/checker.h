/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 13:33:33 by tshata            #+#    #+#             */
/*   Updated: 2018/09/01 14:47:30 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../libft.h"

typedef struct s_stack
{
	int 	*integers;
	int		current_size;
	int		real_size;
	int		min_index;
	int		min_integer;
}				t_stack;

void	swap_top(t_stack *stack);
void	swap_all(t_stack *stack_a, t_stack *stack_b);
void	push_a(t_stack *stack_a, t_stack *stack_b);
void	push_b(t_stack *stack_b, t_stack *stack_a);
void	rotate(t_stack *stack);
void	rotate_all(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate(t_stack *stack);
void	reverse_rotate_all(t_stack *stack_a, t_stack *stack_b);
#endif
