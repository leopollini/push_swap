/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpollini <lpollini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 16:32:07 by lpollini          #+#    #+#             */
/*   Updated: 2023/07/11 15:13:09 by lpollini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	init_stacks(t_all *stuff, int argn, char *strs[])
{
	stuff->a = malloc(8 * MAX);
	stuff->b = malloc(8 * MAX);
	stuff->len = ft_better_atoi(stuff->a, strs, argn - 1);
	stuff->lena = stuff->len;
	stuff->b += stuff->lena;
	do_check(stuff->a, stuff->len);
}

void	lolcheck(char *str, int *lol, int i)
{
	if (str[i])
		*lol += i;
	else
		*lol = 0;
}

static int	ft_atoi(char *str, int *lol)
{
	long	i;
	long	nbr;
	int		isneg;

	i = 0;
	nbr = 0;
	isneg = 0;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t' || \
				str[i] == '\n' || str[i] == '\r' || str[i] == \
				'\v' || str[i] == '\f'))
		i++;
	if (str[i] != '\0' && str[i] == '-')
	{
		isneg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i] <= '9' && str[i] >= '0')
		nbr = (nbr * 10) + (str[i++] - '0');
	lolcheck(str, lol, i);
	if (isneg == 1)
		return (-nbr);
	return (nbr);
}

int	ft_better_atoi(int *a, char *strs[], int max)
{
	int	h;
	int	i;
	int	lol;

	h = 0;
	i = 0;
	lol = 0;
	while (i + h < max)
	{
		a[i] = ft_atoi(strs[i + h + 1] + lol, &lol);
		if (lol)
			h--;
		i++;
	}
	return (i);
}

void	do_check(int *a, int len)
{
	int	i;
	int	j;

	i = -1;
	while (++i < len)
	{
		j = i;
		while (++j < len)
			if (a[i] == a[j])
				ft_exit(REPEATEDNUM);
	}
}
