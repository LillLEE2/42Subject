/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junholee <junholee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 16:47:21 by junholee          #+#    #+#             */
/*   Updated: 2021/06/21 19:21:14 by junholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int sum(int count, ...)
{
	int res = 0;
	va_list ap;
	int i;

	va_start(ap, count);

	for(i = 0; i < count; i++)
		res += va_arg(ap, int);
	va_end(ap);

	return (res);
}

int		ft_printf(const char *format, ...)
{
	
}

int main()
{
	printf("%d\n", sum(10, 1,2,3,4,5,6,7,8,9,10));

	return(0);
}
