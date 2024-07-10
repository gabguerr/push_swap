/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabguerr <gabguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:29:13 by gabguerr          #+#    #+#             */
/*   Updated: 2024/07/02 18:56:24 by gabguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_and_exit(int *nbr_s_a, int *nbr_s_b)
{
	free(nbr_s_a);
	free(nbr_s_b);
	exit(0);
}

void	free_and_exit_without_errors(int *nbr_s_a, int *nbr_s_b)
{
	free(nbr_s_a);
	free(nbr_s_b);
	write(1, "Error\n", 6);
	exit(0);
}

void	check_parameters(int argc, char **argv, int *nbr_s_a, int *nbr_s_b)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc < 2)
		free_and_exit(nbr_s_a, nbr_s_b);
	while (i < argc)
	{
		if ((argv[i][ft_strlen(argv[i]) - 1] == ' ') || (argv[i][0] == ' '))
			free_and_exit_without_errors(nbr_s_a, nbr_s_b);
		j = 0;
		while (j < ft_strlen(argv[i]))
		{
			if (((argv[i][j] < 48) || (argv[i][j] > 57)) && (argv[i][j] != 32))
			{
				if (argv[i][j] != 45)
					free_and_exit_without_errors(nbr_s_a, nbr_s_b);
			}
			if ((argv[i][j] == 32) && (argv[i][j + 1] == 32))
				free_and_exit_without_errors(nbr_s_a, nbr_s_b);
			j++;
		}
		i++;
	}
}

void	set_numbers(int *nbr_s_a, int *nbr_s_b, int argc)
{
	nbr_s_a[0] = argc - 1;
	nbr_s_a[1] = nbr_s_a[0];
	*nbr_s_b = 0;
}

int	main(int argc, char **argv)
{
	long	*s_a;
	long	*s_b;
	int		*nbr_s_a;
	int		*nbr_s_b;

	nbr_s_a = (int *)malloc(2 * sizeof(int));
	nbr_s_b = (int *)malloc(sizeof(int));
	check_parameters(argc, argv, nbr_s_a, nbr_s_b);
	set_numbers(nbr_s_a, nbr_s_b, argc);
	s_a = (long *)malloc(sizeof(long) * ss(argc, argv));
	s_b = (long *)malloc(sizeof(long) * ss(argc, argv));
	if ((seperating_input_numbers(s_a, nbr_s_a, argv) == -1)
		|| (is_stack_sorted(s_a, nbr_s_a) == 0))
		free_s(s_a, s_b, nbr_s_a, nbr_s_b);
	if ((nbr_s_a[1] == 2) && (s_a[0] > s_a[1]))
		rs_a(s_a, nbr_s_a);
	else if (nbr_s_a[1] == 3)
		sort_3_nbr(s_a, nbr_s_a);
	else if (nbr_s_a[1] == 5)
		sort_5_nbr(s_a, s_b, nbr_s_a, nbr_s_b);
	else
		sort_3_5_nbr(s_a, s_b, nbr_s_a, nbr_s_b);
	free_s(s_a, s_b, nbr_s_a, nbr_s_b);
	return (0);
}
