/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabguerr <gabguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:36:55 by gabguerr          #+#    #+#             */
/*   Updated: 2024/07/02 18:33:04 by gabguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	free_s(long *s_a, long *s_b, int *nbr_s_a, int *nbr_s_b)
{
	free(s_a);
	free(s_b);
	free(nbr_s_a);
	free(nbr_s_b);
	exit(0);
}

int	ss(int argc, char **argv)
{
	int	i;
	int	size;

	i = 0;
	size = 1;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == 32)
				size++;
			i++;
		}
	}
	else
		size = argc - 1;
	return (size);
}

int	repeated_numbers(long *s_a, int nbr_s_a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < nbr_s_a)
	{
		j = 0;
		while (j < nbr_s_a)
		{
			if ((s_a[i] == s_a[j]) && (i != j))
			{
				write(1, "Error\n", 6);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_reallocation(long *pointer, int startsize, int newsize)
{
	int		i;
	long	*temporary;

	i = 0;
	if ((pointer != NULL) && (startsize < newsize))
	{
		temporary = malloc(sizeof(long) * (newsize));
		while (i < startsize)
		{
			temporary[i] = pointer[i];
			i++;
		}
		pointer = temporary;
	}
	else if ((pointer != NULL) && (startsize > newsize))
	{
		temporary = malloc(sizeof(long) * (newsize));
		while (i < newsize)
		{
			temporary[i] = pointer[i];
			i++;
		}
		pointer = temporary;
	}
}

void	parameters(long *s_a, long *s_b, int *nbr_s_a, int *nbr_s_b)
{
	ps_a(s_a, s_b, nbr_s_a, nbr_s_b);
	rs_a(s_a, nbr_s_a);
}
