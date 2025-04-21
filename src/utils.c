/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:38:16 by enchevri          #+#    #+#             */
/*   Updated: 2025/04/21 22:32:11 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_occured(t_fd *fd, t_data *data, char *error_msg)
{
	if (error_msg != NULL)
		perror(error_msg);
	free_all(data);
	close_all(fd);
	exit(1);
}

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
	i = 0;
	while (i < data->count_path)
		free(data->split_path[i++]);
	if (data->split_path)
		free(data->split_path);
	if (data->pid_children)
		free(data->pid_children);
}

void	close_all(t_fd *fd)
{
	if (fd->fd1[0] != -1)
		close(fd->fd1[0]);
	if (fd->fd1[1] != -1)
		close(fd->fd1[1]);
	if (fd->fd2[0] != -1)
		close(fd->fd2[0]);
	if (fd->fd2[1] != -1)
		close(fd->fd2[1]);
}
