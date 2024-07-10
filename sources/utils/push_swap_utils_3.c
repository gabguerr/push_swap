/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabguerr <gabguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:37:17 by gabguerr          #+#    #+#             */
/*   Updated: 2024/07/07 16:41:57 by gabguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

long	ft_atol(char *str)
{
	long	i;
	long	negative;
	long	result;

	i = 0;
	negative = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (negative)
		result = -result;
	return (result);
}

void	free_string(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
}

int	numbers_input(long *s_a, int *nbr_s_a, char **argv, char**numbers_list)
{
	int	i;
	int	numbers;

	i = 0;
	numbers = 0;
	numbers_list = ft_split(argv[1], 32);
	while (numbers_list[i])
	{
		numbers++;
		i++;
	}
	nbr_s_a[0] = numbers;
	nbr_s_a[1] = nbr_s_a[0];
	i = 0;
	while (i < nbr_s_a[0])
	{
		s_a[i] = ft_atol(numbers_list[i]);
		i++;
	}
	free_string(numbers_list);
	free(numbers_list);
	return (0);
}

int	standard_input(long *s_a, int *nbr_s_a, char **argv)
{
	int	i;

	i = 0;
	while (i < nbr_s_a[1])
	{
		if (is_only_numbers_in_the_stacks(argv[i + 1]) == 1)
			s_a[i] = ft_atol(argv[i + 1]);
		else
		{
			write(1, "Error\n", 6);
			return (-1);
		}
		i++;
	}
	return (0);
}

int	seperating_input_numbers(long *s_a, int *nbr_s_a, char **argv)
{
	char	**numbers_list;

	numbers_list = NULL;
	if (nbr_s_a[0] == 1)
	{
		if (numbers_input(s_a, nbr_s_a, argv, numbers_list) == -1)
			return (-1);
	}
	else
	{
		if (standard_input(s_a, nbr_s_a, argv) == -1)
			return (-1);
	}
	if (repeated_numbers(s_a, nbr_s_a[1]) == -1)
		return (-1);
	if (number_limits(s_a, nbr_s_a[1]) == -1)
		return (-1);
	return (0);
}
