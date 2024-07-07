/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:52:45 by tblochet          #+#    #+#             */
/*   Updated: 2024/07/07 19:03:11 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "grid.h"
#include "arr.h"
#include "range.h"

#include <stdio.h>
t_line *ft_generate_vertical(int *povs, int arr_sz)
{
	int i;
	t_line *first;
	t_line *current;
	int block_sz;

	i = 0;
	block_sz = arr_sz / 4;
	first = malloc(sizeof(t_line));
	current = first;
	while (i < block_sz)
	{
		current->content = malloc(block_sz * sizeof(t_case));
		current->next = malloc(sizeof(t_line));
		current->n_max = block_sz;
		current->clue_l = povs[i];
		current->clue_r = povs[i + block_sz];
		current = current->next;
		i++;
	}

	free(current->next);
	current->next = 0;
	return (first);
}

void ft_fill_suites(t_line *first_line)
{
	t_line *cur;
	int x;
	int idx;

	cur = first_line;
	while (cur->next)
	{
		if (cur->clue_l == cur->n_max || cur->clue_r == cur->n_max)
		{
			x = 0;
			while (++x <= cur->n_max)
			{
				if (cur->clue_l == cur->n_max)
					idx = x - 1;
				else
					idx = cur->n_max - x - 1;
				cur->content[idx].cur_val = x;
				cur->content[idx].is_certain = 1;
				cur->content[idx].prob_val = 0;
			}
		}
		cur = cur->next;
	}
}

void ft_fill_n_max(t_line *first_line)
{
	t_line *cur;
	int idx;

	cur = first_line;
	while (cur->next)
	{
		if (cur->clue_l == cur->n_max - 1 || cur->clue_r == cur->n_max - 1)
		{
			if (cur->clue_l == cur->n_max - 1)
				idx = cur->n_max - 2;
			else
				idx = cur->n_max - (cur->n_max - 1);
			cur->content[idx].cur_val = cur->n_max;
			cur->content[idx].is_certain = 1;
			cur->content[idx].prob_val = 0;
		}
		cur = cur->next;
	}
}

void ft_set_possible_values(t_line *first_line)
{
	t_range values;
	t_line *cur;
	int i;
	int x;

	cur = first_line;
	while (cur->next)
	{
		values = ft_range_inc(1, cur->n_max);
		i = 0;
		while (i < cur->n_max)
		{
			x = cur->content[i].cur_val;
			if (ft_find_first(values.arr, values.sz, x) != -1)
				ft_range_pop(&values, ft_find_first(values.arr, values.sz, x));
			i++;
		}
		i = -1;
		while (++i < cur->n_max)
		{
			if (!(cur->content[i].is_certain))
				cur->content[i].prob_val = ft_copy(values.arr, values.sz);
		}
		cur = cur->next;
	}
}

void ft_fill_from_possible_values(t_line *first_line)
{
	t_line *l_cur;
	t_case c_cur;
	int i;
	
	l_cur = first_line;
	while (l_cur->next)
	{
		i = 0;
		while (i < l_cur->n_max)
		{
			c_cur = l_cur->content[i];
			if (c_cur.prob_val)
			{
				l_cur->content[i].cur_val = ft_pop(l_cur->content[i].prob_val, l_cur->n_max, 0);
			}
			i++;
		}
		l_cur = l_cur->next;
	}
}