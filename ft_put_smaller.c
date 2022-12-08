/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_smaller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechaoub <aechaoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:34:01 by aechaoub          #+#    #+#             */
/*   Updated: 2022/12/04 15:10:59 by aechaoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	put_smaller_1(t_arays *info, int po)
{
	int	*tab_b;

	tab_b = info->tab_b;
	if (!(po < info->x_a - po - 1))
	{
		while (tab_b[findmax_b(info)] != tab_b[info->f_e - info->x_a - 2]
			&& po++ <= info->x_a - 1)
			rr(info->tab_a, tab_b, info->f_e, info->x_a);
	}
	if (po < info->x_a - po - 1)
	{
		while (po-- >= 0)
			rra(info->tab_a, info->f_e, info->x_a);
	}
	else
	{
		while (po++ <= info->x_a - 1)
		{
			ra(info->tab_a, info->f_e, info->x_a);
		}
	}
	while (tab_b[findmax_b(info)] != tab_b[info->f_e - info->x_a - 2])
		rb(tab_b, info->f_e, info->x_a);
}

void	put_smaller_2(t_arays *info, int po)
{
	int	*tab_b;

	tab_b = info->tab_b;
	if (po < info->x_a - po - 1)
	{
		while (tab_b[findmax_b(info)] != tab_b[info->f_e - info->x_a - 2]
			&& po >= 0)
		{
			rrr(info->tab_a, info->tab_b, info->f_e, info->x_a);
			po--;
		}
		while (po >= 0)
		{
			rra(info->tab_a, info->f_e, info->x_a);
			po--;
		}
	}
	else
	{
		while (po++ <= info->x_a - 1)
			ra(info->tab_a, info->f_e, info->x_a);
	}
	while (tab_b[findmax_b(info)] != tab_b[info->f_e - info->x_a - 2])
		rrb(info->tab_b, info->f_e, info->x_a);
}

void	put_smaller(t_arays *info, int po)
{
	int	*tab_b;
	int	sm;

	tab_b = info->tab_b;
	sm = smallerone(tab_b, info->f_e - info->x_a - 1, info->tab_a[po]);
	if (sm >= info->f_e - info->x_a - 2 - sm)
	{
		put_smaller_1(info, po);
	}
	else
	{
		put_smaller_2(info, po);
	}
	pb(info);
}
