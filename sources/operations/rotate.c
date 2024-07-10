/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabguerr <gabguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:30:46 by gabguerr          #+#    #+#             */
/*   Updated: 2024/07/02 18:14:08 by gabguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rs_a(long *s_a, int *nbr_s_a)
{
	int		i;
	long	*temporary;

	i = 0;
	temporary = (long *)malloc(sizeof(long));
	*temporary = s_a[0];
	while (i < nbr_s_a[1])
	{
		s_a[i] = s_a[i + 1];
		i++;
	}
	s_a[nbr_s_a[1] - 1] = *temporary;
	free(temporary);
	write(1, "ra\n", 3);
}

void	rs_b(long *s_b, int *nbr_s_b)
{
	int		i;
	long	*temporary;

	i = 0;
	temporary = (long *)malloc(sizeof(long));
	*temporary = s_b[0];
	while (i < *nbr_s_b)
	{
		s_b[i] = s_b[i + 1];
		i++;
	}
	s_b[*nbr_s_b - 1] = *temporary;
	free(temporary);
	write(1, "rb\n", 3);
}

void	rs_a_b(long *s_a, long *s_b, int *nbr_s_a, int *nbr_s_b)
{
	int		i;
	long	*temporary;

	i = 0;
	temporary = (long *)malloc(sizeof(long));
	*temporary = s_a[0];
	while (i < nbr_s_a[1])
	{
		s_a[i] = s_a[i + 1];
		i++;
	}
	s_a[nbr_s_a[1] - 1] = *temporary;
	i = 0;
	*temporary = s_b[0];
	while (i < *nbr_s_b)
	{
		s_b[i] = s_b[i + 1];
		i++;
	}
	s_b[*nbr_s_b - 1] = *temporary;
	free(temporary);
	write(1, "rr\n", 3);
}
