/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 13:33:33 by tshata            #+#    #+#             */
/*   Updated: 2018/09/03 17:35:41 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../../libft/libft.h"

typedef struct	s_stack
{
	int			*nbrs;
	int			current_size;
	int			max_size;
	int			min_idx;
	int			min_nbr;
}				t_stack;

void			print_spaces(int spaces);
int				longest_int_len(t_stack *s_a);
char			*update_solution(char *solution, char *op);
void			swap_top(t_stack *stack);
void			swap_both(t_stack *s_a, t_stack *s_b);
int				empty_stack(t_stack *stack);
int				is_duplicate(t_stack *stack, int nbr);
int				is_valid(long int nbr, t_stack *s_a);
int				is_sorted(int *nbrs, int size);
int				is_revsorted(int *nbrs, int size);
int				get_nbrs(char *str);
int				exec_inst(char *op, t_stack *s_a, t_stack *s_b);
void			push_a(t_stack *s_a, t_stack *s_b);
void			push_b(t_stack *s_a, t_stack *s_b);
void			rotate(t_stack *stack);
void			rotate_both(t_stack *s_a, t_stack *s_b);
void			reverse_rotate(t_stack *stack);
void			reverse_rotate_both(t_stack *s_a, t_stack *s_b);
int				handle_input(char *line, t_stack *s_a, t_stack *s_b);
void			find_min(t_stack *s_a);

#endif
