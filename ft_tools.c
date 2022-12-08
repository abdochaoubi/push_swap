/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechaoub <aechaoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:57:48 by aechaoub          #+#    #+#             */
/*   Updated: 2022/12/04 13:57:57 by aechaoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	findsmaller(int *tab, int sz, int nothis)
{
	int	i;
	int	k;

	i = 0;
	k = findmin(tab, sz);
	if (i == nothis)
	{
		i = 1;
	}
	while (i < sz)
	{
		if (tab[i] > tab[k] && tab[i] < nothis)
			k = i;
		i++;
	}
	return (k);
}

int	steptobefst( int needtofst, int *upordown, int top)
{
	if (needtofst + 1 > top - needtofst)
	{
		*upordown = 5;
		return (top - needtofst);
	}
	else
	{
		*upordown = 2;
		return (needtofst + 1);
	}
}

int	manysteps(int el, t_arays *info, int *upordown)
{
	int	top;
	int	max;
	int	twondmin_place;

	max = findmax_b(info);
	top = info->f_e - info->x_a - 2;
	if (info->tab_b[0] == 0)
		return (0);
	if (el > info->tab_b[max])
	{
		return (steptobefst(max, upordown, top));
	}
	else if (el < info->tab_b[findmin(info->tab_b, 1 + top)])
	{
		return (steptobefst(max, upordown, top));
	}
	else
	{
		twondmin_place = findsmaller(info->tab_b, 1 + top, el);
		return (steptobefst(twondmin_place, upordown, top));
	}
}

int	choosebest(int best, int stepss, int upordown, int check)
{
	int	luck;

	if (best > stepss && upordown == check)
		luck = best;
	else if (upordown == check)
		luck = stepss;
	else
		luck = best + stepss;
	return (luck);
}
