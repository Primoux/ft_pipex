/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:56:24 by marvin            #+#    #+#             */
/*   Updated: 2024/11/17 14:05:41 by enchevri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	s_len;
	size_t	copy_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_calloc(1, sizeof(char)));
	copy_len = s_len - start;
	if (copy_len > len)
		copy_len = len;
	tab = ft_calloc(copy_len + 1, sizeof(char));
	if (!tab)
		return (NULL);
	ft_memcpy(tab, s + start, copy_len);
	tab[copy_len] = '\0';
	return (tab);
}
