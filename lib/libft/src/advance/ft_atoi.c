/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:25:22 by enchevri          #+#    #+#             */
/*   Updated: 2025/03/28 17:00:47 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi(const char *str, int *error)
{
	int		sign;
	long	nb;

	*error = 0;
	sign = 1;
	nb = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign *= -1;
	}
	while ((*str >= '0' && *str <= '9'))
	{
		nb = nb * 10 + (*str++ - 48);
		if ((nb > INT_MAX) && sign == 1)
			*error = 1;
		else if (nb > INT_MAX && sign == -1)
			*error = 1;
	}
	return (sign * (int)nb);
}
