/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:46:05 by enchevri          #+#    #+#             */
/*   Updated: 2024/11/21 16:07:42 by enchevri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t length)
{
	size_t	i;

	i = 0;
	if (length == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && i < length - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
