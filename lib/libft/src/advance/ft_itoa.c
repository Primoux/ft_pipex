/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 13:45:31 by enchevri          #+#    #+#             */
/*   Updated: 2025/03/12 20:18:19 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	numlen(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static int	n_absolut(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	long	num;

	if (n == -2147483648)
		return (str = ft_strdup("-2147483648"));
	if (n == 0)
		return (str = ft_strdup("0"));
	num = n_absolut(n);
	len = numlen(n);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		str[0] = '-';
	while (num > 0)
	{
		if (len > 0)
			str[--len] = num % 10 + 48;
		else
			str[len--] = num % 10 + 48;
		num /= 10;
	}
	return (str);
}
