/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_inside.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechaoub <aechaoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:34:15 by aechaoub          #+#    #+#             */
/*   Updated: 2022/12/04 15:11:22 by aechaoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	put_inside_1(t_arays *info, int po)
{
	if (po < info->x_a - po - 1)
		while (po-- >= 0)
			rra(info->tab_a, info->f_e, info->x_a);
	else
	{
		while ((info->tab_a[po] > info->tab_b[0]
				|| info->tab_a[po] < info->tab_b[info->f_e - info->x_a - 2])
			&& po <= info->x_a - 1)
		{
			rr(info->tab_a, info->tab_b, info->f_e, info->x_a);
			po++;
		}
		while (po <= info->x_a - 1)
		{
			ra(info->tab_a, info->f_e, info->x_a);
			po++;
		}
		while (info->tab_a[po] > info->tab_b[0]
			|| info->tab_a[po] < info->tab_b[info->f_e - info->x_a - 2])
			rb(info->tab_b, info->f_e, info->x_a);
	}
	while (info->tab_a[info->x_a] > info->tab_b[0]
		|| info->tab_a[info->x_a] < info->tab_b[info->f_e - info->x_a - 2])
		rb(info->tab_b, info->f_e, info->x_a);
}

void	put_inside_2(t_arays *info, int po)
{
	if (po < info->x_a - po - 1)
	{
		while ((info->tab_a[po] > info->tab_b[0]
				|| info->tab_a[po] < info->tab_b[info->f_e - info->x_a - 2])
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
	while (info->tab_a[info->x_a] > info->tab_b[0]
		|| info->tab_a[info->x_a] < info->tab_b[info->f_e - info->x_a - 2])
		rrb(info->tab_b, info->f_e, info->x_a);
}

void	put_inside(t_arays *info, int po)
{
	int	i;

	i = smallerone(info->tab_b, info->f_e - info->x_a - 2, info->tab_a[po]);
	if (i >= info->f_e - info->x_a - 2 - i)
	{
		put_inside_1(info, po);
	}
	else
	{
		put_inside_2(info, po);
	}
	pb(info);
}
