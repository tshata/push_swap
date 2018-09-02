/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 13:33:33 by tshata            #+#    #+#             */
/*   Updated: 2018/09/02 21:51:34 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../../libft/libft.h"

typedef struct s_stack
{
	int 	integers[100];
	int		current_size;
	int		real_size;
	int		min_index;
	int		min_integer;
}				t_stack;

int	ft_is_number(char *str);
void	swap_top(t_stack *stack);
void	swap_all(t_stack *stack_a, t_stack *stack_b);
void	push_a(t_stack *stack_a, t_stack *stack_b);
void	push_b(t_stack *stack_b, t_stack *stack_a);
void	rotate(t_stack *stack);
void	rotate_all(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate(t_stack *stack);
void	reverse_rotate_all(t_stack *stack_a, t_stack *stack_b);
int	read_input(t_stack *stack_a, char *str);
void	input_handler(t_stack *stack_a, t_stack *stack_b, char *line);
int	fill_stack_a(t_stack *s_a, int argc, char **argv);
int	is_valid(t_stack *s, int nbr);
int	is_duplicate(t_stack *stack, int nbr);
int	is_sorted(int *nbr, int size);
int	is_revsorted(int *nbr, int size);
int	is_empty(t_stack *stack);
int	exec_inst(t_stack *s_a, t_stack *s_b, char *line);
#endif
