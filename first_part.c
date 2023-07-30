/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_part.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpollini <lpollini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:34:08 by lpollini          #+#    #+#             */
/*   Updated: 2023/07/11 15:03:49 by lpollini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	posof(int *a, const int f, int len)
{
	while (len--)
		if (a[len] == f)
			return (len);
	return (-1);
}

static void	a_empty_solve_three(int *a, int len, t_all *st)
{
	if (len == 2 && a[0] > a[1])
		sa(st);
	if (len == 2)
		return ;
	if ((a[0] > a[1]) ^ (a[1] > a[2]) ^ (a[0] > a[2]))
		sa(st);
	if (a[0] > a[2])
	{
		if (a[1] < a[2])
			ra(st);
		else
			rra(st);
	}
}

int	find_part(int *s, int len)
{
	int	res;

	res = (maxim(s, len) + minim(s, len)) / 2;
	while (greater_than(s, len, res) > len / 2)
		res++;
	while (greater_than(s, len, res) < len / 2)
		res--;
	return (res);
}

static int	reach_next(t_all *st, int halb)
{
	int	h1;
	int	h2;
	int	ret;

	h1 = 0;
	h2 = st->lena - 1;
	while (st->a[h1] > halb && h1 < st->lena)
		h1++;
	while (st->a[h2] > halb && h2 >= 0)
		h2--;
	ret = 0;
	if (st->a[h1] == st->a[h2])
		ret = 1;
	if (h1 == st->lena - h2)
		if (st->a[h1] > st->a[h2])
			h2--;
	if (h1 < st->lena - h2)
		perform(ra, h1, st);
	else
		perform(rra, st->lena - h2, st);
	pb(st);
	return (ret);
}

void	first(t_all *st)
{
	int	halb;
	int	i;

	i = 1;
	while (st->lena > 3)
	{
		halb = find_part(st->a, st->lena);
		st->halbs[i] = halb;
		st->varn[i] = 1;
		while (st->lena > st->len / (1 << i))
		{
			if (reach_next(st, halb - 1))
				break ;
			st->varn[i]++;
		}
		i++;
	}
	st->varn[0] = i - 1;
	a_empty_solve_three(st->a, st->lena, st);
}
