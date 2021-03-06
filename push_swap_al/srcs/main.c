/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:24:01 by tshata            #+#    #+#             */
/*   Updated: 2018/09/17 17:53:33 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		read_nbrs(char *str, t_stack *s_a)
{
	int			sign;
	long int	nbr;

	nbr = 0;
	sign = 1;
	while (*str)
	{
		if (*str == '-')
			sign = -1;
		else if (!ft_isdigit(*str))
		{
			ft_putstr("Error\n");
			exit(0);
		}
		else if (ft_isdigit(*str))
			nbr = (nbr * 10) + (*str - '0');
		if (*str == ' ' || !(*(str + 1)))
			read_nbrs_ext(s_a, nbr, sign);
		str++;
	}
	return (1);
}

int		fill_s_a(char **argv, int argc, t_stack *s_a, int flag)
{
	int	i;
	if (flag == 0)
	{
		i = 1;
		while (i < argc)
		{
			read_nbrs(argv[i], s_a);
			i++;
		}
	}
	else
	{
		i = 1;
		while (i <= argc)
		{
			read_nbrs(argv[i], s_a);
			i++;
		}
	}
	return (1);
}

void	init(t_stack *s_a, t_stack *s_b, int size, char **argv)
{
	int		nbr;
	int		i;

	i = 0;
	nbr = 0;
	while (i < size)
	{
		if (!count_nbrs(argv[i]))
		{
			ft_putstr("Error\n");
			exit(0);
		}
		nbr += count_nbrs(argv[i]);
		i++;
	}
	s_a->max_size = nbr;
	s_a->current_size = 0;
	s_a->nbrs = (int*)malloc(sizeof(int) * nbr);
	s_b->max_size = nbr;
	s_b->current_size = 0;
	s_b->nbrs = (int*)malloc(sizeof(int) * nbr);
	i = 0;
	while (i++ <= s_b->current_size)
		s_b->nbrs[i] = 0;
}

int		handle_input(char *line, t_stack *s_a, t_stack *s_b)
{
	while ((get_next_line(0, &line) == 1))
	{
		if (!exec_inst(line, s_a, s_b))
		{
			ft_putstr("Error\n");
			exit(0);
		}
		free(line);
	}
	return (1);
}

void		str_arg(char **argv, int size, t_stack s_a, t_stack s_b)
{
	char **str;
       
	str = ft_strsplit(argv[1],' ');
	
	init(&s_a, &s_b, size, str);
	if (fill_s_a(str, size, &s_a, size - size))
	{
		if (is_sorted(s_a.nbrs, size))
			exit(1);
		else
			choose_solution(s_a, s_b, size);
	}
}

int		main(int argc, char **argv)
{
	t_stack	s_a;
	t_stack	s_b;
	int		size;

	size = 0;
	size = argc - 1;
	if (size > 0)
	{
		if (argc == 2)
		{
			size = count_nbrs(argv[1]);
			str_arg(argv, size, s_a, s_b);
		}
		else
		init(&s_a, &s_b, size, argv);
		if (fill_s_a(argv, size, &s_a, argc))
		{
			if (is_sorted(s_a.nbrs, size))
				exit(1);
			else
				choose_solution(s_a, s_b, size);
		}
		free(s_a.nbrs);
		free(s_b.nbrs);
	}
	return (0);
}
