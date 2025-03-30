/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:16:17 by enchevri          #+#    #+#             */
/*   Updated: 2025/01/22 14:55:08 by enchevri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *mem_block, int srch_char, size_t size)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	c;

	str = (unsigned char *)mem_block;
	c = (unsigned char)srch_char;
	i = 0;
	while (i < size)
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (0);
}
