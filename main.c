/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechaoub <aechaoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 18:35:08 by aechaoub          #+#    #+#             */
/*   Updated: 2022/12/07 13:08:57 by aechaoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	findmin(int *tab, int sz)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (i < sz)
	{
		if (tab[i] < tab[k])
			k = i;
		i++;
	}
	return (k);
}

int	smallerone(int *tab, int sz, int checker)
{
	int	i;
	int	k;

	i = 0;
	k = findmin(tab, sz);
	while (i < sz)
	{
		if (tab[i] < checker && tab[i] > tab[k])
			k = i;
		i++;
	}
	return (k);
}

int	findmax_b(t_arays *info)
{
	int	sz;
	int	i;
	int	k;

	sz = info->f_e - info->x_a - 1;
	i = 0;
	k = 0;
	while (i < sz)
	{
		if (info->tab_b[i] > info->tab_b[k])
			k = i;
		i++;
	}
	return (k);
}

int	index_best_el(t_arays *info, int i)
{
	int	stepss;
	int	luck;
	int	po;
	int	upordown;
	int	yk;

	i = info->x_a;
	yk = 1000;
	while (i >= 0 && info->f_e != info->x_a - 1)
	{
		stepss = manysteps(info->tab_a[i], info, &upordown);
		if (i > info->x_a - i - 1)
			luck = choosebest(info->x_a - i, stepss, upordown, 5);
		else
			luck = choosebest(i + 1, stepss, upordown, 2);
		if (luck < yk)
		{
			yk = luck;
			po = i;
		}
		i--;
	}
	return (po);
}

int	main(int ac, char **av)
{
	t_arays	info;
	int		i;

	i = 0;
	if (!planarrays(ac, av, &info,1))
		return (0);
	if (info.f_e == 3)
	{
		sort_3el(&info);
		return (0);
	}
	if (info.f_e == 5)
	{
		sort_5el(&info);
		return (0);
	}
	else
		sort_unlimited(&info);
	return (0);
}
