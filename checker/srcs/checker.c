/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 12:20:09 by tshata            #+#    #+#             */
/*   Updated: 2018/09/01 14:49:31 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int 	read_input(t_stack *s_a, char *str)
{
	//read numbers
}
int		fill_stack_a(t_stack *s_a, int	argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		read_input(argv[i], s_a);
		i++;
	}
	return (1);
}

static	void	init_ps(t_stack *s_a, t_stack *s_b, int size, char **argv)
{
	//check numbers for valididty
	//malloc for both stacks
}

void	input_handler(t_stack *s_a, t_stack *s_b, char *line)
{
	//get_next_line
	//follow instructions
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
		init_ps(&s_a, &s_b, size, argv);
		line = NULL;
		if (fill_stack_a(&s_a, argv, size))
			input_handler(&s_a, &s_b, line);
		else if (/*condition still to come*/)
		{
			ft_putstr("Error\n");
			exit (1);
		}
		if (sorted(s_a.integers, s_a.current_size) && (s_b.current_size == 0))
			ft_putstr("OK");
		else
			ft_putstr("KO");
	}
	free(s_a.integers);
	free(s_b.integers);
}
