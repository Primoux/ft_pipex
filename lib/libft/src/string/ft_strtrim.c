/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 23:39:10 by marvin            #+#    #+#             */
/*   Updated: 2024/11/21 19:44:34 by enchevri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	c_is_set(char const c, char const *set)
{
	while (*set)
	{
		if (*set++ == c)
			return (1);
	}
	return (0);
}

static int	where_end(char const *s, char const *set)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (i >= 0 && c_is_set(s[i], set))
	{
		i--;
	}
	return (i + 1);
}

static int	where_start(char const *s, char const *set)
{
	int	i;

	i = 0;
	while (s[i] && c_is_set(s[i], set))
	{
		i++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*tab;

	if (!s1 || !set)
		return (NULL);
	start = where_start(s1, set);
	end = where_end(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	tab = ft_substr(s1, start, end - start);
	if (tab == NULL)
		return (NULL);
	return (tab);
}
