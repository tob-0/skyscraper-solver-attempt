/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 14:55:45 by tblochet          #+#    #+#             */
/*   Updated: 2024/07/07 14:57:59 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STR_H
# define STR_H
# include <unistd.h>

/// @brief Outputs a character to STDOUT
/// @param c The character to print
void	ft_putchar(char c);
/// @brief Outputs a string to STDOUT
/// @param s The string as a pointer to char
void	ft_putstr(char *s);
/// @brief Outputs a string to STDOUT, ending the line with '\n'
/// @param s The string as a pointer to char
void	ft_putstr_nl(char *s);

#endif