/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smem.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpollini <lpollini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 15:34:08 by lpollini          #+#    #+#             */
/*   Updated: 2023/07/11 16:01:48 by lpollini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	nxt(char *mv, int i)
{
	while (mv[++i])
		if (mv[i])
			return (i);
	ft_exit(1);
	return (-1);
}

static int	find_stuff_1(char *ms, int *i)
{
	if ((ms[*i] * ms[*i]) == 4 && ms[*i] + ms[nxt(ms, *i)] == 0)
	{
		ms[*i] = 4;
		ms[nxt(ms, *i)] = 10;
		*i -= 10;
		return (1);
	}
	if (((ms[*i] & BITSGN) == 3 && (ms[nxt(ms, *i)] & BITSGN) == 6) || \
				((ms[*i] & BITSGN) == 5 && ms[*i] + ms[nxt(ms, *i)] == 0))
	{
		ms[*i] = 0;
		ms[nxt(ms, *i)] = 10;
		*i -= 10;
		return (2);
	}
	return (0);
}

static int	find_stuff(char *ms, int *i)
{
	if ((ms[*i] & BITSGN) == 3 && ms[*i] + ms[nxt(ms, *i)] == 0)
	{
		if ((ms[*i] & BITSGN) < 0)
			ms[*i] = -5;
		else
			ms[*i] = 5;
		ms[nxt(ms, *i)] = 10;
		*i -= 10;
		return (1);
	}
	return (find_stuff_1(ms, i));
}

static int	better_smem(char *ms, int len)
{
	int	i;
	int	res;

	i = -1;
	res = len;
	while (++i < len - 1)
		res -= find_stuff(ms, &i);
	return (res);
}

int	smem(int a)
{
	static char	moves[BIG];
	static int	len;
	int			i;
	int			res;

	if (a == 100)
	{
		return (0);
	}
	if (!a)
	{
		i = 0;
		res = better_smem(moves, len);
		while (i < len)
			trslate(moves[i++]);
		return (res);
	}
	moves[len++] = a;
	return (0);
}
