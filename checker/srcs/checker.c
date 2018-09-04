/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 12:20:09 by tshata            #+#    #+#             */
/*   Updated: 2018/09/04 17:10:15 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int	read_nbrs(char *str, t_stack *s_a)
{
	int			sign;
	long int	nbr;

	nbr = 0;
	sign = 1;
	while (*str)
	{
		if (*str == '-')
			sign = -1;
		else if (ft_isdigit(*str))
			nbr = (nbr * 10) + (*str - '0');
		if (*str == ' ' || !(*(str + 1)))
		{
			nbr *= sign;
			if (!is_valid(s_a, nbr) && nbr != 0)
			{
				ft_putstr("Error\n");
				exit(0);
			}
			s_a->nbrs[s_a->current_size] = nbr;
			s_a->current_size++;
			nbr = 0;
			sign = 1;
		}
		str++;
	}
	return (1);
}

int				fill_s_a(char **argv, int argc, t_stack *s_a)
{
	int			i;

	i = 0;
	while (i <= argc)
	{
		read_nbrs(argv[i], s_a);
		i++;
	}
	return (1);
}

void		init(t_stack *s_a, t_stack *s_b, int size, char **argv)
{
	int			nbr;
	int			i;

	i = 0;
	nbr = 0;
	while (i < size)
	{
		if (!count_nbrs(argv[i]))
		{
			ft_putstr("Error_count\n");
			exit(0);
		}
		nbr += count_nbrs(argv[i]);
	//	ft_putnbr(nbr);
		i++;
	}
	s_a->max_size = nbr;
	s_a->current_size = 0;
	s_a->nbrs = (int*)malloc(sizeof(int) * nbr);
	s_b->max_size = nbr;
	s_b->current_size = 0;
	s_b->nbrs = (int*)malloc(sizeof(int) * nbr);
}

int			handle_input(char *line, t_stack *s_a, t_stack *s_b)
{	
	while ((get_next_line(0, &line) == 1))
	{
		if (!exec_inst(line, s_a, s_b))
		{
			ft_putstr("Error_input\n");
			exit(0);
		}
		free(line);
	}
	return (1);
}

int				main(int argc, char **argv)
{
	t_stack		s_a;
	t_stack		s_b;
	int			size;
	char		*line;

	size = 0;
	size = argc - 1;
	if (argc > 1)
	{
		init(&s_a, &s_b, size, argv);
		line = NULL;
		if (fill_s_a(argv, size, &s_a))
			handle_input(line, &s_a, &s_b);
		if (is_sorted(s_a.nbrs, s_a.current_size) && (s_b.current_size == 0))
			ft_putstr("OK\n");
		else if (!is_sorted(s_a.nbrs, s_a.current_size))
			ft_putstr("KO\n");
		else
			ft_putstr("Error\n");
	
	free(s_a.nbrs);
	free(s_b.nbrs);
	}
}
