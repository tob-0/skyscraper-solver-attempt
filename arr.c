/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:49:40 by tblochet          #+#    #+#             */
/*   Updated: 2024/07/07 18:57:08 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arr.h"
#include <stdio.h>
int ft_find_first(int *arr, int sz, int value)
{
	int i;

	i = 0;
	while (i < sz)
	{
		if (arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

int ft_pop(int *arr, int sz, int i)
{
	int j;
	int x;
	int offset;
	int *new_arr;

	j = 0;
	offset = 0;
	x = arr[i];
	new_arr = malloc((sz - 1) * sizeof(int));
	while (j < sz - 1)
	{
		if (j != i)
			new_arr[j] = arr[j + offset];
		if (j == i && i == 0)
		{
			offset = 1;
			j = -1;
			i = -1;
		}
		j++;
	}
	j = 0;
	while (j < sz - 1)
	{
		arr[j] = new_arr[j];
		j++;
	}
	arr[j] = 255;

	free(new_arr);
	return (x);
}

int ft_pop_val(int *arr, int sz, int val)
{
	int idx;

	idx = ft_find_first(arr, sz, val);
	return (ft_pop(arr, sz, idx));
}

int *ft_copy(int *arr, int sz)
{
	int i;
	int *cpy;

	i = -1;
	cpy = malloc(sz * sizeof(int));
	while (++i < sz)
	{
		cpy[i] = arr[i];
	}
	return (cpy);
}

int *ft_copy_in_place(int *arr, int sz, int *dest)
{
	int i;

	i = -1;
	while (++i < sz)
	{
		dest[i] = arr[i];
	}
	return (dest);
}