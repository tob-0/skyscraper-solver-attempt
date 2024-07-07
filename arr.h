/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:53:11 by tblochet          #+#    #+#             */
/*   Updated: 2024/07/07 18:17:23 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARR_H
# define ARR_H
# include <stdlib.h>

int		ft_find_first(int *arr, int sz, int value);

int		ft_pop(int *arr, int sz, int i);

int		ft_pop_val(int *arr, int sz, int val);

int		*ft_copy(int *arr, int sz);

int		*ft_copy_in_place(int *arr, int sz, int *dest);

#endif