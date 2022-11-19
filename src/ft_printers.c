/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:44:49 by dbiguene          #+#    #+#             */
/*   Updated: 2022/11/19 15:43:21 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printers.h"
#include "../include/ft_utils.h"
#include <unistd.h>

int	ft_print_char(char c)
{
	return ((int)write(1, &c, 1));
}

int	ft_print_str(char *s)
{
	return ((int)write(1, s, ft_strlen(s)));
}

int	ft_print_nbr(int n)
{
	char		*s;
	ssize_t		len;

	s = ft_itoa(n);
	len = write(1, s, ft_strlen(s));
	free(s);
	return ((int)len);
}
