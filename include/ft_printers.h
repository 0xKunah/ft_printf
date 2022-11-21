/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:21:04 by dbiguene          #+#    #+#             */
/*   Updated: 2022/11/21 18:01:30 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTERS_H
# define FT_PRINTERS_H

# include <stdarg.h>
# include <stdlib.h>

int	ft_printer(char type, va_list args);
int	ft_print_char(char c);
int	ft_print_str(char *s);
int	ft_print_nbr(int n);
int	ft_print_unsigned(unsigned int n);
int	ft_print_hex(unsigned int n, int is_upper);
int	ft_print_pointer(size_t n);
int	ft_print_str_len(char *s, int len);

#endif
