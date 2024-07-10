/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabguerr <gabguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:31:04 by gabguerr          #+#    #+#             */
/*   Updated: 2024/07/02 18:16:57 by gabguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ss_a(long *s_a, int *nbr_s_a)
{
	long	*temporary;

	temporary = (long *)malloc(sizeof(long));
	if (nbr_s_a[1] > 1)
	{
		temporary[0] = s_a[0];
		s_a[0] = s_a[1];
		s_a[1] = temporary[0];
	}
	free(temporary);
	write(1, "sa\n", 3);
}

void	ss_b(long *s_b, int *nbr_s_b)
{
	long	*temporary;

	temporary = (long *)malloc(sizeof(long));
	if (*nbr_s_b > 1)
	{
		temporary[0] = s_b[0];
		s_b[0] = s_b[1];
		s_b[1] = temporary[0];
	}
	free(temporary);
	write(1, "sb\n", 3);
}

void	ss_a_b(long *s_a, long *s_b, int *nbr_s_a, int *nbr_s_b)
{
	long	*temporary;

	temporary = (long *)malloc(sizeof(long));
	if (nbr_s_a[1] > 1)
	{
		temporary[0] = s_a[0];
		s_a[0] = s_a[1];
		s_a[1] = temporary[0];
	}
	if (*nbr_s_b > 1)
	{
		temporary[0] = s_b[0];
		s_b[0] = s_b[1];
		s_b[1] = temporary[0];
	}
	free(temporary);
	write(1, "ss\n", 3);
}
