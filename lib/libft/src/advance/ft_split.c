/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 22:19:58 by marvin            #+#    #+#             */
/*   Updated: 2025/04/04 12:11:47 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sep(char c, char sep)
{
	return (c == sep);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] && check_sep(s[i], c))
			i++;
		if (s[i] && !check_sep(s[i], c))
		{
			words++;
			while (s[i] && !check_sep(s[i], c))
				i++;
		}
	}
	return (words);
}

static size_t	count_letters(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	words;
	size_t	i;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	tab = ft_calloc(words + 1, sizeof(char *));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s && check_sep(*s, c))
			s++;
		tab[i] = ft_calloc(count_letters(s, c) + 1, sizeof(char));
		if (tab[i] == NULL)
			return (free_tab_return_null(tab));
		ft_strlcpy(tab[i], s, count_letters(s, c) + 1);
		s += count_letters(s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
