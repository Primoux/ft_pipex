/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:18:42 by enchevri          #+#    #+#             */
/*   Updated: 2025/02/03 12:22:48 by enchevri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>

int	ft_putnbr_fd(int n, int fd)
{
	char	c;
	int		count;

	count = 0;
	if (n == INT_MIN)
	{
		count += write(fd, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		count += write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		count += ft_putnbr_fd(n / 10, fd);
	}
	c = (n % 10) + '0';
	count += write(fd, &c, 1);
	return (count);
}
