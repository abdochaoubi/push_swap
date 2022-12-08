/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechaoub <aechaoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:59:35 by aechaoub          #+#    #+#             */
/*   Updated: 2022/12/04 15:08:59 by aechaoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	sort_3el(t_arays *info)
{
	int	sz;
	int	*tab ;

	sz = 2;
	tab = info->tab_a;
	if (tab[sz - 0] > tab[sz - 1]
		&& tab[sz - 1] < tab[sz - 2] && tab[sz - 0] < tab[sz - 2])
		sa(info);
	else if (tab[sz - 0] > tab[sz - 1] && tab[sz - 1] > tab[sz - 2])
	{
		sa(info);
		rra(tab, sz + 1, sz);
	}
	else if (tab[sz - 0] > tab[sz - 1]
		&& tab[sz - 1] < tab[sz - 2] && tab[sz - 0] > tab[sz - 2])
		ra(tab, sz + 1, sz);
	else if (tab[sz - 0] < tab[sz - 1]
		&& tab[sz - 1] > tab[sz - 2] && tab[sz - 0] < tab[sz - 2])
	{
		sa(info);
		ra(tab, sz + 1, sz);
	}
	else if (tab[sz - 0] < tab[sz - 1]
		&& tab[sz - 1] > tab[sz - 2] && tab[sz - 0] > tab[sz - 2])
		rra(tab, sz + 1, sz);
}

void	sort_5el(t_arays *info)
{
	if (findmin(info->tab_a, info->x_a + 1) < 2)
	{
		while (findmin(info->tab_a, info->x_a + 1) != 4)
			rra(info->tab_a, info->f_e, info->x_a);
	}
	else
	{
		while (findmin(info->tab_a, info->x_a + 1) != 4)
			ra(info->tab_a, info->f_e, info->x_a);
	}
	pb(info);
	if (findmin(info->tab_a, info->x_a + 1) < 2)
	{
		while (findmin(info->tab_a, info->x_a + 1) != 3)
			rra(info->tab_a, info->f_e, info->x_a);
	}
	else
	{
		while (findmin(info->tab_a, info->x_a + 1) != 3)
			ra(info->tab_a, info->f_e, info->x_a);
	}
	pb(info);
	sort_3el(info);
	pa(info);
	pa(info);
}
