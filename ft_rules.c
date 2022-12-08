/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechaoub <aechaoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:02:28 by aechaoub          #+#    #+#             */
/*   Updated: 2022/12/06 14:41:51 by aechaoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	pb(t_arays *info)
{
	int	o;

	o = info->x_a;
	if (o == -1)
		return ;
	info->tab_b[info->f_e - o - 1] = info->tab_a[o];
	info->tab_a[o] = 0;
	write(1, "pb\n", 3);
	info->x_a--;
}

void	pa(t_arays *info)
{
	int	o;

	o = info->f_e - info->x_a - 2;
	if (o == -1)
		return ;
	info->tab_a[info->x_a + 1] = info->tab_b[o];
	info->tab_b[o] = 0;
	write(1, "pa\n", 3);
	info->x_a++;
}

void	rotate_2el(int *tab, int size, int indexa)
{
	int	o;
	int	y;

	if (size < 1)
		return ;
	if (indexa < 1)
		return ;
	o = indexa;
	y = tab[o];
	while (o)
	{
		tab[o] = tab[o - 1];
		o--;
	}
	tab[o] = y;
}

void	ra(int *tab, int size, int indexa)
{
	rotate_2el(tab, size, indexa);
	write(1, "ra\n", 3);
}

void	rb(int *tab, int size, int indexa)
{
	rotate_2el(tab, size, size - indexa - 2);
	write(1, "rb\n", 3);
}
