/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_a_solve_four.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpollini <lpollini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:49:39 by lpollini          #+#    #+#             */
/*   Updated: 2023/07/11 15:36:41 by lpollini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, str + i++, 1);
	return (i);
}

static int	a_solve_four_hb1(int *a, t_all *st)
{
	if ((a[0] < a[2] && a[0] < a[3]) && (a[1] < a[2] && a[1] < a[3]))
	{
		if (checkok(a + 2, 2))
		{
			sa(st);
			return (1);
		}
		perform(pb, 2, st);
		if (st->a[0] > st->a[1])
			sa(st);
		if (st->b[0] < st->b[1])
			sb(st);
		perform(pa, 2, st);
	}
	else if (posof(a, minim(a, 4), 4) < 2)
	{
		if (posof(a, minim(a, 4), 4) == 1)
			sa(st);
		pb(st);
		a_solve_three(st->a, 3, st);
		pa(st);
	}
	else
		return (0);
	return (1);
}

static int	a_solve_four_hb2(int *a, int len, t_all *st)
{
	if (checkok(a, 4))
		return (1);
	if (len < 4)
	{
		a_solve_three(a, len, st);
		return (1);
	}
	if (a_solve_four_hb1(a, st))
		return (1);
	if (minim(a, 2) > a[2] && minim(a, 2) > a[3])
	{
		perform(pb, 2, st);
		if (st->a[0] > st->a[1])
			sa(st);
		if (st->b[0] < st->b[1])
			sb(st);
		perform(ra, 2, st);
		perform(pa, 2, st);
		perform(rra, 2, st);
		return (1);
	}
	return (0);
}

static void	a_solve_four_hb3(int *a, t_all *st)
{
	if (posof(a, maxim(a, 4), 4) == 3)
		a_solve_three(a, 3, st);
	else
	{
		perform(pb, 2, st);
		sa(st);
		if (st->b[0] < st->b[1])
			sb(st);
		ra(st);
		perform(pa, 2, st);
		rra(st);
	}
}

void	a_solve_four(int *a, int len, t_all *st)
{
	if (a_solve_four_hb2(a, len, st))
		return ;
	if (posof(a, maxim(a, 4), 4) < 2)
	{
		if (a[0] > a[1])
			sa(st);
		pb(st);
		ra(st);
		if (st->a[0] > st->a[1])
			sa(st);
		pb(st);
		rra(st);
		sa(st);
		sb(st);
		perform(pa, 2, st);
		return ;
	}
	a_solve_four_hb3(a, st);
}
