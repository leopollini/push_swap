/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpollini <lpollini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 19:31:03 by lpollini          #+#    #+#             */
/*   Updated: 2023/07/11 15:26:08 by lpollini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	pb(t_all *stuff)
{
	if (!stuff->lena)
		ft_exit(TOOMANYPUSH);
	stuff->b--;
	stuff->b[0] = stuff->a[0];
	stuff->a++;
	stuff->lena--;
	smem(1);
	return (1);
}

int	pa(t_all *stuff)
{
	if (stuff->lena == stuff->len)
		ft_exit(TOOMANYPUSH);
	stuff->a--;
	stuff->a[0] = stuff->b[0];
	stuff->b++;
	stuff->lena++;
	smem(-1);
	return (1);
}

int	sa(t_all *stuff)
{
	int	temp;

	temp = stuff->a[0];
	stuff->a[0] = stuff->a[1];
	stuff->a[1] = temp;
	smem(2);
	return (1);
}

int	sb(t_all *stuff)
{
	int	temp;

	if (stuff->len - stuff->lena < 2)
		ft_exit(TOOFEWSWAP);
	temp = stuff->b[0];
	stuff->b[0] = stuff->b[1];
	stuff->b[1] = temp;
	smem(-2);
	return (1);
}

int	ss(t_all *stuff)
{
	sa(stuff);
	sb(stuff);
	smem(4);
	return (1);
}
