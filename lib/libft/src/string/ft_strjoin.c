/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 21:57:51 by marvin            #+#    #+#             */
/*   Updated: 2025/04/03 18:00:42 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	if (!s1 || !s2)
		return (NULL);
	tab = ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (tab == NULL)
		return (NULL);
	while (s1[i])
	{
		tab[x] = s1[i++];
		x++;
	}
	i = 0;
	while (s2[i])
	{
		tab[x] = s2[i++];
		x++;
	}
	tab[x] = '\0';
	return (tab);
}
