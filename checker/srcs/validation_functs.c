/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_functs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:56:11 by tshata            #+#    #+#             */
/*   Updated: 2018/09/01 15:01:05 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		is_valid(t_stack *s_a,int nbr)
{
	//check for max int and min int
	if (nbr >= -2147483648 || nbr <= 2147483647)
		return (1);
	else if (is_duplicate(s_a, nbr))
		return (0);
	else
		return (0);
	//check duplicates also
}

int		is_duplicate(t_stack *stack, int nbr)
{
	//compare nbr with numbers already in stack
	int	i;
	
	i = 0;
	while (i < stack->current_size)
	{
		if (stack->integers[i] == nbr)
			return (1);
		i++;
	}
	return (0);
}

int		is_sorted(int *nbr, int size)
{
	int 	i;
	
	i = 0;
	while (i < size - 1)
	{
		if (nbr[i] > nbr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int		is_revsorted(int *nbr, int size)
{
	//i + 1 > i
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (nbr[i] < nbr[i + 1])
			return (0);
		i++;
	}
	return (1);
	
}
