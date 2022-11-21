/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:42:40 by dbiguene          #+#    #+#             */
/*   Updated: 2022/11/21 16:08:42 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "../include/ft_utils.h"
#include "../include/ft_printers.h"

int	ft_printf(const char *str, ...)
{
	int		i;
	int		total;
	char	*tmp;
	va_list	args;

	va_start(args, str);
	total = 0;
	while (*str)
	{
		i = 0;
		while (str[i] && str[i] != '%')
			i++;
		tmp = ft_substr(str, 0, i);
		total += ft_print_str(tmp);
		free(tmp);
		if (str[i] && ft_strchr("cspdiuxX%", str[i + 1]))
			total += ft_printer(str[++i], args);
		if (str[i])
			i++;
		str += i;
	}
	return (total);
}
