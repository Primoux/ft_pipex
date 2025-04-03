/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_free_to_join.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:14:55 by enchevri          #+#    #+#             */
/*   Updated: 2025/04/02 17:51:49 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_free_to_join(char *s1, char *s2)
{
	char	*temp;

	temp = ft_strjoin(s1, s2);
	if (s1)
		free(s1);
	return (temp);
}
