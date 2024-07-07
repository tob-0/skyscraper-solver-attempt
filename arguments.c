/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:43:55 by tblochet          #+#    #+#             */
/*   Updated: 2024/07/07 14:54:17 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "arguments.h"

int	ft_is_num_in_range(char nb, int min, int max)
{
	int	num_nb;

	if (!(nb >= '0' && nb <= '9'))
		return (0);
	num_nb = nb - '0';
	return (num_nb >= min && num_nb <= max);
}

int	ft_arg_is_valid(char *arg, int expected_length)
{
	int	i;

	i = 0;
	if (arg[i] == ' ')
		return (0);
	while (arg[i])
	{
		if (i % 2 == 0 && !ft_is_num_in_range(arg[i], 1, 4))
			return (0);
		if (i % 2 == 1 && arg[i] != ' ')
			return (0);
		i++;
	}
	return (i == expected_length);
}

int	*ft_parse_input(char *arg, int sz)
{
	int	*arr;
	int	i;

	arr = malloc(sz * sizeof(int));
	i = 0;
	while (i < sz * 2)
	{
		arr[i / 2] = arg[i] - '0';
		i += 2;
	}
	return (arr);
}