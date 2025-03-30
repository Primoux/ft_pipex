/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:10:20 by enchevri          #+#    #+#             */
/*   Updated: 2025/03/10 13:55:02 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putstr_fd(char *s, int fd)
{
	int	count;
	int	write_ret;

	count = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[count])
	{
		write_ret = write(fd, &s[count], 1);
		if (write_ret == -1)
			return (-1);
		count++;
	}
	return (count);
}
