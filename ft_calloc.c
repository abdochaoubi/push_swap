/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aechaoub <aechaoub@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:41:12 by aechaoub          #+#    #+#             */
/*   Updated: 2022/12/04 14:30:56 by aechaoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;

	if (count >= SIZE_MAX || size >= SIZE_MAX)
		return (0);
	p = malloc(count * size);
	if (!p)
		return (0);
	ft_bzero(p, count * size);
	return ((void *)p);
}
