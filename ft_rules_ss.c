/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules_ss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechaoub <aechaoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:28:55 by aechaoub          #+#    #+#             */
/*   Updated: 2022/12/06 15:01:17 by aechaoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	swap_2el(int *tab, int size, int indexa)
{
	int	o;
	int	k;

	if (size < 1 || indexa<1)
		return (0);
	o = indexa;
	k = tab[o];
	tab[o] = tab[o - 1];
	tab[o - 1] = k;
	return (1);
}

void	sa(t_arays *info)
{
	if(swap_2el(info->tab_a, info->f_e, info->x_a))
		write(1, "sa\n", 3);
}

void	sb(t_arays *info)
{
	if(swap_2el(info->tab_b, info->f_e, info->f_e - info->x_a-2))
		write(1, "sb\n", 3);
}

void	ss(t_arays *info)
{
	int i=info->f_e - info->x_a-2;
	if(i>=1 && info->f_e>=1)
	{
		swap_2el(info->tab_a, info->f_e,  info->x_a);
		swap_2el(info->tab_b, info->f_e, i);
		write(1, "ss\n", 3);
	}
}

void	rr(int *tab, int *tab2, int size, int indexa)
{
	rotate_2el(tab, size, indexa);
	rotate_2el(tab2, size, size - indexa - 2);
	write(1, "rr\n", 3);
}
