/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpollini <lpollini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:31:03 by lpollini          #+#    #+#             */
/*   Updated: 2023/07/11 15:25:55 by lpollini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	ra(t_all *stuff)
{
	int	i;
	int	t;

	if (!stuff->lena)
		ft_exit(TOOFEWROTATE);
	t = stuff->a[0];
	i = 0;
	while (i < stuff->lena)
	{
		stuff->a[i] = stuff->a[i + 1];
		i++;
	}
	stuff->a[i - 1] = t;
	smem(3);
	return (1);
}

int	rra(t_all *stuff)
{
	int	i;
	int	t;

	if (!stuff->lena)
		ft_exit(TOOFEWROTATE);
	t = stuff->a[stuff->lena - 1];
	i = stuff->lena - 1;
	while (i)
	{
		stuff->a[i] = stuff->a[i - 1];
		i--;
	}
	stuff->a[0] = t;
	smem(6);
	return (1);
}

int	rb(t_all *stuff)
{
	int	i;
	int	t;

	if (stuff->lena == stuff->len)
		ft_exit(TOOFEWROTATE);
	t = stuff->b[0];
	i = 0;
	while (i < stuff->len - stuff->lena)
	{
		stuff->b[i] = stuff->b[i + 1];
		i++;
	}
	stuff->b[i - 1] = t;
	smem(-3);
	return (1);
}

int	rrb(t_all *stuff)
{
	int	i;
	int	t;

	if (stuff->lena == stuff->len)
		ft_exit(TOOFEWROTATE);
	t = stuff->b[stuff->len - stuff->lena - 1];
	i = stuff->len - stuff->lena - 1;
	while (i)
	{
		stuff->b[i] = stuff->b[i - 1];
		i--;
	}
	stuff->b[0] = t;
	smem(-6);
	return (1);
}

int	rr(t_all *stuff)
{
	ra(stuff);
	rb(stuff);
	smem(5);
	return (1);
}
