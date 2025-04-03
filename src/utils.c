/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:38:16 by enchevri          #+#    #+#             */
/*   Updated: 2025/04/03 18:06:09 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(t_data *data)
{
	int	i;
	int	j;

	if (data->args)
	{
		i = 0;
		while (data->args[i])
		{
			j = 0;
			while (data->args[i][j])
				free(data->args[i][j++]);
			free(data->args[i++]);
		}
		free(data->args);
	}
	if (data->split_path)
		free_tab_return_int(data->split_path, 0);
}
