/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_planarrays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechaoub <aechaoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 13:59:59 by aechaoub          #+#    #+#             */
/*   Updated: 2022/12/07 19:00:52 by aechaoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	checkletter(char *f)
{
	int	i;

	i = 0;
	if (f[0] == '-' && f[1])
		i++;
	while (f[i])
	{
		if (!(f[i] <= '9' && f[i] >= '0'))
			return (0);
		i++;
	}
	return (1);
}

int	checkerror(int *tab, int *sz,int anyfunct)
{
	int	i;
	int	check;
	int	j;

	i = 0;
	check = 1;
	if(anyfunct == 2)
		check = 0;
	while (i < *sz)
	{
		j = i + 1;
		while (j < *sz)
		{
			if (tab[i] == tab[j])
				return (0);
			if (tab[i] < tab[j])
				check = 0;
			j++;
		}
		i++;
	}
	if (check == 1)
		*sz = -1;
	return (1);
}

int	planarrays_1( char **av, t_arays *info)
{
	char	**l;
	int		i;

	i = 0;
	l = ft_split(av[1], ' ');
	while (l[i])
		i++;
	info->f_e = i;
	info->x_a = i - 1;
	info->tab_a = malloc(sizeof(int) * (info->f_e));
	info->tab_b = malloc(sizeof(int) * (info->f_e));
	i = info->f_e - 1;
	while (i >= 0)
	{
		info->tab_a[i] = ft_atoi(l[info->f_e - i - 1], &info->f_e);
		if (info->f_e == -1 || !checkletter(l[info->f_e - i - 1]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		free(l[info->f_e - i - 1]);
		info->tab_b[i--] = 0;
	}
	free(l);
	return (1);
}

int	planarrays_2(int ac, char **av, t_arays *info)
{
	int		i;

	i = 0;
	info->f_e = ac - 1;
	info->x_a = ac - 2;
	info->tab_a = malloc(sizeof(int) * (info->f_e));
	info->tab_b = malloc(sizeof(int) * (info->f_e));
	i = ac - 2;
	while (i >= 0)
	{
		info->tab_a[i] = ft_atoi(av[info->f_e - i], &info->f_e);
		if (info->f_e == -1 || !checkletter(av[info->f_e - i]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		info->tab_b[i] = 0;
		i--;
	}
	return (1);
}

int	planarrays(int ac, char **av, t_arays *info,int anyfunc)
{
	int		i;

	i = 0;
	if (ac == 2)
	{
		if (!planarrays_1(av, info))
			return (0);
	}
	else
	{
		if (!planarrays_2(ac, av, info))
			return (0);
	}
	if (!checkerror(info->tab_a, &info->f_e,anyfunc))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (info->f_e < 2)
		return (0);
	return (1);
}
