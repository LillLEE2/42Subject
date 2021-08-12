/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junholee <junholee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 14:38:23 by junholee          #+#    #+#             */
/*   Updated: 2021/08/12 16:17:09 by junholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char *str)
{
	size_t	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

int	ft_putchr(char c)
{
	write(1, &c, 1);
	return (1);
}

char	*ft_itoa_base(unsigned int n, char type)
{
	char	*str;
	int		size;
	char	*types;

	size = base_size((unsigned int)n, type);
	types = base_set(type);
	size += 1;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = types[n % ft_strlen(types)];
		size--;
		n /= ft_strlen(types);
	}
	return (str);
}
