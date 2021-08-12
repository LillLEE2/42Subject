/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junholee <junholee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 14:38:23 by junholee          #+#    #+#             */
/*   Updated: 2021/08/12 16:42:38 by junholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*base_set(char types)
{
	if (types == 'd' || types == 'i' || types == 'u')
		return ("0123456789");
	else if (types == 'p' || types == 'x')
		return ("0123456789abcdef");
	else if (types == 'X')
		return ("0123456789ABCDEF");
	return (NULL);
}

char	*type_px(char *str, char *base, unsigned long n, int size)
{
	while (size > 0)
	{
		str[size - 1] = base[n % 16];
		size--;
		n /= 16;
	}
	return (str);
}

int	base_size(unsigned long n, char type)
{
	int	size;

	size = 0;
	while (n >= ft_strlen(base_set(type)))
	{
		n /= ft_strlen(base_set(type));
		size++;
	}
	return (size);
}

int	print_p(unsigned long n)
{
	char	*str;
	int		size;

	if (n == 0)
	{
		write(1, "(nil)", 6);
		return (5);
	}
	size = base_size(n, 'p');
	size += 1;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (-1);
	str[size] = '\0';
	str = type_px(str, base_set('p'), n, size);
	size = write(1, "0x", 2) + write(1, str, ft_strlen(str));
	free(str);
	return (size);
}

int	print_u(unsigned int n)
{
	char	*str;
	int		size;

	str = ft_itoa_base(n, 'u');
	size = write(1, str, ft_strlen(str));
	free(str);
	return (size);
}
