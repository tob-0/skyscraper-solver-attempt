/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:22:43 by tblochet          #+#    #+#             */
/*   Updated: 2024/07/07 18:26:14 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "range.h"
#include "arr.h"

t_range	ft_range_inc(int start, int end)
{
	t_range	range;
	int		i;

	range.sz = end - start + 1;
	range.arr = malloc(range.sz * sizeof(int));
	i = -1;
	while (++i < range.sz)
		range.arr[i] = i + start ;
	return (range);
}

int	ft_range_pop(t_range *range, int i)
{
	int		n;

	n = ft_pop(range->arr, range->sz, i);
	range->sz--;
	return (n);
}