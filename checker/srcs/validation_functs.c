/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_functs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/01 14:56:11 by tshata            #+#    #+#             */
/*   Updated: 2018/09/13 13:50:02 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#include "../../libft/libft.h"

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

int		is_valid(t_stack *stack, long int nbr)
{
	if (ft_isalpha(nbr))
		return (0);
	if (nbr > 2147483647 || nbr < -2147483648 || is_duplicate(stack ,nbr))
		return (0);
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

int		count_nbrs(char *str)
{
	int	nbrs;
	int i;

	nbrs = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && ft_isdigit(str[i + 1]))
			i++;
		else if (str[i] == ' ' && (ft_isdigit(str[i - 1]) || ft_isdigit(str[i + 1])))
		{
			i++;
		}
		else if (ft_isdigit(str[i]))
		{
			i++;
			nbrs++;
		}
		else
		{
			return (1);
		}
	}
	return (nbrs);
}
