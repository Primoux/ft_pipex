/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enchevri <enchevri@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 17:26:05 by enchevri          #+#    #+#             */
/*   Updated: 2025/04/18 15:45:18 by enchevri         ###   ########lyon.fr   */
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
		middle_cmd(fd);
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

int	ft_pipex(t_data *data)
{
	t_fd	fd;
	int		i;
	int		exit_code;

	i = -1;
	if (pipe(fd.fd1) == -1)
		return (1);
	data->pid_children = malloc((data->cmd_count + 1) * sizeof(pid_t));
	while (data->args[++i])
	{
		if (i < data->cmd_count - 1 && pipe(fd.fd2) == -1)
			return (1);
		data->pid_children[i] = fork();
		if (data->pid_children[i] == -1)
			return (1);
		if (data->pid_children[i] == 0)
		{
			prepare_pipe(data, &fd, i);
			exec_cmd(data, i);
			exit(1);
		}
		swap_pipes(&fd, i, data);
	}
	exit_code = wait_childs(data);
	return (exit_code);
}
