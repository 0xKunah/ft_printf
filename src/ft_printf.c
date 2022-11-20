/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:42:40 by dbiguene          #+#    #+#             */
/*   Updated: 2022/11/20 14:40:10 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
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
	i = -1;
	total = 0;
	while (*str)
	{
		i = 0;
		while (str[++i] && str[i] != '%')
			;
		tmp = ft_substr(str, 0, i);
		ft_putstr_fd(tmp, 1);
		free(tmp);
		if (str[i] && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			if (str[i + 1] == 's')
				ft_print_str(va_arg(args, char *));
			else if (str[i + 1] == 'c')
				ft_print_char(va_arg(args, int));
			else if (str[i + 1] == 'i' || str[i + 1] == 'd')
				ft_print_nbr(va_arg(args, int));
			i += 2;
		}
		str += i;
	}
	return (0);
}

int	main(void)
{
	return (ft_printf("This is a string: %s\nThis is a char: %c\nThis is a int: %i\nThis is a digit: %d\nThis is another digit: %d\n", "string", 'c', 15, 48, 65));
}
