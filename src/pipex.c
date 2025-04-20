/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:26:05 by enchevri          #+#    #+#             */
/*   Updated: 2025/04/20 17:05:49 by enchevri         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exec_cmd(t_data *data, int i)
{
	char	*cmd_path;

	if (data->args[i][0] == NULL)
	{
		free_all(data);
		exit(127);
	}
	cmd_path = find_command_path(data->args[i][0], data->split_path, data);
	if (!cmd_path)
	{
		free_all(data);
		exit(127);
	}
	execve(cmd_path, data->args[i], data->env);
	free(cmd_path);
	free_all(data);
	exit(126);
}

static void	prepare_pipe(t_data *data, t_fd *fd, int i)
{
	if (i == 0)
		first_cmd(fd, data->infile, data);
	else if (i == data->cmd_count - 1)
		last_cmd(fd, data->outfile, data);
	else
		middle_cmd(fd, data);
}

static void	swap_pipes(t_fd *fd, int i, t_data *data)
{
	close(fd->fd1[0]);
	close(fd->fd1[1]);
	if (i < data->cmd_count - 1)
	{
		fd->fd1[0] = fd->fd2[0];
		fd->fd1[1] = fd->fd2[1];
	}
}

static int	routine_fork(int i, t_fd *fd, t_data *data)
{
	if (data->cmd_count - 1 && pipe(fd->fd2) == -1)
		return (1);
	data->pid_children[i] = fork();
	if (data->pid_children[i] == -1)
		return (1);
	if (data->pid_children[i] == 0)
	{
		prepare_pipe(data, fd, i);
		exec_cmd(data, i);
	}
	swap_pipes(fd, i, data);
	return (0);
}

int	ft_pipex(t_data *data, t_fd *fd)
{
	int	i;

	i = -1;
	if (pipe(fd->fd1) == -1)
		return (1);
	data->pid_children = ft_calloc((data->cmd_count + 1), sizeof(pid_t));
	if (!data->pid_children)
		return (1);
	while (data->args[++i])
	{
		if (routine_fork(i, fd, data) == 1)
			return (1);
	}
	return (wait_childs(data));
}
