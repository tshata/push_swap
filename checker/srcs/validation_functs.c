/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_functs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:56:11 by tshata            #+#    #+#             */
/*   Updated: 2018/09/03 18:37:18 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		is_duplicate(t_stack *stack, int nbr)
{
	int	i;

	i = 0;
	while (i < stack->current_size)
	{
		if (stack->nbrs[i] == nbr)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int		is_valid(long int nbr, t_stack *s_a)
{
	if (is_duplicate(s_a, nbr))
	{
		ft_putstr("Error\n");
		return (0);
	}
	else
		return (1);
}

int		is_sorted(int *nbrs, int size)
{
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		if (nbrs[i] > nbrs[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		is_revsorted(int *nbrs, int size)
{
	int	i;

	i = 0;
	while (i < (size - 1))
	{
		if (nbrs[i] < nbrs[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		get_nbrs(char *str)
{
	int	nbrs;

	nbrs = 0;
	while (*str)
	{
		if (*str == '-' && ft_isdigit(*(str + 1)))
			str++;
		else if (*str == ' ' && (ft_isdigit(*(str - 1)) ||
							ft_isdigit(*(str + 1))))
		{
			str++;
			nbrs++;
		}
		else if (ft_isdigit(*str))
		{
			str++;
			if (!*str)
				nbrs++;
		}
		else
			return (0);
	}
	return (nbrs);

}
