/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_nbrs_ext.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshata <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 12:20:13 by tshata            #+#    #+#             */
/*   Updated: 2018/09/17 17:37:35 by tshata           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	read_nbrs_ext(t_stack *s_a, long int nbr, int sign)
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
