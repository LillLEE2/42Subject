/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junholee <junholee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 14:24:48 by junholee          #+#    #+#             */
/*   Updated: 2021/08/12 17:35:47 by junholee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		find_format(va_list value, char *format);
int		ft_printf(const char *format, ...);

int		print_c(int n);
int		print_s(char *str);
int		print_i(int n);
int		print_x(unsigned int n);
int		print_X(unsigned int n);

size_t	ft_strlen(char *str);
int		ft_putchr(char c);
char	*ft_itoa_base(unsigned int n, char type);

int		base_size(unsigned long n, char type);
int		print_p(unsigned long n);
int		print_u(unsigned int n);
char	*type_p(char *str, char *base, unsigned long n, int size);
char	*base_set(char types);

#endif