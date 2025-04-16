/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:38:16 by enchevri          #+#    #+#             */
/*   Updated: 2025/04/15 23:23:17 by enchevri         ###   ########lyon.fr   */
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
	if (data->pid_children)
		free(data->pid_children);
}


void	close_all(t_fd *fd)
{
	close(fd->fd1[0]);
	close(fd->fd1[1]);
	close(fd->fd2[0]);
	close(fd->fd2[1]);
}
