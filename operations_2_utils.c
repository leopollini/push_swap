/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpollini <lpollini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:31:03 by lpollini          #+#    #+#             */
/*   Updated: 2023/07/11 15:04:10 by lpollini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	perform(int (f)(t_all *), int times, t_all *st)
{
	while (times--)
		f(st);
}

int	minim(int *s, int len)
{
	int	res;

	res = 0x7FFFFFFF;
	while (len--)
		if (s[len] < res)
			res = s[len];
	return (res);
}

int	maxim(int *s, int len)
{
	int	res;

	res = 0x80000000;
	while (len--)
		if (s[len] > res)
			res = s[len];
	return (res);
}

int	greater_than(int *s, int len, int test)
{
	int	res;
	int	i;

	i = -1;
	res = 0;
	while (++i < len)
		if (s[i] >= test)
			res++;
	return (res);
}

int	rrr(t_all *stuff)
{
	rra(stuff);
	rrb(stuff);
	smem(-5);
	return (0);
}
