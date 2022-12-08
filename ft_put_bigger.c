/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_bigger.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechaoub <aechaoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:33:32 by aechaoub          #+#    #+#             */
/*   Updated: 2022/12/04 15:11:37 by aechaoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	put_bigger_1(t_arays *info, int po)
{
	int	*tab_b;

	tab_b = info->tab_b;
	while (tab_b[findmax_b(info)] != tab_b[info->f_e - info->x_a - 2]
		&& po <= info->x_a - 1)
	{
		rr(info->tab_a, tab_b, info->f_e, info->x_a);
		po++;
	}
	if (po < info->x_a - po - 1)
	{
		while (po-- >= 0)
			rra(info->tab_a, info->f_e, info->x_a);
	}
	else
	{
		while (po++ <= info->x_a - 1)
			ra(info->tab_a, info->f_e, info->x_a);
	}
	while (tab_b[findmax_b(info)] != tab_b[info->f_e - info->x_a - 2])
		rb(tab_b, info->f_e, info->x_a);
}

void	put_bigger_2(t_arays *info, int po)
{
	int	*tab_b;

	tab_b = info->tab_b;
	if (po < info->x_a - po - 1)
	{
		while (tab_b[findmax_b(info)] != tab_b[info->f_e - info->x_a - 2]
			&& po-- >= 0)
			rrr(info->tab_a, info->tab_b, info->f_e, info->x_a);
		while (po >= 0)
		{
			rra(info->tab_a, info->f_e, info->x_a);
			po--;
		}
	}
	else
	{
		while (po <= info->x_a - 1)
		{
			ra(info->tab_a, info->f_e, info->x_a);
			po++;
		}
	}
	while (tab_b[findmax_b(info)] != tab_b[info->f_e - info->x_a - 2])
		rrb(info->tab_b, info->f_e, info->x_a);
}

void	put_bigger(t_arays *info, int po)
{
	int	*tab_b;
	int	*tab_a;
	int	f_e;
	int	x_a;
	int	sm;

	x_a = info->x_a;
	f_e = info->f_e;
	tab_b = info->tab_b;
	tab_a = info->tab_a;
	sm = smallerone(tab_b, f_e - x_a - 1, tab_a[po]);
	if (sm > f_e - x_a - 2 - smallerone(tab_b, f_e - x_a - 2, tab_a[po]))
	{
		put_bigger_1(info, po);
	}
	else
	{
		put_bigger_2(info, po);
	}
	pb(info);
}
