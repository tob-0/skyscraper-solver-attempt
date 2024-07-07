/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:43:50 by tblochet          #+#    #+#             */
/*   Updated: 2024/07/07 15:03:58 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGUMENTS_H
# define ARGUMENTS_H
# include <stdlib.h>

/// @brief Parse the provided argument and store its content in an int array
/// @param arg String to parse
/// @param sz Size of the int tab
/// @return Pointer to the newly allocated int array
int	*ft_parse_input(char *arg, int sz);
/// @brief Check wether the character representation
/// of a digit is between two ints
/// @param nb Char to check
/// @param min Lower bound (inclusive)
/// @param max Upper bound (inclusive)
/// @return 1 if the number is inside the range, 0 otherwise
int	ft_is_num_in_range(char nb, int min, int max);
/// @brief Check if the given argument is valid and can be parsed
/// @param arg The argument to check
/// @param expected_length the expected length of the argument, to make sure
///	no value is missing
/// @return 1 if the argument is valid, 0 otherwise
int	ft_arg_is_valid(char *arg, int expected_length);

#endif