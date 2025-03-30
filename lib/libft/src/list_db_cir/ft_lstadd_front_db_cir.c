/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:06:59 by enchevri          #+#    #+#             */
/*   Updated: 2025/03/10 19:30:21 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front_db_cir(t_list_db_cir **lst, t_list_db_cir *new)
{
	if (*lst == NULL)
	{
		*lst = new;
		new->prev = new;
		new->next = new;
		return ;
	}
	else
	{
		new->next = *lst;
		new->prev = (*lst)->prev;
		(*lst)->prev = new;
		new->prev->next = new;
		*lst = new;
	}
}
