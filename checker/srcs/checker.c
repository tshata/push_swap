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

int	ft_is_number(char *str)
{
	int	nbr;
	int	i;

	i = 0;
	nbr = 0;
	while(str[i])
	{
		if (str[i] == '-' && ft_isdigit(str[i + 1]))
			i++;
		else if (str[i] == ' ' && (ft_isdigit(str[i]) || ft_isdigit(str[i])))
		{
			i++;
			nbr++;
		}
		else if (ft_isdigit(str[i]))
		{
			i++;
		if (!str[i])
				nbr++;
		}
		else
			return (0);
	}
	return (nbr);
}	
int 	read_input(t_stack *s_a, char *str)
{
	int                     sign;
        long int        nbr;
	int 		i;

       	nbr = 0;
	i = 0;
        sign = 1;
        while (str[i])
        {
                if (str[i] == '-')
                        sign = -1;
                else if (ft_isdigit(str[i]))
                        nbr = (nbr * 10) + (str[i] - '0');
                if (str[i] == ' ' || !(str[i + 1]))
                {
                        nbr *= sign;
                        if (!is_valid(s_a, nbr))
			{
				ft_putstr("Error_r\n");
                                exit(1);
			}
                        s_a->integers[s_a->current_size] = nbr;
	//		ft_putnbr((int)s_a->integers);
                        s_a->current_size++;
                        nbr = 0;
                        sign = 1;
                }
                i++;
       
//		ft_atoi(str);
       	}
        return (1);

}

int	fill_stack_a(t_stack *s_a, int	argc, char **argv)
{
	int	i;

	i = 0;
	while (i <= argc)
	{
		ft_putstr("foo");
		read_input(s_a, argv[i]);
		i++;
	}
	return (1);
}

static void	init_ps(t_stack *s_a, t_stack *s_b, int size, char **argv)
{
	int	nbr;
	int 	i;
	
	i = 2;
	nbr = 0;
	ft_putstr("here\n");
	while (i < size)
	{
	/*	if (!ft_is_number(argv[i]))
		{
			ft_putstr("Error_i\n");
			exit (1);
		}ft_putstr("nnon\n");
*/
		nbr += ft_is_number(argv[i]);
		i++;
	}
	s_a->real_size = i;
	s_a->current_size = 0;
//	s_a->integers = (int*)malloc(sizeof(int) * nbr);
	s_b->real_size = nbr;
	s_b->current_size = 0;
//	s_b->integers = (int*)malloc(sizeof(int) * nbr);
}
	
void	input_handler(t_stack *s_a, t_stack *s_b, char *line)
{
	//get_next_line
	//execute instructions
	while ((get_next_line(0, &line)))
	{
		if (!(exec_inst(s_a, s_b, line)))
		{
			ft_putstr("Error_e\n");
			exit(1);
		}
		free(line);
	}
}

int			main(int argc, char **argv)
{
	t_stack		*s_a;
	t_stack		*s_b;
	char 		*line;
	int			size;

	size = 0;
	size = argc - 1;
	if (argc > 1)
	{
		ft_putstr("run\n");
		init_ps(s_a, s_b, size, argv);
		ft_putstr("init\n");
		line = NULL;
		if (fill_stack_a(s_a, size, argv))
		{
			ft_putstr("nksncjd");
			input_handler(s_a, s_b, line);
			ft_putstr("after input");
		if (is_sorted(s_a->integers, s_a->current_size) && (s_b->current_size == 0))
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
		}}
	free(s_a->integers);
	free(s_b->integers);

return (0);




}
