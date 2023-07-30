/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpollini <lpollini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:44:38 by lpollini          #+#    #+#             */
/*   Updated: 2023/07/11 15:48:52 by lpollini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(int e)
{
	printf("called. %i\n", e);
	if (e != DONESORTING)
		write(STDERR_FILENO, "Error\n", 7);
	exit(e);
}

void	trslate(int m)
{
	if (m == 1)
		write(1, "pb\n", 3);
	if (m == -1)
		write(1, "pa\n", 3);
	if (m == 2)
		write(1, "sa\n", 3);
	if (m == -2)
		write(1, "sb\n", 3);
	if (m == 4)
		write(1, "ss\n", 3);
	if (m == 3)
		write(1, "ra\n", 3);
	if (m == -3)
		write(1, "rb\n", 3);
	if (m == 6)
		write(1, "rra\n", 4);
	if (m == -6)
		write(1, "rrb\n", 4);
	if (m == 5)
		write(1, "rr\n", 3);
	if (m == -5)
		write(1, "rrr\n", 4);
}

int	checkok(int *s, int len)
{
	while (--len)
		if (s[len] < s[len - 1])
			return (0);
	return (1);
}

void	dosort(t_all *st)
{
	first(st);
	if (st->len > 3)
		second(st);
}
