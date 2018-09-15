/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 17:24:01 by tshata            #+#    #+#             */
/*   Updated: 2018/09/15 02:21:02 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int read_nbrs(char *str, t_stack *s_a)
{
    int         sign;
    long int    nbr;

    nbr = 0;
    sign = 1;
    while (*str)
    {
        if (*str == '-')
            sign = -1;
        else if (!ft_isdigit(*str))
        {
            ft_putstr("Error\n");
            exit (0);
        }
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

int             fill_s_a(char **argv, int argc, t_stack *s_a)
{
    int         i;

    i = 1;
    while (i <= argc)
    {
        read_nbrs(argv[i], s_a);
//      ft_putnbr(ft_atoi(argv[i]));
        i++;
	}
	i = 1;
    return (1);
}

void        init(t_stack *s_a, t_stack *s_b, int size, char **argv)
{
    int         nbr;
    int         i;

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
    //  ft_putnbr(nbr);
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

int         handle_input(char *line, t_stack *s_a, t_stack *s_b)
{
    while ((get_next_line(0, &line) == 1))
    {
        //exec_inst(line, s_a, s_b);
        if (!exec_inst(line, s_a, s_b))
        {
            ft_putstr("Error\n");
            exit(0);
        }
        free(line);
    }
    return (1);
}

int             main(int argc, char **argv)
{
    t_stack     s_a;
    t_stack     s_b;
    int         size;
  
    size = 0;
    size = argc - 1;
    if (size > 0)
    {
        init(&s_a, &s_b, size, argv);
        if (fill_s_a(argv, size, &s_a))
		{
			if (size == 3)
				solve_three(&s_a);
			else if (size == 5)
				solve_five(&s_a, &s_b);
		}
		free(s_a.nbrs);
    	free(s_b.nbrs);
    }
}
