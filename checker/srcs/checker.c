/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 12:20:09 by tshata            #+#    #+#             */
/*   Updated: 2018/09/02 21:49:14 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int				get_nums(char *str, t_stack *stack_a)
{
	int			sign;
	long int	num;

	num = 0;
	sign = 1;
	while (*str)
	{
		if (*str == '-')
			sign = -1;
		else if (ft_isdigit(*str))
			num = (num * 10) + (*str - '0');
		if (*str == ' ' || !(*(str + 1)))
		{
			num *= sign;
			if (!is_valid(num, stack_a))
				exit(1);
			stack_a->nums[stack_a->cur_size] = num;
			stack_a->cur_size++;
			num = 0;
			sign = 1;
		}
		str++;
	}
	return (1);
}

int				make_stack_a(char **av, int ac, t_stack *stack_a)
{
	int			i;

	i = 0;
	while (i < ac)
	{
		get_nums(av[i], stack_a);
		i++;
	}
	return (1);
}

static void		setup(t_stack *stack_a, t_stack *stack_b, int size, char **av)
{
	int			nums;
	int			i;

	i = 0;
	nums = 0;
	while (i < size)
	{
		if (!are_numbers(av[i]))
		{
			ft_putstr("Error_se\n");
			exit(1);
		}
		nums += are_numbers(av[i]);
		i++;
	}
	stack_a->max_size = nums;
	stack_a->cur_size = 0;
	stack_a->nums = (int*)malloc(sizeof(int) * nums);
	stack_b->max_size = nums;
	stack_b->cur_size = 0;
	stack_b->nums = (int*)malloc(sizeof(int) * nums);
}

void			handle_input(char *line, t_stack *stack_a,
						t_stack *stack_b, t_flags *flags)
{
	
	while ((get_next_line(0, &line) == 1))
	{
		if (!perform_op(line, stack_a, stack_b, flags))
		{
			ft_putstr("Error_h\n");
			exit(1);
		}
		free(line);
	}
}

static void		setup_flags(t_flags *flags)
{
	flags->v = 0;
	flags->c = 0;
}

int				main(int ac, char **av)
{
	t_stack		stack_a;
	t_stack		stack_b;
	t_flags		flags;
	char		*line;

	if (ac > 1)
	{
		setup_flags(&flags);
		av = check_for_flags(av, &flags, &ac);
		setup(&stack_a, &stack_b, (ac - 1), av);
		line = NULL;
		if (make_stack_a(av, (ac - 1), &stack_a))
			handle_input(line, &stack_a, &stack_b, &flags);
		if (is_sorted(stack_a.nums, stack_a.cur_size) &&
					(stack_b.cur_size == 0))
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
	}
	free(stack_a.nums);
	free(stack_b.nums);
}
