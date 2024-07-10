/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabguerr <gabguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:35:19 by gabguerr          #+#    #+#             */
/*   Updated: 2024/07/02 18:06:31 by gabguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rs_a_r(long *s_a, int *nbr_s_a)
{
	rs_a(s_a, nbr_s_a);
	rs_a(s_a, nbr_s_a);
}

void	rrs_a_r(long *s_a, int *nbr_s_a)
{
	rrs_a(s_a, nbr_s_a);
	rrs_a(s_a, nbr_s_a);
}

void	first_stack(long *s_a, long *s_b, int *nbr_s_a, int *nbr_s_b)
{
	if (s_b[0] < s_a[0])
		ps_a(s_a, s_b, nbr_s_a, nbr_s_b);
	else if ((s_b[0] > s_a[0]) && (s_b[0] < s_a[1]))
	{
		rs_a(s_a, nbr_s_a);
		ps_a(s_a, s_b, nbr_s_a, nbr_s_b);
		rrs_a(s_a, nbr_s_a);
	}
	else if ((s_b[0] > s_a[1]) && (s_b[0] < s_a[2]))
	{
		rrs_a(s_a, nbr_s_a);
		ps_a(s_a, s_b, nbr_s_a, nbr_s_b);
		rrs_a(s_a, nbr_s_a);
		rrs_a(s_a, nbr_s_a);
	}
	else if (s_b[0] > s_a[2])
	{
		ps_a(s_a, s_b, nbr_s_a, nbr_s_b);
		rs_a(s_a, nbr_s_a);
	}
}

void	second_stack(long *s_a, long *s_b, int *nbr_s_a, int *nbr_s_b)
{
	if (s_b[0] < s_a[0])
		ps_a(s_a, s_b, nbr_s_a, nbr_s_b);
	else if ((s_b[0] > s_a[0]) && (s_b[0] < s_a[1]))
	{
		rs_a(s_a, nbr_s_a);
		ps_a(s_a, s_b, nbr_s_a, nbr_s_b);
		rrs_a(s_a, nbr_s_a);
	}
	else if ((s_b[0] > s_a[1]) && (s_b[0] < s_a[2]))
	{
		rs_a(s_a, nbr_s_a);
		ps_a(s_a, s_b, nbr_s_a, nbr_s_b);
		ss_a(s_a, nbr_s_a);
		rrs_a(s_a, nbr_s_a);
	}
	else if ((s_b[0] > s_a[2]) && (s_b[0] < s_a[3]))
	{
		rrs_a(s_a, nbr_s_a);
		ps_a(s_a, s_b, nbr_s_a, nbr_s_b);
		rs_a_r(s_a, nbr_s_a);
	}
	else if (s_b[0] > s_a[3])
		parameters(s_a, s_b, nbr_s_a, nbr_s_b);
}

void	sort_5_nbr(long *s_a, long *s_b, int *nbr_s_a, int *nbr_s_b)
{
	ps_b(s_a, s_b, nbr_s_a, nbr_s_b);
	ps_b(s_a, s_b, nbr_s_a, nbr_s_b);
	sort_3_nbr(s_a, nbr_s_a);
	while (*nbr_s_b != 0)
	{
		if (nbr_s_a[1] == 3)
			first_stack(s_a, s_b, nbr_s_a, nbr_s_b);
		else if (nbr_s_a[1] == 4)
			second_stack(s_a, s_b, nbr_s_a, nbr_s_b);
	}
}
