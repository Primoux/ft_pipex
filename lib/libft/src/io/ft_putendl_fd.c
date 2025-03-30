/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:15:07 by enchevri          #+#    #+#             */
/*   Updated: 2025/02/03 12:22:07 by enchevri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

int	ft_putendl_fd(char *s, int fd)
{
	int	count1;
	int	count2;

	if (!s)
	{
		return (write(fd, "(null)", 6));
	}
	count2 = write(fd, s, ft_strlen(s));
	if (count2 == -1)
		return (-1);
	count1 = write(fd, "\n", 1);
	if (count1 == -1)
		return (-1);
	return (count1 + count2);
}
