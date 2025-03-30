/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_db_cir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:32:46 by enchevri          #+#    #+#             */
/*   Updated: 2025/03/12 20:27:58 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize_db_cir(t_list_db_cir *lst)
{
	int				i;
	t_list_db_cir	*temp;

	if (!lst)
		return (0);
	temp = lst->next;
	i = 1;
	while (temp != lst)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
