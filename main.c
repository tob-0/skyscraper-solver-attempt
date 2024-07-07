/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:11:31 by tblochet          #+#    #+#             */
/*   Updated: 2024/07/07 17:54:05 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "grid.h"
#include "arguments.h"
#include "str.h"

int main(int argc, char *argv[])
{
	int *povs;
	t_line *first_vertical;

	if (argc != 2 || argv[1] == 0)
	{
		ft_putstr_nl("Error.");
		return (1);
	}
	if (!ft_arg_is_valid(argv[1], 31))
	{
		ft_putstr_nl("Error.");
		return (1);
	}
	povs = ft_parse_input(argv[1], 16);
	first_vertical = ft_generate_vertical(povs, 16);
	ft_fill_suites(first_vertical);
	ft_fill_n_max(first_vertical);
	ft_set_possible_values(first_vertical);
	ft_fill_from_possible_values(first_vertical);
	t_line *cur;
	int x = 0;
	while (x < 4)
	{
		cur = first_vertical;
		while (cur->next)
		{

			printf("%d ", cur->content[x].cur_val);
			cur = cur->next;
		}
		x++;
		printf("\n");
	}


	free(first_vertical);
	free(povs);
	return (0);
}
