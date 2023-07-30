/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_part.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpollini <lpollini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:44:24 by lpollini          #+#    #+#             */
/*   Updated: 2023/07/11 14:54:04 by lpollini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rsa_part(t_all *st, int h2, int h4, t_vector3_i *t)
{
	if (st->a[0] >= h2)
	{
		pb(st);
		t->a++;
	}
	else if (st->a[0] >= h4)
	{
		ra(st);
		t->b++;
	}
	else
	{
		pb(st);
		rb(st);
		t->c++;
	}
}

static void	rsb_part(t_all *st, int h2, int h4, t_vector3_i *t)
{
	if (st->b[0] >= h2)
	{
		pa(st);
		t->a++;
	}
	else if (st->b[0] >= h4)
	{
		rb(st);
		t->b++;
	}
	else
	{
		pa(st);
		ra(st);
		t->c++;
	}
}

void	recursion_side_a(t_all *st, int h2, int h4, int testlen)
{
	int			i;
	t_vector3_i	t;

	i = 0;
	t.a = 0;
	t.b = 0;
	t.c = 0;
	testlen -= a_hmany_ok(st, testlen);
	if (testlen < 5)
		return (a_solve_four(st->a, testlen, st));
	while (i++ < testlen)
		rsa_part(st, h2, h4, &t);
	recursion_side_b(st, o_t_p(st->b, t.a, 2), o_t_p(st->b, t.a, 4), t.a);
	perform(rra, t.b, st);
	recursion_side_a(st, o_t_p(st->a, t.b, 2), o_t_p(st->a, t.b, 4), t.b);
	perform(rrb, t.c, st);
	recursion_side_b(st, o_t_p(st->b, t.c, 2), o_t_p(st->b, t.c, 4), t.c);
}

void	recursion_side_b(t_all *st, int h2, int h4, int testlen)
{
	int			i;
	t_vector3_i	t;

	i = 0;
	t.a = 0;
	t.b = 0;
	t.c = 0;
	testlen -= b_hmany_ok(st, testlen);
	if (testlen < 5)
		return (b_solve_four(st->b, testlen, st));
	while (i++ < testlen)
		rsb_part(st, h2, h4, &t);
	recursion_side_a(st, o_t_p(st->a, t.a, 2), o_t_p(st->a, t.a, 4), t.a);
	perform(rrb, t.b, st);
	recursion_side_b(st, o_t_p(st->b, t.b, 2), o_t_p(st->b, t.b, 4), t.b);
	perform(rra, t.c, st);
	recursion_side_a(st, o_t_p(st->a, t.c, 2), o_t_p(st->a, t.c, 4), t.c);
}

void	second(t_all *st)
{
	int	i;

	i = st->varn[0] + 1;
	while (--i > 1)
		recursion_side_b(st, o_t_p(st->b, st->varn[i], 2), \
					o_t_p(st->b, st->varn[i], 4), st->varn[i]);
	i = st->len - st->lena;
	recursion_side_b(st, o_t_p(st->b, i, 2), o_t_p(st->b, i, 4), i);
}
