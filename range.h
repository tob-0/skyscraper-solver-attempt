/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   range.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 16:22:18 by tblochet          #+#    #+#             */
/*   Updated: 2024/07/07 17:00:54 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANGE_H
# define RANGE_H

typedef struct s_range
{
	int	sz;
	int	*arr;
}	t_range;

int		ft_range_pop(t_range *range, int i);
t_range	ft_range_inc(int start, int end);

#endif