/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_5_nbr.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabguerr <gabguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:35:50 by gabguerr          #+#    #+#             */
/*   Updated: 2024/07/02 18:05:02 by gabguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_a_section_of_the_stack(long *array, int *ss)
{
	long	i;
	long	j;
	long	temporary;

	i = 0;
	j = 0;
	while (i < ss[0])
	{
		j = i + 1;
		while (j < ss[0])
		{
			if (array[i] > array[j])
			{
				temporary = array[i];
				array[i] = array[j];
				array[j] = temporary;
			}
			j++;
		}
		i++;
	}
}

void	ss_a_1t(long *copy, long *copy_swap_stack_a, long *s_a, int *nbr_s_a)
{
	int	i;

	i = 0;
	while (i < nbr_s_a[0])
	{
		copy[i] = s_a[i];
		copy_swap_stack_a[i] = s_a[i];
		i++;
	}
}

void	ss_a_2t(long *copy, long *copy_swap_stack_a, long *s_a, int *nbr_s_a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < nbr_s_a[1])
	{
		j = 0;
		while (j < nbr_s_a[0])
		{
			if (copy_swap_stack_a[i] == copy[j])
				s_a[i] = j;
			j++;
		}
		++i;
	}
}

void	ss_a_3t(long *s_a, long *s_b, int *nbr_s_a, int *nbr_s_b)
{
	int	maximum_number;
	int	maximum_bits;
	int	loop_through[2];

	maximum_number = nbr_s_a[1] - 1;
	maximum_bits = 0;
	loop_through[0] = 0;
	loop_through[1] = 0;
	while ((maximum_number >> maximum_bits) != 0)
		++maximum_bits;
	while (loop_through[0] < maximum_bits)
	{
		loop_through[1] = 0;
		while (loop_through[1] < nbr_s_a[0])
		{
			if (((s_a[0] >> loop_through[0]) & 1) == 1)
				rs_a(s_a, nbr_s_a);
			else
				ps_b(s_a, s_b, nbr_s_a, nbr_s_b);
			++loop_through[1];
		}
		while (*nbr_s_b != 0)
			ps_a(s_a, s_b, nbr_s_a, nbr_s_b);
		++loop_through[0];
	}
}

void	sort_3_5_nbr(long *s_a, long *s_b, int *nbr_s_a, int *nbr_s_b)
{
	long	*copy;
	long	*copy_swap_stack_a;

	copy = (long *)malloc(nbr_s_a[0] * sizeof(long));
	copy_swap_stack_a = (long *)malloc(nbr_s_a[0] * sizeof(long));
	ss_a_1t(copy, copy_swap_stack_a, s_a, nbr_s_a);
	sort_a_section_of_the_stack(copy, nbr_s_a);
	ss_a_2t(copy, copy_swap_stack_a, s_a, nbr_s_a);
	free(copy);
	free(copy_swap_stack_a);
	ss_a_3t(s_a, s_b, nbr_s_a, nbr_s_b);
}
