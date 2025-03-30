/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:14:41 by enchevri          #+#    #+#             */
/*   Updated: 2025/02/03 17:10:33 by enchevri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	print_pointer(void *ptr)
{
	if (!ptr)
		return (write(1, "(nil)", 5));
	else
	{
		return (write(1, "0x", 2) + print_hexa((unsigned long)ptr));
	}
}

int	print_hexa(unsigned long n)
{
	int		count;
	char	*symbols;

	count = 0;
	symbols = "0123456789abcdef";
	if (n < 16)
		return (ft_putchar_fd(symbols[n], 1));
	else
	{
		count = print_hexa(n / 16);
		return (count + print_hexa(n % 16));
	}
}
