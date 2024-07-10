/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabguerr <gabguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:29:46 by gabguerr          #+#    #+#             */
/*   Updated: 2024/07/02 18:09:51 by gabguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ps_a(long *stack_a, long *stack_b, int *nbr_s_a, int *nbr_s_b)
{
	int	i;

	(nbr_s_a[1])++;
	i = nbr_s_a[1] - 1;
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = stack_b[0];
	i = 0;
	while (i < *nbr_s_b)
	{
		stack_b[i] = stack_b[i + 1];
		i++;
	}
	(*nbr_s_b)--;
	if (*nbr_s_b == 0)
		stack_b = NULL;
	write(1, "pa\n", 3);
}

void	ps_b(long *stack_a, long *stack_b, int *nbr_s_a, int *nbr_s_b)
{
	int	i;

	(*nbr_s_b)++;
	i = *nbr_s_b - 1;
	while (i > 0)
	{
		stack_b[i] = stack_b[i - 1];
		i--;
	}
	stack_b[0] = stack_a[0];
	i = 0;
	while (i < nbr_s_a[1])
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	(nbr_s_a[1])--;
	if (nbr_s_a[1] == 0)
		stack_a = NULL;
	write(1, "pb\n", 3);
}
