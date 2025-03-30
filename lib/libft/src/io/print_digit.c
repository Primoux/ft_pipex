/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:36:17 by enchevri          #+#    #+#             */
/*   Updated: 2025/02/03 17:10:27 by enchevri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	print_digit(long n, int base, char c)
{
	int		count;
	char	*symbols;

	count = 0;
	if (c == 'd' || c == 'x' || c == 'u' || c == 'i')
		symbols = "0123456789abcdef";
	if (c == 'X')
		symbols = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_digit(-n, base, c) + 1);
	}
	else if (n < base)
		return (ft_putchar_fd(symbols[n], 1));
	else
	{
		count = print_digit(n / base, base, c);
		return (count + print_digit(n % base, base, c));
	}
}
