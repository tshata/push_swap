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

typedef struct	s_flags
{
	int			v;
	int			c;
}				t_flags;

typedef struct	s_stack
{
	int			*nums;
	int			cur_size;
	int			max_size;
	int			min_idx;
	int			min_num;
}				t_stack;

void			print_spaces(int spaces);
int				longest_int_len(t_stack *stack_a);
char			*update_solution(char *solution, char *op);
char			**check_for_flags(char **av, t_flags *flags, int *ac);
void			swap_first_two(t_stack *stack);
void			swap_both(t_stack *stack_a, t_stack *stack_b);
int				empty_stack(t_stack *stack);
int				is_duplicate(t_stack *stack, int num);
int				is_valid(long int num, t_stack *stack_a);
int				is_sorted(int *nums, int size);
int				is_revsorted(int *nums, int size);
int				are_numbers(char *str);
int				perform_op(char *op, t_stack *stack_a,
							t_stack *stack_b, t_flags *flags);
void			push_on_a(t_stack *stack_a, t_stack *stack_b);
void			push_on_b(t_stack *stack_a, t_stack *stack_b);
void			rotate(t_stack *stack);
void			rotate_both(t_stack *stack_a, t_stack *stack_b);
void			reverse_rotate(t_stack *stack);
void			reverse_rotate_both(t_stack *stack_a, t_stack *stack_b);
void			display_stacks(t_flags *flags, char *op,
					t_stack *stack_a, t_stack *stack_b);
void			find_min(t_stack *stack_a);

#endif
