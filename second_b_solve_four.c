/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_b_solve_four.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpollini <lpollini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:49:39 by lpollini          #+#    #+#             */
/*   Updated: 2023/07/11 14:54:12 by lpollini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checkok_r(int *s, int len)
{
	while (--len)
		if (s[len] > s[len - 1])
			return (0);
	return (1);
}

static int	b_solve_four_hb(int *b, int len, t_all *st)
{
	if (!len)
		return (1);
	if (len < 4)
		b_solve_three(b, len, st);
	else if (checkok_r(b, 4))
		perform(pa, 4, st);
	else if (posof(b, maxim(b, 4), 4) < 2)
	{
		if (posof(b, maxim(b, 4), 4) == 1)
			sb(st);
		pa(st);
		b_solve_three(st->b, 3, st);
	}
	else if (posof(b, minim(b, 4), 4) < 2)
	{
		if (posof(b, minim(b, 4), 4) == 1)
			sb(st);
		rb(st);
		b_solve_three(st->b, 3, st);
		rrb(st);
		pa(st);
	}
	else
		return (0);
	return (1);
}

void	b_solve_four(int *b, int len, t_all *st)
{
	if (b_solve_four_hb(b, len, st))
		return ;
	if (posof(b, minim(b, 4), 4) == 3)
	{
		b_solve_three(st->b, 3, st);
		pa(st);
	}
	else
	{
		pa(st);
		pa(st);
		sb(st);
		if (st->a[0] > st->a[1])
			sa(st);
		ra(st);
		pa(st);
		sa(st);
		rra(st);
		pa(st);
	}
}

int	b_hmany_ok(t_all *st, int len)
{
	int	res;

	res = 0;
	while (st->b[0] == maxim(st->b, len) && res < len && len > 1)
	{
		pa(st);
		res++;
	}
	return (res);
}

int	a_hmany_ok(t_all *st, int len)
{
	int	res;

	res = 0;
	while (posof(st->a, maxim(st->a, len), len) == len - 1 - res \
				&& res < len && len > 1)
		res++;
	return (res);
}
