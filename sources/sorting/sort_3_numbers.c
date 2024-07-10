/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabguerr <gabguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:34:51 by gabguerr          #+#    #+#             */
/*   Updated: 2024/07/02 18:17:50 by gabguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_3_nbr(long *stack_a, int *numbers_in_stack_a)
{
	if ((stack_a[0] > stack_a[1]) && (stack_a[1] < stack_a[2])
		&& (stack_a[0] < stack_a[2]))
		ss_a(stack_a, numbers_in_stack_a);
	if ((stack_a[0] > stack_a[1]) && (stack_a[1] > stack_a[2])
		&& (stack_a[0] > stack_a[2]))
	{
		ss_a(stack_a, numbers_in_stack_a);
		rrs_a(stack_a, numbers_in_stack_a);
	}
	if ((stack_a[0] > stack_a[1]) && (stack_a[1] < stack_a[2])
		&& (stack_a[0] > stack_a[2]))
		rs_a(stack_a, numbers_in_stack_a);
	if ((stack_a[0] < stack_a[1]) && (stack_a[1] > stack_a[2])
		&& (stack_a[0] < stack_a[2]))
	{
		ss_a(stack_a, numbers_in_stack_a);
		rs_a(stack_a, numbers_in_stack_a);
	}
	if ((stack_a[0] < stack_a[1]) && (stack_a[1] > stack_a[2])
		&& (stack_a[0] > stack_a[2]))
		rrs_a(stack_a, numbers_in_stack_a);
}
