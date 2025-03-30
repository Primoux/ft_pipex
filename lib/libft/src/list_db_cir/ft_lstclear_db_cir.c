/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_db_cir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:18:43 by enchevri          #+#    #+#             */
/*   Updated: 2025/03/05 22:00:16 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear_db_cir(t_list_db_cir **lst)
{
	t_list_db_cir	*temp;

	if (!*lst)
		return ;
	(*lst)->prev->next = NULL;
	(*lst)->prev = NULL;
	while (*lst)
	{
		temp = (*lst)->next;
		free(*lst);
		*lst = temp;
	}
}
