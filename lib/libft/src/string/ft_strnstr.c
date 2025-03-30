/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:31:29 by enchevri          #+#    #+#             */
/*   Updated: 2025/02/04 21:13:06 by enchevri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	y;
	size_t	save;

	i = 0;
	save = 0;
	if (little[0] == '\0')
		return ((char *)&big[0]);
	while (big[i] != '\0' && i < len)
	{
		y = 0;
		save = i;
		while (big[save] == little[y] && save < len)
		{
			save++;
			y++;
			if (little[y] == '\0')
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
