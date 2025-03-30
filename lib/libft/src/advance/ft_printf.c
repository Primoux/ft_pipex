/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 22:20:00 by enchevri          #+#    #+#             */
/*   Updated: 2025/03/12 20:13:09 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <unistd.h>

static int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar_fd((char)va_arg(ap, int), 1);
	else if (specifier == 's')
		count += ft_putstr_fd(va_arg(ap, char *), 1);
	else if (specifier == 'p')
		count += print_pointer(va_arg(ap, void *));
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit((va_arg(ap, int)), 10, specifier);
	else if (specifier == 'x' || specifier == 'X')
		count += print_digit((va_arg(ap, unsigned int)), 16, specifier);
	else if (specifier == 'u')
		count += print_digit((va_arg(ap, unsigned int)), 10, specifier);
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	if (!format || format == 0)
		return (-1);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
			count += print_format(*++format, ap);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
