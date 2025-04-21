/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 16:30:21 by enchevri          #+#    #+#             */
/*   Updated: 2025/04/21 22:31:57 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	init_var(t_data *data, int argc, char **argv, t_fd *fd)
{
	data->ac = argc;
	data->av = argv;
	data->split_path = NULL;
	data->pid_children = NULL;
	data->cmd_count = 0;
	data->count_path = 0;
	fd->fd1[0] = -1;
	fd->fd1[1] = -1;
	fd->fd2[0] = -1;
	fd->fd2[1] = -1;
}

int	init_data(t_data *data, int argc, char **argv, t_fd *fd)
{
	int	i;

	i = 0;
	init_var(data, argc, argv, fd);
	if (get_arg(data, argv) == 1)
		return (1);
	data->path = get_path(data->env);
	data->split_path = ft_split(data->path, ':');
	if (data->split_path == NULL)
		return (1);
	while (data->split_path[i])
		i++;
	data->count_path = i;
	i = 0;
	while (i < data->count_path)
	{
		data->split_path[i] = str_free_to_join(data->split_path[i], "/");
		if (data->split_path[i] == NULL)
			return (1);
		i++;
	}
	count_args(data);
	return (0);
}
