/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechaoub <aechaoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:50:16 by aechaoub          #+#    #+#             */
/*   Updated: 2022/12/06 15:22:34 by aechaoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include <string.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

# include <stdlib.h>

typedef struct s_data
{
	int	f_e;
	int	x_a;
	int	*tab_a;
	int	*tab_b;

}	t_arays;

void	sort_3el(t_arays *info);
void	sort_5el(t_arays *info);

int		ft_atoi(const char *str, int *ckeck);
void	sb(t_arays *info);
void	sa(t_arays *info);
void	ss(t_arays *info);
void	pa(t_arays *info);
void	pb(t_arays *info);
void	ra(int *tab, int size, int indexa);
void	rb(int *tab, int size, int indexa);
void	rr(int *tab, int *tab2, int size, int indexa);
void	rra(int *tab, int size, int indexa);
void	rrb(int *tab, int size, int indexa);
void	rrr(int *tab, int *tab2, int size, int indexa);
void	rotate_2el(int *tab, int size, int indexa);
char	**ft_split(char const *s, char c);

void	sort_unlimited(t_arays *info);
void	put_bigger(t_arays *info, int po);
void	put_smaller(t_arays *info, int po);
void	put_inside(t_arays *info, int po);
int		planarrays(int ac, char **av, t_arays *info,int anyfunct);
int		findsmaller(int *tab, int sz, int nothis);
int		steptobefst(int needtofst, int *upordown, int top);
int		manysteps(int el, t_arays *info, int *upordown);
int		choosebest(int best, int stepss, int upordown, int check);
void	printi(int *tab, int *tab_b, int size, int indexa);
int		check(int *tab, int size);
int		findmin(int *tab, int sz);
int		index_best_el(t_arays *info, int i);
void	sort_2el(int *tab);
int		findmax_b(t_arays *info);
int		smallerone(int *tab, int sz, int checker);
#endif
