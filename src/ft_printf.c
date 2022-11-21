/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:42:40 by dbiguene          #+#    #+#             */
/*   Updated: 2022/11/21 18:31:44 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../include/ft_utils.h"
#include "../include/ft_printers.h"

int	increment_i(int *i, char *str)
{
	if (str[*i])
		*i += 1;
	return (*i);
}

int	check_write(int count, int *x)
{
	*x = count;
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		x;
	int		total;
	va_list	args;

	va_start(args, str);
	total = 0;
	while (*str)
	{
		i = 0;
		while (str[i] && str[i] != '%')
			i++;
		if (total > total + ft_print_str_len((char *)str, i))
			return (-1);
		total += i;
		if (str[i] && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			if (check_write(ft_printer(str[++i], args), &x) == -1)
				return (-1);
			total += x;
		}
		str += increment_i(&i, (char *)str);
	}
	va_end(args);
	return (total);
}
