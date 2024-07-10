/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabguerr <gabguerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 10:04:39 by gabguerr          #+#    #+#             */
/*   Updated: 2024/07/02 19:10:27 by gabguerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

void	ps_a(long *s_a, long *s_b, int *nbr_s_a, int *nbr_s_b);
void	ps_b(long *s_a, long *s_b, int *nbr_s_a, int *nbr_s_b);

void	ss_a(long *s_a, int *nbr_s_a);

void	rs_a(long *s_a, int *nbr_s_a);
void	rs_b(long *s_b, int *nbr_s_b);
void	rs_a_b(long *s_a, long *s_b, int *nbr_s_a, int *nbr_s_b);

void	rrs_a(long *s_a, int *nbr_s_a);

void	free_s(long *s_a, long *s_b, int *nbr_s_a, int *nbr_s_b);
void	parameters(long *s_a, long *s_b, int *nbr_s_a, int *nbr_s_b);

void	sort_3_nbr(long *s_a, int *nbr_s_a);
void	sort_5_nbr(long *s_a, long *s_b, int *nbr_s_a, int *nbr_s_b);
void	sort_3_5_nbr(long *s_a, long *s_b, int *nbr_s_a, int *nbr_s_b);

int		ft_strlen(const char *str);
int		number_limits(long *s_a, int nbr_s_a);
int		repeated_numbers(long *s_a, int nbr_s_a);
int		is_only_numbers_in_the_stacks(char *numbers);
int		ss(int argc, char **argv);
int		seperating_input_numbers(long *s_a, int *nbr_s_a, char **argv);
int		is_stack_sorted(long *s_a, int *nbr_s_a);

char	**ft_split(char const *str, char c);

#endif
