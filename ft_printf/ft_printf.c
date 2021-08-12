/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junholee <junholee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:47:21 by junholee          #+#    #+#             */
/*   Updated: 2021/08/12 17:36:00 by junholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(va_list value, char types)
{
	if (types == 'c')
		return (print_c(va_arg(value, int)));
	else if (types == 's')
		return (print_s(va_arg(value, char *)));
	else if (types == 'd' || types == 'i')
		return (print_i(va_arg(value, int)));
	else if (types == '%')
		return (ft_putchr('%'));
	else if (types == 'x')
		return (print_x(va_arg(value, unsigned int)));
	else if (types == 'p')
		return (print_p(va_arg(value, unsigned long)));
	else if (types == 'X')
		return (print_X(va_arg(value, unsigned int)));
	else if (types == 'u')
		return (print_u(va_arg(value, unsigned int)));
	return (-1);
}

int	find_format(va_list value, char *format)
{
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	while (*format)
	{
		while (*format != '%' && *format)
			ret += ft_putchr(*format++);
		if (*format == '%')
		{
			format++;
			i += check_type(value, *format);
			if (i == -1)
				return (-1);
			format++;
		}
	}
	return (ret + i);
}

int	ft_printf(const char *format, ...)
{
	int		ret;
	va_list	value;

	va_start(value, format);
	ret = find_format(value, (char *)format);
	va_end(value);
	return (ret);
}
