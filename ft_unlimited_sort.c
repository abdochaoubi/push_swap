/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unlimited_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechaoub <aechaoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:52:35 by aechaoub          #+#    #+#             */
/*   Updated: 2022/12/06 14:41:58 by aechaoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	make_stack_good(t_arays *info)
{
	int	*tab_b;

	tab_b = info->tab_b;
	if (info->f_e - findmax_b(info) < findmax_b(info))
	{
		while (tab_b[findmax_b(info)] != tab_b[info->f_e - info->x_a - 2])
			rb(info->tab_b, info->f_e, info->x_a);
	}
	else
	{
		while (tab_b[findmax_b(info)] != tab_b[info->f_e - info->x_a - 2])
			rrb(info->tab_b, info->f_e, info->x_a);
	}
}

void	sort_unlimited(t_arays *info)
{
	int	po;
	int	findmn;

	while (info->x_a >= 0)
	{
		po = index_best_el(info, 0);
		if (info->f_e - info->x_a - 1 == 0)
			pb(info);
		else
		{
			findmn = findmin(info->tab_b, info->f_e - info->x_a - 1);
			if (info->tab_a[po] >= info->tab_b[findmax_b(info)])
				put_bigger(info, po);
			else if (info->tab_a[po] < info->tab_b[findmn])
				put_smaller(info, po);
			else
				put_inside(info, po);
		}
	}
	make_stack_good(info);
	while (info->f_e - info->x_a - 1 > 0)
		pa(info);
}
