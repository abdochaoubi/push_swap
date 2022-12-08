/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechaoub <aechaoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:24:45 by aechaoub          #+#    #+#             */
/*   Updated: 2022/12/04 15:05:49 by aechaoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	rev_rotate_2el(int *tab, int size, int indexa)
{
	int	o;
	int	y;
	int	i;

	if (size < 1)
		return ;
	o = indexa;
	y = tab[0];
	i = 0;
	while (i < o)
	{
		tab[i] = tab[i + 1];
		i++;
	}
	tab[i] = y;
}

void	rra(int *tab, int size, int indexa)
{
	rev_rotate_2el(tab, size, indexa);
	write(1, "rra\n", 4);
}

void	rrb(int *tab, int size, int indexa)
{
	rev_rotate_2el(tab, size, size - indexa - 2);
	write(1, "rrb\n", 4);
}

void	rrr(int *tab, int *tab2, int size, int indexa)
{
	rev_rotate_2el(tab, size, indexa);
	rev_rotate_2el(tab2, size, size - indexa - 2);
	write(1, "rrr\n", 4);
}
