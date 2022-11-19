/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbiguene <dbiguene@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:37:45 by dbiguene          #+#    #+#             */
/*   Updated: 2022/11/19 15:40:34 by dbiguene         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_utils.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*str;

	len = ft_strlen(s1);
	str = malloc((len + 1) * sizeof(*s1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = 0;
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*t;

	if (size && count != (count * size) / size)
		return (NULL);
	t = malloc(count * size);
	if (!t)
		return (NULL);
	ft_bzero(t, count * size);
	return ((void *)t);
}

static void	init_itoa(int *len, int *sign, int *factor, int *n)
{
	*factor = 1;
	*sign = 0;
	if (*n < 0)
	{
		*n *= -1;
		*sign = 1;
	}
	*len = *sign + 1;
	while (*factor <= *n / 10)
	{
		*factor *= 10;
		*len += 1;
	}
}

char	*ft_itoa(int n)
{
	int		factor;
	int		i;
	int		len;
	int		sign;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	init_itoa(&len, &sign, &factor, &n);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = -1;
	if (sign)
		str[++i] = '-';
	while (++i < len)
	{
		str[i] = (n / factor) + 48;
		n %= factor;
		factor /= 10;
	}
	return (str);
}
