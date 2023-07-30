/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpollini <lpollini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:17:14 by lpollini          #+#    #+#             */
/*   Updated: 2023/07/11 15:44:27 by lpollini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argn, char *args[])
{
	t_all	stuff;

	if (argn < 2)
		return (0);
	init_stacks(&stuff, argn, args);
	if (stuff.len < 2)
		ft_exit(DONESORTING);
	if (!checkok(stuff.a, stuff.lena))
		dosort(&stuff);
	smem(0);
	free(stuff.a - stuff.len + stuff.lena);
	free(stuff.b - stuff.lena);
	return (0);
}
