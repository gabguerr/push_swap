/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabguerr <gabguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:37:07 by gabguerr          #+#    #+#             */
/*   Updated: 2024/07/02 20:56:12 by gabguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isdigit(int i)
{
	while ('0' <= i && i <= '9')
		return (1);
	return (0);
}

int	is_only_numbers_in_the_stacks(char *numbers)
{
	int	i;
	int	minus;

	i = 0;
	minus = 0;
	while (numbers[i])
	{
		if (numbers[i] == 45)
			minus++;
		else if (ft_isdigit(numbers[i]) == 0)
			return (0);
		i++;
	}
	if (minus > 1)
		return (0);
	return (1);
}

int	number_limits(long *s_a, int nbr_s_a)
{
	int	i;

	i = 0;
	while (i < nbr_s_a)
	{
		if ((s_a[i] > 2147483647) || (s_a[i] < -2147483648))
		{
			write(1, "Error\n", 6);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	is_stack_sorted(long *s_a, int *nbr_s_a)
{
	int		i;
	int		j;
	long	max;

	i = 1;
	j = 0;
	max = s_a[0];
	while (i < nbr_s_a[1])
	{
		if (s_a[i] > max)
		{
			max = s_a[i];
			j++;
		}
		i++;
	}
	if (j == nbr_s_a[1] - 1)
		return (0);
	return (-1);
}
