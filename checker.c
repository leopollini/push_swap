/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpollini <lpollini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:09:30 by lpollini          #+#    #+#             */
/*   Updated: 2023/07/11 16:26:21 by lpollini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_exec(t_all *st, char *cmd)
{
	if (!ft_strncmp(cmd, "pb\n", 3))
		return ((void )pb(st));
	if (!ft_strncmp(cmd, "pa\n", 3))
		return ((void )pa(st));
	if (!ft_strncmp(cmd, "sa\n", 3))
		return ((void )sa(st));
	if (!ft_strncmp(cmd, "sb\n", 3))
		return ((void )sb(st));
	if (!ft_strncmp(cmd, "ss\n", 3))
		return ((void )ss(st));
	if (!ft_strncmp(cmd, "ra\n", 3))
		return ((void )ra(st));
	if (!ft_strncmp(cmd, "rb\n", 3))
		return ((void )rb(st));
	if (!ft_strncmp(cmd, "rra\n", 4))
		return ((void )rra(st));
	if (!ft_strncmp(cmd, "rrb\n", 4))
		return ((void )rrb(st));
	if (!ft_strncmp(cmd, "rr\n", 3))
		return ((void )rr(st));
	if (!ft_strncmp(cmd, "rrr\n", 4))
		return ((void )rrr(st));
}

int	sayok( void )
{
	ft_putstr("\033[1;32m");
	ft_putstr("OK\n");
	ft_putstr("\033[0m");
	return (0);
}

int	end_checker(t_all *st)
{
	free(st->a - st->len + st->lena);
	free(st->b - st->lena);
	sayok();
	return (0);
}

int	main(int argn, char *args[])
{
	t_all	stuff;
	char	*buff;

	if (argn == 1)
		return (0);
	init_stacks(&stuff, argn, args);
	if (checkok(stuff.a, stuff.lena) && stuff.len == stuff.lena)
		return (end_checker(&stuff));
	buff = get_next_line(0);
	while (buff && *buff && *buff != '\n')
	{
		ft_exec(&stuff, buff);
		free(buff);
		if (checkok(stuff.a, stuff.lena) && stuff.len == stuff.lena)
			return (end_checker(&stuff));
		buff = get_next_line(0);
	}
	free(buff);
	free(stuff.a - stuff.len + stuff.lena);
	free(stuff.b - stuff.lena);
	ft_putstr("\033[1;31m");
	ft_putstr("KO\n");
	ft_putstr("\033[0m");
}
