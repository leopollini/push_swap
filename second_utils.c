/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpollini <lpollini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:34:08 by lpollini          #+#    #+#             */
/*   Updated: 2023/07/11 15:20:09 by lpollini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	b_solve_two(t_all *st)
{
	if (st->b[0] < st->b[1])
		sb(st);
	pa(st);
	pa(st);
}

void	b_solve_three(int *b, int len, t_all *st)
{
	t_vector3_i	temp;

	if (len == 1 || st->len - st->lena == 1)
		return ((void )(pa(st)));
	if (len == 2)
		return (b_solve_two(st));
	temp.a = b[0];
	temp.b = b[1];
	temp.c = b[2];
	pa(st);
	if (temp.b < temp.c)
		sb(st);
	pa(st);
	if (temp.a > temp.b && temp.a > temp.c)
		pa(st);
	else
	{
		sa(st);
		pa(st);
		if (temp.a < temp.b && temp.a < temp.c)
			sa(st);
	}
}

void	a_solve_three(int *a, int len, t_all *st)
{
	t_vector3_i	temp;

	if (len == 1)
		return ;
	if (len == 2)
		if (st->a[0] > st->a[1])
			return ((void )sa(st));
	temp.a = a[0];
	temp.b = a[1];
	temp.c = a[2];
	if (temp.a > temp.b)
		sa(st);
	if (!(temp.c > temp.a && temp.c > temp.b))
	{
		ra(st);
		sa(st);
		rra(st);
		if (temp.c < temp.b && temp.c < temp.a)
			sa(st);
	}
}

int	o_t_p(int *s, int len, int part)
{
	int	res;

	res = (maxim(s, len) + minim(s, len)) / 2;
	while (greater_than(s, len, res) > len - len / part)
		res++;
	while (greater_than(s, len, res) < len - len / part)
		res--;
	return (res);
}
