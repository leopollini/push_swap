/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpollini <lpollini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 11:17:12 by lpollini          #+#    #+#             */
/*   Updated: 2023/07/11 15:46:57 by lpollini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# define BIG 99999
# define MAX 2000
# define SMOL 0xFFFFFFFF
# define DONESORTING 0
# define TOOMANYPUSH 1
# define USELESSROTATE 2
# define TOOFEWROTATE -2
# define TOOFEWSWAP 3
# define REPEATEDNUM 4
# define INPTINVALID 5
# define CHECKERINVALIDINPT -5
# define BITSGN 0x7FFFFFFF

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "get_next_line.h"

typedef struct s_all
{
	int	*a;
	int	*b;
	int	len;
	int	lena;
	int	halbs[50];
	int	varn[50];
}	t_all;

typedef struct s_vector4_i
{
	int	a;
	int	b;
	int	c;
	int	d;
}	t_vector4_i;

typedef struct s_vector3_i
{
	int	a;
	int	b;
	int	c;
}	t_vector3_i;

typedef struct s_quick
{
	int		max;
	int		min;
	long	delta;
	int		mid;
}	t_quick;

int		pb(t_all *stuff);
int		pa(t_all *stuff);
int		sa(t_all *stuff);
int		sb(t_all *stuff);
int		ss(t_all *stuff);
int		ra(t_all *stuff);
int		rra(t_all *stuff);
int		rb(t_all *stuff);
int		rrb(t_all *stuff);
int		rr(t_all *stuff);
int		rrr(t_all *stuff);
int		ft_putstr(char *str);
void	ft_exit(int e);
int		smem(int a);
void	init_stacks(t_all *stuff, int argn, char *strs[]);
int		ft_better_atoi(int *a, char *strs[], int max);
void	do_check(int *a, int len);
void	ft_exit(int e);
int		minim(int *s, int len);
int		maxim(int *s, int len);
int		greater_than(int *s, int len, int test);
void	perform(int (f)(t_all *), int times, t_all *st);
void	first(t_all *st);
int		find_part(int *s, int len);
int		checkok(int *s, int len);
void	recursion_side_a(t_all *st, int h2, int h4, int testlen);
void	recursion_side_b(t_all *st, int h2, int h4, int testlen);
void	trslate(int m);
int		o_t_p(int *s, int len, int part);
int		find_part(int *s, int len);
void	first(t_all *st);
void	second(t_all *st);
void	b_solve_three(int *b, int len, t_all *st);
void	a_solve_three(int *a, int len, t_all *st);
void	a_solve_four(int *a, int len, t_all *st);
void	b_solve_four(int *b, int len, t_all *st);
int		b_hmany_ok(t_all *st, int len);
int		a_hmany_ok(t_all *st, int len);
int		posof(int *a, const int f, int len);
void	dosort(t_all *st);

#endif
