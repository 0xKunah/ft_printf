/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 14:17:42 by dbiguene          #+#    #+#             */
/*   Updated: 2022/11/21 15:05:36 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printers.h"
#include "../include/ft_utils.h"
#include <unistd.h>
#include <stdio.h>

static void	ft_putnbr_base(size_t n, int *count, int is_upper)
{
	if (n >= 16)
		ft_putnbr_base(n / 16, count, is_upper);
	if (is_upper)
		*count += ft_print_char("0123456789ABCDEF"[n % 16]);
	else
		*count += ft_print_char("0123456789abcdef"[n % 16]);
}

static void	ft_putnbr_unsigned(unsigned int n, int *count)
{
	if (n >= 10)
		ft_putnbr_unsigned(n / 10, count);
	*count += ft_print_char((n % 10) + 48);
}

int	ft_print_hex(unsigned int n, int is_upper)
{
	int	count;

	count = 0;
	ft_putnbr_base(n, &count, is_upper);
	return (count);
}

int	ft_print_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	ft_putnbr_unsigned(n, &count);
	return (count);
}

int	ft_print_pointer(size_t n)
{
	int	count;

	count = ft_print_str("0x");
	ft_putnbr_base(n, &count, 0);
	return (count);
}
