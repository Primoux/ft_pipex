/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:10:32 by enchevri          #+#    #+#             */
/*   Updated: 2025/01/22 15:03:35 by enchevri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		while (size-- > 0)
			((unsigned char *)dest)[size] = ((unsigned char *)src)[size];
	}
	else
		ft_memcpy(dest, src, size);
	return (dest);
}
