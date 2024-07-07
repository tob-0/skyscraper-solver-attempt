/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:49:01 by tblochet          #+#    #+#             */
/*   Updated: 2024/07/07 17:23:35 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRID_H
# define GRID_H
# include <stdlib.h>

typedef struct s_case
{
	int	cur_val;
	int	*prob_val;
	int	is_certain;
}	t_case;

typedef struct s_line
{
	int				clue_l;
	int				clue_r;
	int				n_max;
	t_case			*content;
	struct s_line	*next;
}	t_line;

typedef struct grid
{
	t_line	*first_v;
	t_line	*first_h;
}	t_grid;

t_line	*ft_generate_vertical(int *povs, int arr_sz);
void	ft_fill_suites(t_line *first_line);
void	ft_fill_n_max(t_line *first_line);
void	ft_set_possible_values(t_line *line);
void	ft_fill_from_possible_values(t_line *first_line);

#endif